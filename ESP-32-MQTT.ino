#include <WiFi.h>
#include <PubSubClient.h>
#include <PubSubClientTools.h>

#define WIFI_SSID "........"
#define WIFI_PASS "........"
#define MQTT_SERVER "broker.mqtt-dashboard.com"

WiFiClient espClient;
PubSubClient client(MQTT_SERVER, 1883, espClient);
PubSubClientTools mqtt(client);



int value = 0;
const String s = "";

void setup() {
  Serial.begin(115200);
  Serial.println();

  // Connect to WiFi
  Serial.print(s+"Connecting to WiFi: "+WIFI_SSID+" ");
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("connected");

  // Connect to MQTT
  Serial.print(s+"Connecting to MQTT: "+MQTT_SERVER+" ... ");
  if (client.connect("ESP32Client")) {
    Serial.println("connected");
  
  } 
  else 
  {
    Serial.println(s+"failed, rc="+client.state());
  }
  }

void loop() {
  client.loop();
  }

void publisher() {
   mqtt.publish("test_out", s+"Hello World! - No. "+value);
}

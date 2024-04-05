#include <Arduino.h>
float VERSION = 0.1;

//-------------------------------------------------------------
#define NUM_CHANNELS 5
#define PPM_PIN 10
//-------------------------------------------------------------
#define ANALOG_REFRESH_RATE 150 // Taxa de atualização em miliSegundos (ms)
#define ROLL A0
#define PITCH A1
#define YAW A2
#define THROTTLE A3
#define CHAVE_1 6
//-------------------------------------------------------------

// Define a structure to hold the analog readings
struct canais {  
 int XYZT[3];
 byte DIGITAL;
 unsigned long lastUpdate = 0;
};

// Create an instance of the structure
canais channels;

void setup() {
 Serial.begin(115200);
 Serial.println("OPEN CONTROLLER BOOTING UP...");
 Serial.println("...");
 Serial.print("CURRENT VERSION:");
 Serial.println(VERSION);
 pinMode(CHAVE_1,INPUT_PULLUP);

}

void updateCH(){
 channels.XYZT[0] = analogRead(ROLL);
 channels.XYZT[1] = analogRead(PITCH);
 channels.XYZT[2] = analogRead(YAW);
 channels.XYZT[3] = analogRead(THROTTLE);
 channels.DIGITAL = digitalRead(CHAVE_1);
}



void loop() {
  updateCH();

    Serial.print("CH1: ");
    Serial.print(channels.XYZT[0]);
    Serial.print("\tCH2: ");
    Serial.print(channels.XYZT[1]);
    Serial.print("\tCH3: ");
    Serial.print(channels.XYZT[2]);
    Serial.print("\tCH4: ");
    Serial.print(channels.XYZT[3]);
    Serial.print("\tDIGITAL 1: ");
    Serial.println(channels.DIGITAL);


 
}

#include "BluetoothSerial.h"

BluetoothSerial SerialBT;


void setup() {
  pinMode(12, OUTPUT);
  pinMode(14, OUTPUT);

  Serial.begin(115200);

  SerialBT.begin("ESP32_RAHHHHHHHHHH"); // Bluetooth name
  Serial.println("Bluetooth started. Pair with ESP32_Blinky");
}

void loop() {
  if (SerialBT.available()) {
    char cmd = SerialBT.read();

    if (cmd == '1')

    {
      digitalWrite(12, HIGH);
      digitalWrite(14, LOW);
      SerialBT.println("RIGHT");
      SerialBT.println("12_HIGH 14_LOW");
    }


    else if (cmd == '0')

    {
      digitalWrite(14, HIGH);
      digitalWrite(12, LOW);
      SerialBT.println("LEFT");
      SerialBT.println("14_HIGH 12_LOW");
    }


    else if (cmd == '3')

    {
      digitalWrite(14, HIGH);
      digitalWrite(12, HIGH);
      SerialBT.println("STOP");
      SerialBT.println("12_HIGH 14_HIGH");
    }
  }
}

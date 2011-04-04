#ifndef WEATHER_PROTOCOL_H_
#define WEATHER_PROTOCOL_H_

#include <stdint.h>
#include <radio/radio.h>

#define WEATHER_PROTOCOL_NR 6

typedef enum {
    WEATHER_HELLO,
    WEATHER_CHAT,
    WEATHER_DATA
} packet_types;

typedef struct {
    uint16_t seq_nr;
    uint8_t src;
    uint8_t type;
    uint8_t resevered;
} weather_packet_header_t; 

typedef struct __attribute__ ((packed)) {
    weather_packet_header_t header;
} weather_hello_pkt_t;

typedef struct {
    weather_packet_header_t header;
    uint8_t len;
    char mesg[40];
} weather_chat_pkt_t;

typedef struct {
    weather_packet_header_t header;
    time_t timestamp;
    double temperature;
    double relhum;
    double relhum_temp;
    double energy;
} weather_data_pkt_t;

#endif

/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * main.c - Auto-generated by Anjuta's Makefile project wizard
 * 
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * Shuffle Array
 * @param array
 * @param n
 */
void shuffle(int *array, size_t n) {
    srand((unsigned) time(NULL));
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

/**
 * Get Draw Numbers
 * @param numbers
 * @param draw
 */
void getDraw(int *numbers, int *draw) {
    //arithmetic sequences
    draw[0] = numbers[1];
    draw[1] = numbers[2];
    draw[2] = numbers[3];
    draw[3] = numbers[4];
    draw[4] = numbers[5];
    draw[5] = numbers[6];
    draw[6] = numbers[7];
    draw[7] = numbers[8];
}

/**
 * shuffle deck of cards based on the shuffle counter
 * @param numbers
 * @param n
 * @param shuffleCounter
 */
void doShuffling(int *numbers, size_t n, int shuffleCounter) {

    int x;
    for (x = 0; x < shuffleCounter; x++) {
        shuffle(numbers, n);
    }
}

/**
 * Main Method
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {

    int shuffleCounter;
    int drawCounter;
    int numbersLength;
    int numbers[49];
    int arrDraw[9];
    int arrDrawLength;
    int i, j, x;

    numbersLength = 49;
    arrDrawLength = 9;


    if (argc == 1) {
        shuffleCounter = 3;
        drawCounter = 1;
    } else if (argc == 2) {
        shuffleCounter = atoi(argv[1]);
        drawCounter = 1;
    } else {
        shuffleCounter = atoi(argv[1]);
        drawCounter = atoi(argv[2]);
    }

    j = 1;

    //create array 1 - 49
    for (i = 0; i < numbersLength; i++) {
        numbers[i] = j;
        j++;
    }

    //create draws based on drawCounter
    for (i = 0; i < drawCounter; i++) {
        doShuffling(numbers, numbersLength, shuffleCounter);
        getDraw(numbers, arrDraw);
        for (x = 0; x < 6; x++) {
            printf("%d,", arrDraw[x]);
        }
        printf(";");
    }

    exit(EXIT_SUCCESS);
}

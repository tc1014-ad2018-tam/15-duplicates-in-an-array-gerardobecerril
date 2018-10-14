/*
 * This program lets the user input as many numbers as he wants, then tells him or her how many duplicated numbers
 * were found.
 *
 * Author: Gerardo González Becerril.
 * E-mail: a01411981@itesm.mx
 * Date: October 14th, 2018.
 */

 // Libraries needed.
#include <stdio.h>
#include <stdlib.h>

// Function needed for the 'qsort' function. It compares two numbers.
int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int main() {

    int x; // Variable for taking user input.
    int n; // Variable that stores the amount of numbers the user wants.
    int counter = 0; // Counter that stores the amount of duplicates found from a single number.
    int duplicates = 0; // Counter that stores the amount of numbers with duplicates.
    int repetition; // Variable that checks whether a duplicate was found in a loop.

    // Asks the user how many numbers he or she wants.
    printf("How many numbers would you like?\n");
    scanf("%i", &n);

    int arr[n]; // Array that fits as many numbers as the user wants.

    printf("Give me %i numbers:\n", n);

    // For loop that asks the user for a number as many times as numbers indicated, then adds the value to the position
    // of the number of i in the loop into the array.
    for (int i = 0; i < n; i++) {
        printf("Give me number %i:\n", i + 1);
        scanf("%i", &x);
        arr[i] = x;
    }

    // Function that sorts the values in the loop from smallest to biggest.
    qsort(arr, n, sizeof(int), cmpfunc);

    // For loop that goes from 0 to the indicated amount, with a step that changes depending on how many duplicates
    // were found.
    for (int i = 0; i < n; i += counter+1) {

        counter = 0; // The counter checks the amount of duplicates, so it should be restarted every loop.

        // While loop that compares numbers to the following ones to see how many duplicates there are.
        do {
            // If statement that compares the number in the current position to the next one.
            if (arr[i] == arr[i+counter+1]) {
                counter++; // A new duplicate has been found.
                repetition = 1; // The while should continue.
            } else {
                repetition = 0; // No duplicate was found. The while should end.
            }
        } while (repetition == 1);

        // If at least one duplicate found one, duplicates should increase by one.
        if (counter > 0) {
            duplicates++;
        }

    }

    printf("The amount of duplicated numbers is %i.", duplicates);

    return 0;

}
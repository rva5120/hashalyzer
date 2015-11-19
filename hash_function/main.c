//
//  main.c
//  hash_function
//
//  Created by Raquel Alvarez on 11/18/15.
//  Copyright (c) 2015 R. All rights reserved.
//

#include <stdio.h>
#define HASHMAP_RANGE 8192

int hash_function (int disk, int block) {
    int temp = disk * 10000;
    temp = temp + block;
    return (temp%HASHMAP_RANGE);
}

int main(int argc, const char * argv[]) {
    // Variables
    int hashtable [HASHMAP_RANGE] = { 0 };
    int hash_value = 0;
    int worst_case = -100000;
    //int accesses = 10000;
    
    // Generate hash values for all possible blocks
    for (int disk = 0; disk < 9; disk++) {
        for (int block = 0; block < 4096; block++) {
            hash_value = hash_function(disk, block);
            hashtable[hash_value]++;
            // update worst case time
            if (hashtable[hash_value] > worst_case) {
                worst_case = hashtable[hash_value];
            }
        }
    }
    
    // Print the distribution of the hash values
    // For every hash_value: for every hash_function(d,b) = hash_value, print *
    for (int val = 0; val < HASHMAP_RANGE; val++) {
        printf("%4d |", val);
        for (int star = 0; star < hashtable[val]; star++) {
            printf("*");
        }
        printf("\n");
    }
    
    printf("STATISTICS -> Worst Case  %d\n", worst_case);
    
    return(0);
}

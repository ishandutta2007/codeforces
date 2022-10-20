#include<iostream>
#include<stdio.h>
using namespace std ;

int ans[ 16 ]={ 1 , 0 , 18 , 0 , 1800 , 0 , 670320 , 0 , 734832000 , 0 , 890786230 , 0 , 695720788 , 0 , 150347555 , 0 } ;

int main ( ) {
    int n ;
    scanf ( "%d" , &n ) ;
    printf ( "%d\n" , ans[ n - 1 ] ) ;
    return 0 ;
}
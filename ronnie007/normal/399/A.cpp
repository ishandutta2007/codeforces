#include<iostream>
#include<stdio.h>
using namespace std ;

int main ( ) {
    int n , p , k ;
    scanf ( "%d%d%d" , &n , &p , &k ) ;
    int f , s ;
    f = p - k ;
    if ( f < 1 ) f = 1 ;
    s = p + k ;
    if ( s > n ) s = n ;
    if ( f != 1 ) {
        printf ( "<< " ) ;
    }
    int i ;
    for ( i = f ; i <= s ; i ++ ) {
        if ( i != p ) printf ( "%d " , i ) ;
        else printf ( "(%d) " , p ) ;
    }
    if ( s != n ) printf ( " >>\n" ) ;
    return 0 ;
}
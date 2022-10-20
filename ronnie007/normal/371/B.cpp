#include<iostream>
#include<stdio.h>
using namespace std ;

int gcd ( int x , int y ) {
    if ( y == 0 ) return x ;
    return gcd ( y , x%y ) ;
}

int main ( ) {
    int x , y ;
    scanf ( "%d%d" , &x , &y ) ;
    if ( y > x ) swap ( x , y ) ;
    int p = gcd ( x , y ) ;
    int a = x / p ;
    int b = y / p ;
    int ans = 0 ;
    while ( a % 2 == 0 ) {
        a /= 2 ;
        ans ++ ;
    }
    while ( a % 3 == 0 ) {
        a /= 3 ;
        ans ++ ;
    }

    while ( a % 5 == 0 ) {
        a /= 5 ;
        ans ++ ;
    }

    while ( b % 2 == 0 ) {
        b /= 2 ;
        ans ++ ;
    }
    while ( b % 3 == 0 ) {
        b /= 3 ;
        ans ++ ;
    }

    while ( b % 5 == 0 ) {
        b /= 5 ;
        ans ++ ;
    }
    if ( a != 1 || b != 1 ) printf ( "-1\n" ) ;
    else printf ( "%d\n" , ans ) ;
    return 0 ;
}
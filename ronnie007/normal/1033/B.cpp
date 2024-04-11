#include<iostream>
#include<stdio.h>
using namespace std ;

long long a , b ;

void input ( ) {
    scanf ( "%I64d%I64d" , &a , &b ) ;
}

void solve ( ) {
    if ( b < ( a - 1 ) ) { printf ( "NO\n" ) ; return ; }
    a += b ;
    long long i ;
    for ( i = 2 ; i * i <= a ; i ++ ) {
        if ( ( a % i ) == 0 ) { printf ( "NO\n" ) ; return ; }
    }
    printf ( "YES\n" ) ;
}

int main ( ) {
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t != 0 ) {
        t -- ;
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
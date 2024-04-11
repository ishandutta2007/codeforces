#include<iostream>
#include<stdio.h>
#include<string>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;

int ans[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int lst = -2 * n ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) { ans[ i ] = 5 * n ; }
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( a[ i ] == 0 ) { lst = i ; }
        if ( ans[ i ] > ( i - lst ) ) { ans[ i ] = ( i - lst ) ; }
    }
    lst = 5 * n ;
    for ( i = n ; i >= 1 ; i -- ) {
        if ( a[ i ] == 0 ) { lst = i ; }
        if ( ans[ i ] > ( lst - i ) ) { ans[ i ] = ( lst - i ) ; }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        printf ( "%d" , ans[ i ] ) ;
        if ( i == n ) { printf ( "\n" ) ; }
        else { printf ( " " ) ; }
    }
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
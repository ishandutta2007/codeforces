#include<iostream>
#include<stdio.h>
using namespace std ;

#define MAXN 107

int n , m , k ;
int a[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &k ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int i ;
    int mn = n * 200 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( a[ i ] == 0 ) { continue ; }
        if ( a[ i ] > k ) { continue ; }
        int diff = ( i - m ) ;
        if ( diff < 0 ) { diff = 0 - diff ; }
        if ( mn > diff * 10 ) { mn = ( 10 * diff ) ; }
    }
    printf ( "%d\n" , mn ) ;
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
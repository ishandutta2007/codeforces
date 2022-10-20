#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

#define MAXN 20007

int n ;
int a[ MAXN ] ;
int b[ MAXN ] ;


void input ( ) {
    scanf ( "%d" , &n ) ;
}

void solve ( ) {
    int fl = 0 ;
    int sm = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        b[ i ] = ( a[ i ] / 2 ) ;
        sm += b[ i ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( 2 * b[ i ] != a[ i ] ) {
            if ( sm > 0 && a[ i ] < 0 ) {
                -- b[ i ] , -- sm ;
            }
            if ( sm < 0 && a[ i ] > 0 ) {
                ++ b[ i ] , ++ sm ;
            }
        }
    }
    for ( int i = 1 ;  i <= n ; ++ i ) {
        printf ( "%d\n" , b[ i ] ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
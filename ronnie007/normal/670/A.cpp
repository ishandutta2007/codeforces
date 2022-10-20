#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

int n ;
int br[ 17 ] ;
int mx ;
int mn ;

int f ( int x ) {
    int i ;
    for ( i = 1 ; i <= 7 ; i ++ ) {
        br[ i ] = 0 ;
    }

    for ( i = 1 ; i <= n ; i ++ ) {
        br[ x ] ++ ;
        x ++ ;
        if ( x == 8 ) { x = 1 ; }
    }
    return ( br[ 6 ] + br[ 7 ] ) ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
}

void solve ( ) {
    int i ;
    mn = n + 7 ;
    mx = 0 ;
    for ( i = 1 ; i <= 7 ; i ++ ) {
        int h = f ( i ) ;
        if ( mx < h ) { mx = h ; }
        if ( mn > h ) { mn = h ; }
    }
    printf ( "%d %d\n" , mn , mx ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
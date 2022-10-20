#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

#define MAXN 300007

int n ;
int a[ MAXN ] ;
int gap[ MAXN ] ;

int lst[ MAXN ] ;
int mnval[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 0 ; i <= n ; ++ i ) {
        gap[ i ] = 0 ;
        lst[ i ] = 0 ;
        mnval[ i ] = MAXN ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        gap[ a[ i ] ] = max ( gap[ a[ i ] ] , i - lst[ a[ i ] ] - 1 ) ;
        lst[ a[ i ] ] = i ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        gap[ i ] = max ( gap[ i ] , n + 1 - lst[ i ] - 1 ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        mnval[ gap[ i ] ] = min ( mnval[ gap[ i ] ] , i ) ;
    }
    int ans = mnval[ 0 ] ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( ans == MAXN ) { printf ( "-1 " ) ; }
        else { printf ( "%d " , ans ) ; }
        ans = min ( ans , mnval[ i ] ) ;
    }
    printf ( "\n" ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
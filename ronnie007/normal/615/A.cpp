#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std ;

#define MAXN 107

int n , k ;
int used[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &k , &n ) ;
    int i ;
    int p , x ;
    for ( i = 1 ; i <= k ; i ++ ) {
        scanf ( "%d" , &p ) ;
        while ( p != 0 ) {
            p -- ;
            scanf ( "%d" , &x ) ;
            used[ x ] = 1 ;
        }
    }
}

void solve ( ) {
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( used[ i ] == 0 ) { break ; }
    }
    if ( i == n + 1 ) { printf ( "YES\n" ) ; }
    else { printf ( "NO\n" ) ; }
}


int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
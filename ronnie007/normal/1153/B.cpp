#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std ;

#define MAXN 107

int n , m , h ;
int a[ MAXN ][ MAXN ] ;


int c[ MAXN ] ;
int r[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &h ) ;
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 1 ; j <= m ; j ++ ) {
            a[ i ][ j ] = h ;
        }
    }
    for ( i = 1 ; i <= m ; i ++ ) {
        scanf ( "%d" , &c[ i ] ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &r[ i ] ) ;
    }
}

void solve ( ) {
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 1 ; j <= m ; j ++ ) {
            int foo ;
            scanf ( "%d" , &foo ) ;
            if ( foo == 0 ) { a[ i ][ j ] = 0 ; }
            else {
                a[ i ][ j ] = min ( r[ i ] , c[ j ] ) ;
            }
        }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 1 ; j <= m ; j ++ ) {
            printf ( "%d" , a[ i ][ j ] ) ;
            if ( j == m ) { printf ( "\n" ) ; }
            else { printf ( " " ) ; }
        }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
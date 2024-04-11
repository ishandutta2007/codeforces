#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std ;

#define MOD 1000000007
#define MAXN 1007


#define UNKNOWN 0
#define WHITE 1
#define BLACK 2

int n , m ;
int r[ MAXN ] ;
int c[ MAXN ] ;
int a[ MAXN ][ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &r[ i ] ) ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        scanf ( "%d" , &c[ i ] ) ;
    }
}

void solve ( ) {
    long long ans = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= r[ i ] ; ++ j ) {
            if ( a[ i ][ j ] == WHITE ) { ans = 0 ; }
            a[ i ][ j ] = BLACK ;
        }
        if ( r[ i ] < m ) {
            if ( a[ i ][ r[ i ] + 1 ] == BLACK ) { ans = 0 ; }
            a[ i ][ r[ i ] + 1 ] = WHITE ;
        }
    }

    for ( int j = 1 ; j <= m ; ++ j ) {
        for ( int i = 1 ; i <= c[ j ] ; ++ i ) {
            if ( a[ i ][ j ] == WHITE ) { ans = 0 ; }
            a[ i ][ j ] = BLACK ;
        }
        if ( c[ j ] < n ) {
            if ( a[ c[ j ] + 1 ][ j ] == BLACK ) { ans = 0 ; }
            a[ c[ j ] + 1 ][ j ] = WHITE ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            if ( a[ i ][ j ] == UNKNOWN ) { ans <<= 1 ; }
            while ( ans >= MOD ) { ans -= MOD ; }
        }
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
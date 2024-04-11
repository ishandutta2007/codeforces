#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std ;

#define MAXN 107

int n ;
int a[ MAXN ] ;

map < vector < int > , int > ZX ;

int bitcnt ( int x ) {
    int ret = 0 ;
    while ( x > 0 ) {
        x = ( x & ( x - 1 ) ) ;
        ++ ret ;
    }
    return ret ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    vector < int > v ;
    v.resize ( n ) ;
    vector < int > sr ;
    sr.resize ( n ) ;
    for ( int i = 0 ; i < (1<<15) ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            v[ j - 1 ] = bitcnt ( ( a[ j ] >> 15 ) ^ i ) ;
        }
        ZX[ v ] = i ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        a[ i ] %= (1<<15) ;
    }
    int ans = -1 ;
    for ( int i = 0 ; i < (1<<15) ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            v[ j - 1 ] = bitcnt ( a[ j ] ^ i ) ;
        }
        for ( int cnt = 0 ; cnt <= 30 ; ++ cnt ) {
            for ( int j = 0 ; j < n ; ++ j ) { sr[ j ] = cnt - v[ j ] ; }
            if ( ZX.find ( sr ) != ZX.end ( ) ) { ans = ( ZX[ sr ] << 15 ) + i ; printf ( "%d\n" , ans ) ; return ; }
        }
    }
    printf ( "-1\n" ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
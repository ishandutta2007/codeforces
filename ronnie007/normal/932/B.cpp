#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std ;

#define MAXN 1000007

int q ;

int f[ MAXN ] ;
vector < int > v[ 17 ] ;
int l , r , k ;

int get ( int x ) {
    int ret = 1 ;
    while ( x != 0 ) {
        int u = ( x % 10 ) ;
        x /= 10 ;
        if ( u != 0 ) { ret *= u ; }
    }
    return ret ;
}

int calc ( int sr ) {
    if ( sr < 1 ) { return 0 ; }
    int sz = v[ k ].size ( ) ;
    if ( v[ k ][ sz - 1 ] <= sr ) { return sz ; }
    if ( v[ k ][ 0 ] > sr ) { return 0 ; }
    int lo , hi , mid ;
    lo = 0 ;
    hi = sz - 1 ;
    while ( hi - lo > 3 ) {
        mid = ( lo + hi ) / 2 ;
        if ( v[ k ][ mid ] > sr ) { hi = mid ; }
        else { lo = mid ; }
    }
    while ( v[ k ][ hi ] > sr ) { hi -- ; }
    return ( hi + 1 ) ;
}

void input ( ) {
    scanf ( "%d" , &q ) ;
}

void solve ( ) {
    int i ;
    for ( i = 1 ; i <= 9 ; i ++ ) {
        f[ i ] = i ;
    }
    for ( i = 10 ; i < MAXN ; i ++ ) {
        int ret = get ( i ) ;
        f[ i ] = f[ ret ] ;
    }
    for ( i = 1 ; i < MAXN ; i ++ ) {
        v[ f[ i ] ].push_back ( i ) ;
    }
    while ( q != 0 ) {
        q -- ;
        scanf ( "%d%d%d" , &l , &r , &k ) ;
        printf ( "%d\n" , calc ( r ) - calc ( l - 1 ) ) ;
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
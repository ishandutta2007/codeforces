#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
using namespace std ;

#define MAXN 300007

int n ;
long long a[ MAXN ] ;
long long b[ MAXN ] ;

long long prv_add[ MAXN ] ;

long long sm = 0 ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%I64d%I64d" , &a[ i ] , &b[ i ] ) ;
        prv_add[ i ] = 0 ;
    }
}

void solve ( ) {
    sm = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int nxt = i + 1 ;
        if ( nxt > n ) { nxt = 1 ; }
        if ( a[ nxt ] > b[ i ] ) {
            sm += a[ nxt ] - b[ i ] ;
            prv_add[ nxt ] = a[ nxt ] - b[ i ] ;
        }
    }
    long long ans = -1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int nxt = i + 1 ;
        if ( nxt > n ) { nxt = 1 ; }
        long long aux = sm - prv_add[ i ] + a[ i ] ;
        if ( ans < 0 ) { ans = aux ; }
        if ( ans > aux ) { ans = aux ; }
    }
    printf ( "%I64d\n" , ans ) ;
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
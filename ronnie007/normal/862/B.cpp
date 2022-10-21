#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std ;

#define MAXN 100007

int n ;
vector < int > v[ MAXN ] ;

int br[ 2 ] ;

int f[ MAXN ] ;

void dfs ( int vertex , int prv , int id ) {
    f[ vertex ] = id ;
    br[ id ] ++ ;
    int i ;
    int sz = v[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        dfs ( v[ vertex ][ i ] , vertex , (id^1) ) ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i < n ; i ++ ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    dfs ( 1 , -1 , 0 ) ;
    int i ;
    long long ans = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        ans += br[ ( f[ i ] ^ 1 ) ] - v[ i ].size ( ) ;
    }
    ans /= 2 ;
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
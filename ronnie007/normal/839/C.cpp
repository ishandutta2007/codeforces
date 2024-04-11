#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std ;

#define MAXN 100007

int n ;
vector < int > v[ MAXN ] ;

double dp[ MAXN ] ;

void dfs ( int vertex , int prv ) {
    int i ;
    int sz = v[ vertex ].size ( ) ;
    double sm = 0.0000000000 ;
    int tot = 0 ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        tot ++ ;
        dfs ( v[ vertex ][ i ] , vertex ) ;
        sm += dp[ v[ vertex ][ i ] ] ;
    }
    if ( tot != 0 ) {
        sm /= tot ;
        dp[ vertex ] = ( 1.000000000000 + sm ) ;
    }
    else { dp[ vertex ] = 0.000000000000 ; }
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
    dfs ( 1 , -1 ) ;
    printf ( "%.12lf" , dp[ 1 ] ) ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
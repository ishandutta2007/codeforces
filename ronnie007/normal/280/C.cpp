#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
using namespace std ;

#define MAXN 100007

int n ;
vector < int > v[ MAXN ] ;

int dist[ MAXN ] ;

double ans = 0 ;

void dfs ( int vertex , int prv ) {
    int i ;
    int sz = v[ vertex ].size ( ) ;
    ans += ( 1.0000 / ( dist[ vertex ] + 1.0000 ) ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        dist[ v[ vertex ][ i ] ] = dist[ vertex ] + 1 ;
        dfs ( v[ vertex ][ i ] , vertex ) ;
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
    dfs ( 1 , -1 ) ;
    printf ( "%.12lf\n" , ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
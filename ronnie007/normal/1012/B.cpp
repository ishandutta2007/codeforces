#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std ;

#define MAXN 200007

int n , m , q ;
vector < int > v[ 2 * MAXN ] ;

bool used[ 2 * MAXN ] ;

void dfs ( int vertex ) {
    used[ vertex ] = true ;
    int i ;
    int sz = v[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( used[ v[ vertex ][ i ] ] == true ) { continue ; }
        dfs ( v[ vertex ][ i ] ) ;
    }
}

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &q ) ;
    int i ;
    for ( i = 1 ; i <= q ; i ++ ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        y += n ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    int i ;
    int ans = 0 ;
    for ( i = 1 ; i <= n + m ; i ++ ) {
        if ( used[ i ] == false ) {
            dfs ( i ) ;
            ans ++ ;
        }
    }
    ans -- ;
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std ;

#define MAXN 150007

int n , m ;
vector < int > v[ MAXN ] ;
int used[ MAXN ] ;

long long br , edg ;

void dfs ( int vertex ) {
    used[ vertex ] = 1 ;
    br ++ ;
    int i ;
    int sz = v[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        edg ++ ;
        if ( used[ v[ vertex ][ i ] ] == 0 ) {
            dfs ( v[ vertex ][ i ] ) ;
        }
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    for ( i = 1 ; i <= m ; i ++ ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( used[ i ] == 0 ) {
            br = 0 ;
            edg = 0 ;
            dfs ( i ) ;
            if ( ( br * ( br - 1 ) ) != edg ) { printf ( "NO\n" ) ; return ; }
        }
    }
    printf ( "YES\n" ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
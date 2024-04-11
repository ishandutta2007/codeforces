#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;
int b[ MAXN ] ;
vector < int > v[ MAXN ] ;
int c[ MAXN ] ;

void dfs ( int vertex ) {
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( c[ v[ vertex ][ i ] ] > 0 ) { continue ; }
        c[ v[ vertex ][ i ] ] = 3 - c[ vertex ] ;
        dfs ( v[ vertex ][ i ] ) ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        a[ i ] = x ; b[ i ] = y ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
    for ( int i = 1 ; i < 2 * n ; i += 2 ) {
        v[ i ].push_back ( i + 1 ) ;
        v[ i + 1 ].push_back ( i ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= 2 * n ; ++ i ) {
        if ( c[ i ] == 0 ) {
            c[ i ] = 1 ;
            dfs ( i ) ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        printf ( "%d %d\n" , c[ a[ i ] ] , c[ b[ i ] ] ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
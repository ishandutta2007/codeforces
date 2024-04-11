#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;
vector < int > v[ MAXN ] ;

int ans = 0 ;
int dp[ MAXN ][ 3 ] ;



void dfs ( int vertex , int prv ) {
    int sz = v[ vertex ].size ( ) ;
    int mx[ 3 ][ 2 ] ;
    for ( int i = 0 ; i < 3 ; ++ i ) {
        for ( int j = 0 ; j < 2 ; ++ j ) {
            mx[ i ][ j ] = 0 ;
        }
    }
    int cnt = 0 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ] ;
        if ( h == prv ) { continue ; }
        ++ cnt ;
        dfs ( h , vertex ) ;
        for ( int j = 0 ; j < 3 ; ++ j ) {
            if ( mx[ j ][ 0 ] < dp[ h ][ j ] ) {
                mx[ j ][ 1 ] = mx[ j ][ 0 ] ;
                mx[ j ][ 0 ] = dp[ h ][ j ] ;
            }
            else if ( mx[ j ][ 1 ] < dp[ h ][ j ] ) {
                mx[ j ][ 1 ] = dp[ h ][ j ] ;
            }
        }
    }
    dp[ vertex ][ 0 ] = 1 + mx[ 1 ][ 0 ] ;
    dp[ vertex ][ 1 ] = max ( 0 , cnt - 1 ) + mx[ 2 ][ 0 ] ;
    dp[ vertex ][ 1 ] = max ( dp[ vertex ][ 1 ] , cnt ) ;
    dp[ vertex ][ 2 ] = max ( dp[ vertex ][ 0 ] , dp[ vertex ][ 1 ] ) ;
    ans = max ( ans , dp[ vertex ][ 2 ] ) ;
    if ( cnt >= 2 ) {
        ans = max ( mx[ 1 ][ 0 ] + mx[ 1 ][ 1 ] + 1 , ans ) ;
        ans = max ( cnt - 2 + mx[ 2 ][ 0 ] + mx[ 2 ][ 1 ] + ( prv != -1 ) , ans ) ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    dfs ( 1 , -1 ) ;
    printf ( "%d\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
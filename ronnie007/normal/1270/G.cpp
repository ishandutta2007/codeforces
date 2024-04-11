#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

#define MAXN 1000007

int n ;
vector < int > v[ MAXN ] ;
int used[ MAXN ] ;
int stk[ MAXN ] ;
int tpsz ;
bool done ;

void dfs ( int vertex ) {
    stk[ tpsz ++ ] = vertex ;
    used[ vertex ] = 2 ;
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( done == true ) { return ; }
        int nxt = v[ vertex ][ i ] ;
        if ( used[ nxt ] == 2 ) {
            done = true ;
            int ans = 0 ;
            for ( int j = 0 ; j < tpsz ; ++ j ) {
                if ( stk[ j ] == nxt ) { ans = tpsz - j ; break ; }
            }
            printf ( "%d\n" , ans ) ;
            for ( int j = 1 ; j <= ans ; ++ j ) {
                printf ( "%d " , stk[ tpsz - j ] ) ;
            }
            printf ( "\n" ) ;
        }
        else if ( used[ nxt ] == 0 ) {
            dfs ( nxt ) ;
        }
    }
    used[ vertex ] = 1 ;
    -- tpsz ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        v[ i ].clear ( ) ;
        used[ i ] = 0 ;
        done = false ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        int x ;
        scanf ( "%d" , &x ) ;
        v[ i - x ].push_back ( i ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == 0 ) {
            tpsz = 0 ;
            dfs ( i ) ;
        }
    }
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
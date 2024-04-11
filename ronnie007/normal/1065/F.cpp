#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007

int n , k ;
vector < int > v[ MAXN ] ;
int lvl[ MAXN ] ;

int cnt[ MAXN ] ;
int mndepth[ MAXN ] ;

int noreturn[ MAXN ] ;

void init ( int vertex ) {
    int sz = v[ vertex ].size ( ) ;
    if ( sz == 0 ) {
        cnt[ vertex ] = 1 ;
        mndepth[ vertex ] = lvl[ vertex ] ;
        return ;
    }
    mndepth[ vertex ] = MAXN ; 
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ] ;
        lvl[ h ] = lvl[ vertex ] + 1 ; 
        init ( h ) ;
        if ( mndepth[ h ] <= lvl[ vertex ] + k ) {
            cnt[ vertex ] += cnt[ h ] ;
            mndepth[ vertex ] = min ( mndepth[ vertex ] , mndepth[ h ] ) ;
        }
    }
}

void dfs ( int vertex ) {
    int sz = v[ vertex ].size ( ) ;
    if ( sz == 0 ) {
        noreturn[ vertex ] = 1 ;
        return ;
    }
    for ( int i = 0 ; i < sz ; ++ i ) {
        dfs ( v[ vertex ][ i ] ) ;
    }
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ] ;
        int aux = cnt[ vertex ] ;
        if ( mndepth[ h ] <= lvl[ vertex ] + k ) {
            aux -= cnt[ h ] ;
        }        
        noreturn[ vertex ] = max ( noreturn[ vertex ] , aux + noreturn[ h ] ) ;
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        int x ;
        scanf ( "%d" , &x ) ;
        v[ x ].push_back ( i ) ;
    }
}

void solve ( ) {
    init ( 1 ) ;
    dfs ( 1 ) ;
    printf ( "%d\n" , noreturn[ 1 ] ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
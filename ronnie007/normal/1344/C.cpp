#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n , m ;
vector < int > v[ MAXN ] ;
vector < int > rev[ MAXN ] ;

bool bad = false ;
int used[ MAXN ] ;

int up[ MAXN ] ;
int down[ MAXN ] ;
int ans[ MAXN ] ;

void mark_up ( int vertex ) {
    up[ vertex ] = 1 ;
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ] ;
        if ( up[ h ] == 1 ) { continue ; }
        mark_up ( h ) ;
    }
}

void mark_down ( int vertex ) {
    down[ vertex ] = 1 ;
    int sz = rev[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = rev[ vertex ][ i ] ;
        if ( down[ h ] == 1 ) { continue ; }
        mark_down ( h ) ;
    }
}

void dfs ( int vertex ) {
    int sz = v[ vertex ].size ( ) ;
    used[ vertex ] = 2 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ] ;
        if ( used[ h ] == 2 ) {
            bad = true ;
        }
        else if ( used[ h ] == 0 ) {
            dfs ( h ) ;
        }
    }
    used[ vertex ] = 1 ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        rev[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == 0 ) {
            dfs ( i ) ;
        }
    }
    if ( bad == true ) {
        printf ( "-1\n" ) ;
        return ;
    }
    int cnt = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( up[ i ] == 0 && down[ i ] == 0 ) {
            ++ cnt ; ans[ i ] = 1 ;
        }
        mark_up ( i ) ;
        mark_down ( i ) ;
    }
    printf ( "%d\n" , cnt ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( ans[ i ] == 1 ) { printf ( "A" ) ; }
        else { printf ( "E" ) ; }
    }
    printf ( "\n" ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
#include<bits/stdc++.h>
using namespace std ;

#define MAXN 32

long long sm[ MAXN ] ;
map < int , int > s[ MAXN ] ;

int q ;
int cnt ;

void add ( int x ) {
    int id = -1 ;
    int aux = x ;
    while ( aux > 0 ) {
        aux /= 2 ; ++ id ;
    }
    sm[ id ] += x ;
    ++ s[ id ][ x ] ;
    ++ cnt ;
}

void rem ( int x ) {
    int id = -1 ;
    int aux = x ;
    while ( aux > 0 ) {
        aux /= 2 ; ++ id ;
    }
    sm[ id ] -= x ;
    if ( s[ id ][ x ] == 1 ) {
        s[ id ].erase ( x ) ;
    }
    else {
        -- s[ id ][ x ] ;
    }
    -- cnt ;
}

int query ( ) {
    long long sr = 0 ;
    int ret = cnt ;
    for ( int i = 0 ; i < MAXN ; ++ i ) {
        if ( s[ i ].size ( ) == 0 ) { continue ; }
        int hh = s[ i ].begin ( )->first ;
        if ( hh > sr * 2 ) { -- ret ; }
        sr += sm[ i ] ;
    }
    return ret ;
}

void input ( ) {
    cin >> q ;
}

void solve ( ) {
    while ( q -- ) {
        char c ;
        int x ;
        cin >> c >> x ;
        if ( c == '-' ) {
            rem ( x ) ;
        }
        else {
            add ( x ) ;
        }
        cout << query ( ) << "\n" ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
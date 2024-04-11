#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007

int n ;
int a[ MAXN ] ;

vector < int > v[ MAXN ] ;
int mx[ MAXN ] ;

int lst[ MAXN ] ;
int fst[ MAXN ] ;

int pref[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        v[ i ].clear ( ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        v[ a[ i ] ].push_back ( i ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        mx[ i ] = n ;
    }
    stack < int > s ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        while ( s.empty ( ) == false && a[ s.top ( ) ] >= a[ i ] ) {
            s.pop ( ) ;
        }
        if ( s.empty ( ) == false ) {
            lst[ i ] = s.top ( ) ;
        }
        else {
            lst[ i ] = 0 ;
        }
        s.push ( i ) ;
    }
    while ( s.empty ( ) == false ) { s.pop ( ) ; }
    for ( int i = n ; i >= 1 ; -- i ) {
        while ( s.empty ( ) == false && a[ s.top ( ) ] >= a[ i ] ) {
            s.pop ( ) ;
        }
        if ( s.empty ( ) == false ) {
            fst[ i ] = s.top ( ) ;
        }
        else {
            fst[ i ] = n + 1 ; 
        }
        s.push ( i ) ;
    }
    pref[ 0 ] = MAXN ; 
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( v[ i ].empty ( ) == true ) {
            pref[ i ] = 0 ;
        }
        else {
            pref[ i ] = pref[ i - 1 ] ;
            int sz = v[ i ].size ( ) ;
            int mx = 0 ;
            for ( int j = 0 ; j < sz ; ++ j ) {
                mx = max ( mx , fst[ v[ i ][ j ] ] - lst[ v[ i ][ j ] ] ) ;
            }
            pref[ i ] = min ( pref[ i ] , mx ) ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( pref[ n - i + 1 ] > i ) { printf ( "1" ) ; }
        else { printf ( "0" ) ; }
    }
    printf ( "\n" ) ;
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
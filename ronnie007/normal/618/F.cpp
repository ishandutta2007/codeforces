#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007

int n ;
int a[ 2 ][ MAXN ] ;
long long pref[ 2 ][ MAXN ] ;

int aux[ MAXN ] ;
int lst[ MAXN ] ;

vector < int > ans[ 2 ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int id = 0 ; id < 2 ; ++ id ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            scanf ( "%d" , &a[ id ][ i ] ) ;
            pref[ id ][ i ] = pref[ id ][ i - 1 ] + a[ id ][ i ] ;
        }
    }
}

void solve ( ) {
    if ( pref[ 0 ][ n ] == pref[ 1 ][ n ] ) {
        for ( int tm = 0 ; tm < 2 ; ++ tm ) {
            printf ( "%d\n" , n ) ;
            for ( int i = 1 ; i <= n ; ++ i ) {
                printf ( "%d " , i ) ;
            }
        }
        return ;
    }
    int w = ( pref[ 1 ][ n ] < pref[ 0 ][ n ] ) ;
    int pos = 0 ;
    for ( int i = 0 ; i <= n ; ++ i ) { lst[ i ] = -1 ; }
    for ( int i = 0 ; i <= n ; ++ i ) {
        while ( pref[ w ][ i ] >= pref[ w ^ 1 ][ pos ] ) { ++ pos ; }
        aux[ i ] = pos ;
        int diff = pref[ w ^ 1 ][ pos ] - pref[ w ][ i ] ;
        if ( lst[ diff ] == -1 ) { lst[ diff ] = i ; }
        else {
            for ( int j = lst[ diff ] + 1 ; j <= i ; ++ j ) {
                ans[ w ].push_back ( j ) ;
            }
            for ( int j = aux[ lst[ diff ] ] + 1 ; j <= pos ; ++ j ) {
                ans[ w ^ 1 ].push_back ( j ) ;
            }
            break ;
        }
    }
    for ( int tm = 0 ; tm < 2 ; ++ tm ) {
        printf ( "%d\n" , ans[ tm ].size ( ) ) ;
        for ( auto x : ans[ tm ] ) {
            printf ( "%d " , x ) ;
        }
        printf ( "\n" ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // cin >> t ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
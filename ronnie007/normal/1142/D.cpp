#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int n ;
string a ;

int wh[ 12 ][ 12 ] ;
long long dp[ 12 ][ 2 ] ;

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    for ( int i = 0 ; i < 11 ; ++ i ) {
        for ( int j = 0 ; j < 11 ; ++ j ) {
            wh[ i ][ j ] = -1 ;
        }
    }
    int tp = 9 ;
    for ( int i = 0 ; i < 11 ; ++ i ) {
        for ( int j = 0 ; j < i ; ++ j ) {
            if ( j > 9 ) { break ; }
            tp = ( tp + 1 ) % 11 ;
            wh[ i ][ j ] = tp ;
        }
    }
    long long ans = 0 ;
    int prv = 0 , nxt = 1 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        int nw = ( a[ i ] - '0' ) ;
        for ( int j = 0 ; j < 11 ; ++ j ) {
            if ( wh[ j ][ nw ] >= 0 ) {
                dp[ wh[ j ][ nw ] ][ nxt ] += dp[ j ][ prv ] ;
            }
        }
        if ( nw > 0 ) { ++ dp[ nw ][ nxt ] ; }
        for ( int j = 0 ; j < 11 ; ++ j ) {
            ans += dp[ j ][ nxt ] ;
            dp[ j ][ prv ] = 0 ;
        }
        prv ^= 1 , nxt ^= 1 ;
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
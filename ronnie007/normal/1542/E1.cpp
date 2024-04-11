#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 52

int n , MOD ;

long long dp[ MAXN ][ MAXN * MAXN ][ 2 ] ;

void input ( ) {
    cin >> n >> MOD ;
}

void solve ( ) {
    int cnt_inv = n * ( n - 1 ) / 2 ;
    int offset = cnt_inv ;
    dp[ 0 ][ offset ][ 0 ] = 1 % MOD ;
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j <= 2 * cnt_inv ; ++ j ) {
            for ( int t = 0 ; t < 2 ; ++ t ) {
                if ( dp[ i ][ j ] == 0 ) { continue ; }

                for ( int nwx = 0 ; nwx <= i ; ++ nwx ) {
                    for ( int nwy = 0 ; nwy <= i ; ++ nwy ) {
                        int pos = j + nwx - nwy ;
                        int hh = 0 ;
                        if ( t == 0 && nwx >= nwy ) { hh = 0 ; }
                        else if ( t == 1 && nwx > nwy ) { hh = 0 ; }
                        else { hh = 1 ; }
                        dp[ i + 1 ][ pos ][ hh ] += dp[ i ][ j ][ t ] ;
                        if ( dp[ i + 1 ][ pos ][ hh ] >= MOD ) {
                            dp[ i + 1 ][ pos ][ hh ] -= MOD ;
                        }
                    }
                }
            }
        }
    }
    long long ans = 0 ;
    for ( int i = 0 ; i < cnt_inv ; ++ i ) {
        ans += dp[ n ][ i ][ 0 ] ;
        if ( ans >= MOD ) { ans -= MOD ; }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
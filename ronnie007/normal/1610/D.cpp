#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 200007
#define MOD 1000000007

int n ;
int a[ MAXN ] ;
int pw[ MAXN ] ;

int cnt[ 32 ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    pw[ 0 ] = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        pw[ i ] = ( pw[ i - 1 ] * 2 ) % MOD ;
    }
}   

void solve ( ) {
    int ans = ( pw[ n ] - 1 + MOD ) % MOD ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int hh = 0 ;
        while ( ( a[ i ] % 2 ) == 0 ) {
            a[ i ] /= 2 ;
            ++ hh ;
        }
        ++ cnt[ hh ] ;
    }
    int lft = n - cnt[ 0 ] ;
    for ( int i = 1 ; i <= 31 ; ++ i ) {
        if ( cnt[ i ] == 0 ) { continue ; }
        lft -= cnt[ i ] ;
        int coef = pw[ cnt[ i ] - 1 ] ;
        int sub = ( 1LL * coef * pw[ lft ] ) % MOD ;
        ans = ( ans + MOD - sub ) % MOD ;
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
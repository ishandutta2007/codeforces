#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 5007


int n ;
string a ;

int eq[ MAXN ][ MAXN ] ;

int dp[ MAXN ] ;

void input ( ) {
    cin >> n ;
    cin >> a ;
}

void solve ( ) {
    for ( int i = 0 ; i <= n + 1 ; ++ i ) {
        for ( int j = 0 ; j <= n + 1 ; ++ j ) {
            eq[ i ][ j ] = 0 ;
        }
    }
    for ( int i = n ; i >= 1 ; -- i ) {
        for ( int j = i - 1 ; j >= 1 ; -- j ) {
            if ( a[ i - 1 ] != a[ j - 1 ] ) {
                eq[ i ][ j ] = 0 ;
            }
            else {
                eq[ i ][ j ] = eq[ i + 1 ][ j + 1 ] + 1 ;
            }
        }
    }
    int ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        dp[ i ] = n - i + 1 ;
        for ( int j = 1 ; j < i ; ++ j ) {
            int sr1 = i + eq[ i ][ j ] - 1 ;
            int sr2 = j + eq[ i ][ j ] - 1 ;
            if ( a[ sr1 ] > a[ sr2 ] ) {
                dp[ i ] = max ( dp[ i ] , dp[ j ] + ( n - sr1 ) ) ;
            }
        }
        ans = max ( ans , dp[ i ] ) ;
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
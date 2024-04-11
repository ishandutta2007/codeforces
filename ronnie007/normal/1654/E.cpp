#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 100007
#define MAGIC 300


int n ;
int a[ MAXN ] ;
int cnt[ 2 * MAXN * MAGIC + 2 * MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    int OFFSET = MAXN * MAGIC + MAXN ;
    int ans = 0 ;
    for ( int hh = -MAGIC ; hh <= MAGIC ; ++ hh ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            ++ cnt[ OFFSET + a[ i ] - i * hh ] ;
            ans = max ( ans , cnt[ OFFSET + a[ i ] - i * hh ] ) ;
        }
        for ( int i = 1 ; i <= n ; ++ i ) {
            -- cnt[ OFFSET + a[ i ] - i * hh ] ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= 400 ; ++ j ) {
            if ( i + j > n ) { break ; }
            if ( ( a[ i + j ] - a[ i ] ) % j == 0 ) {
                ++ cnt[ OFFSET + ( a[ i + j ] - a[ i ] ) / j ] ;
                ans = max ( ans , cnt[ OFFSET + ( a[ i + j ] - a[ i ] ) / j ] + 1 ) ;
            }
        }        
        for ( int j = 1 ; j <= 400 ; ++ j ) {
            if ( i + j > n ) { break ; }
            if ( ( a[ i + j ] - a[ i ] ) % j == 0 ) {
                -- cnt[ OFFSET + ( a[ i + j ] - a[ i ] ) / j ] ;
            }
        }
    }
    cout << n - ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ;
    // cin >> t ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
#include<bits/stdc++.h>
using namespace std ;

#define MAXN 5007
#define MOD 1000000007

int n , k , q ;
int a[ MAXN ] ;

long long dp[ MAXN ][ MAXN ] ;
long long ways[ MAXN ] ;

void input ( ) {
    cin >> n >> k >> q ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}


void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        dp[ 0 ][ i ] = 1 ;
    }
    for ( int t = 1 ; t <= k ; ++ t ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            if ( i > 1 ) {
                dp[ t ][ i - 1 ] += dp[ t - 1 ][ i ] ;
                if ( dp[ t ][ i - 1 ] >= MOD ) {
                    dp[ t ][ i - 1 ] -= MOD ;
                }
            }
            if ( i < n ) {
                dp[ t ][ i + 1 ] += dp[ t - 1 ][ i ] ;
                if ( dp[ t ][ i + 1 ] >= MOD ) {
                    dp[ t ][ i + 1 ] -= MOD ;
                }
            }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j <= k ; ++ j ) {
            long long hh = ( dp[ j ][ i ] * dp[ k - j ][ i ] ) % MOD ;
            ways[ i ] += hh ;
            if ( ways[ i ] >= MOD ) { ways[ i ] -= MOD ; }
        }
    }
    long long ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        ans += ( ways[ i ] * a[ i ] ) % MOD ;
        ans %= MOD ;
    }
    while ( q -- ) {
        int pos , nw ;
        cin >> pos >> nw ;
        ans -= ( ways[ pos ] * a[ pos ] ) % MOD ;
        ans = ( ans + MOD ) % MOD ;

        a[ pos ] = nw ;
        ans += ( ways[ pos ] * a[ pos ] ) % MOD ;
        ans %= MOD ;

        cout << ans << "\n" ;
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
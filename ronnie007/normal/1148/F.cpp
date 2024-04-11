#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007

int n ;
long long val[ MAXN ] ;
long long mask[ MAXN ] ;

void input ( ) {
    cin >> n ;
    long long sm = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> val[ i ] >> mask[ i ] ;
        sm += val[ i ] ;
    }
    if ( sm > 0 ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            val[ i ] = -val[ i ] ;
        }
    }
}

void solve ( ) {
    long long ans = 0 ;
    for ( long long bit = 0 ; bit < 62 ; ++ bit ) {
        long long sm = 0 ;
        long long aux = ( 1LL << bit ) ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            if ( ( mask[ i ] & aux ) > 0 && 2 * aux > mask[ i ] ) {
                sm += val[ i ] ;
            }
        }
        if ( sm < 0 ) {
            ans += aux ;
            for ( int i = 1 ; i <= n ; ++ i ) {
                if ( ( mask[ i ] & aux ) > 0 ) {
                    val[ i ] = -val[ i ] ;
                }
            }
        }
    }
    cout << ans << "\n" ;
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
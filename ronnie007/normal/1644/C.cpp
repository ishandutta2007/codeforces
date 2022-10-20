#include<bits/stdc++.h>
using namespace std ;

#define MAXN 5007

int n , x ;
int a[ MAXN ] ;

long long mx[ MAXN ] ;
long long suff[ MAXN ] ;

void input ( ) {
    cin >> n >> x ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    for ( int i = 0 ; i <= n ; ++ i ) {
        mx[ i ] = suff[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        mx[ i ] = mx[ i - 1 ] + a[ i ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        long long hh = 0 ;
        for ( int j = i ; j <= n ; ++ j ) {
            hh += a[ j ] ;
            mx[ j - i + 1 ] = max ( mx[ j - i + 1 ] , hh ) ;
        }
    }
    suff[ n ] = mx[ n ] ;
    for ( int i = n - 1 ; i >= 0 ; -- i ) {
        suff[ i ] = max ( mx[ i ] , suff[ i + 1 ] ) ;
    }
    long long ans = suff[ 0 ] ;
    for ( int i = 0 ; i <= n ; ++ i ) {
        ans = max ( ans , suff[ i ] + 1LL * x * i ) ;
        cout << ans << " " ;
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    /// t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
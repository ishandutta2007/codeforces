#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007
#define MOD 998244353

int n ;
int a[ MAXN ] ;


long long fastpow ( long long x , long long pw ) {
    long long ret = 1 ;
    while ( pw > 0 ) {
        if ( ( pw % 2 ) == 0 ) {
            x = ( x * x ) % MOD ;
            pw /= 2 ;
        }
        else {
            ret = ( ret * x ) % MOD ;
            -- pw ;
        }
    }
    return ret ;
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= 2 * n ; ++ i ) {
        cin >> a[ i ] ;
    }
    sort ( a + 1 , a + 2 * n + 1 ) ;
}

void solve ( ) {
    long long ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        ans -= a[ i ] ;
        ans += a[ n + i ] ;
    }
    ans %= MOD ;
    for ( int i = n + 1 ; i <= 2 * n ; ++ i ) {
        ans = ( ans * i ) % MOD ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        ans = ( ans * fastpow ( i , MOD - 2 ) ) % MOD ;
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    /// cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
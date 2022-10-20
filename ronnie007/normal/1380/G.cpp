#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007
#define MOD 998244353

int n ;
int a[ MAXN ] ;
long long pref[ MAXN ] ;

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
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        pref[ i ] = ( pref[ i - 1 ] + a[ i ] ) % MOD ;
    }
}

void solve ( ) {
    long long inv = fastpow ( n , MOD - 2 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int en = n - i ;
        long long ans = 0 ;
        long long aux = 1 ;
        while ( en >= i ) {
            ans += ( pref[ en ] - pref[ en - i ] ) * ( aux ++ ) ;
            ans %= MOD ;
            en -= i ;
        }
        ans += pref[ en ] * aux ;
        ans %= MOD ;
        ans = ( ans * inv ) % MOD ;
        cout << ans << " " ;
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
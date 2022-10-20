#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 1000007 ;
const int MOD = 998244353 ;

ll n ;
ll fac[ MAXN ] , inv[ MAXN ] ;

ll fastpow ( ll x , ll pw ) {
    ll ret = 1 ;
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

ll comb ( int up , int down ) {
    if ( up < down ) { return 0 ; }
    ll ret = fac[ up ] ;
    ret = ( ret * inv[ down ] ) % MOD ;
    ret = ( ret * inv[ up - down ] ) % MOD ;
    return ret ;
}


void input ( ) {
    cin >> n ;
    fac[ 0 ] = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        fac[ i ] = ( fac[ i - 1 ] * i ) % MOD ;
    }
    inv[ n ] = fastpow ( fac[ n ] , MOD - 2 ) ;
    for ( int i = n - 1 ; i >= 0 ; -- i ) {
        inv[ i ] = ( inv[ i + 1 ] * ( i + 1 ) ) % MOD ;
    }
}

void solve ( ) {
    ll ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        ll coef = 1 ;
        if ( ( i % 2 ) == 0 ) { coef = MOD - 1 ; }
        ll pw = ( n - i ) * n + i ;
        coef = ( coef * fastpow ( 3 , pw ) ) % MOD ;
        coef = ( coef * comb ( n , i ) ) % MOD ;
        ans = ( ans + MOD + coef ) % MOD ;
    }
    ans = ( ans * 2 ) % MOD ;
    for ( int i = 0 ; i < n ; ++ i ) {
        ll aux = 1 ;
        if ( ( i % 2 ) == 0 ) { aux = MOD - 1 ; }
        aux = ( aux * comb ( n , i ) ) % MOD ;
        aux = ( aux * 3 ) % MOD ;

        ll hh = ( MOD - fastpow ( 3 , i ) ) % MOD ;
        ll coef = ( fastpow ( 1 + hh , n ) - fastpow ( hh , n ) + MOD ) % MOD ;
        aux = ( aux * coef ) % MOD ;
        ans = ( ans + aux + MOD ) % MOD ;
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
#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 4e5 + 7 ;
const int MOD = 1e9 + 7 ;

int n ;
int a[ MAXN ] ;

ll fac[ MAXN ] ;
ll inv[ MAXN ] ;

ll fastpow ( ll x , int pw ) {
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

ll comb ( ll up , ll down ) {
    if ( up < down || down < 0 ) { return 0 ; }
    ll ret = fac[ up ] ;
    ret = ( ret * inv[ down ] ) % MOD ;
    ret = ( ret * inv[ up - down ] ) % MOD ;
    return ret ;
}

void solve ( ) {
    cin >> n ;
    for ( int i = 0 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    fac[ 0 ] = 1 ;
    for ( int i = 1 ; i < MAXN ; ++ i ) {
        fac[ i ] = ( fac[ i - 1 ] * i ) % MOD ;
    }
    inv[ MAXN - 1 ] = fastpow ( fac[ MAXN - 1 ] , MOD - 2 ) ;
    for ( int i = MAXN - 2 ; i >= 0 ; -- i ) {
        inv[ i ] = ( inv[ i + 1 ] * ( i + 1 ) ) % MOD ;
    }
    ll ans = 0 ;
    for ( int i = 0 ; i <= n ; ++ i ) {
        ans += comb ( i + a[ i ] , a[ i ] - 1 ) ;
        ans %= MOD ;
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; // cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}
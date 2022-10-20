#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair < int , int > pii ; 
#define fi first
#define se second
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int MOD = 998244353 ;
const int MAXN = 2e5 + 7 ;

int n ;
ll a[ MAXN ] ;
ll pref[ MAXN ] ;
map < ll , int > w[ 2 ] ;

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

void init ( ) {
    fac[ 0 ] = 1 ;
    for ( int i = 1 ; i < MAXN ; ++ i ) {
        fac[ i ] = ( fac[ i - 1 ] * i ) % MOD ;
    }
    inv[ MAXN - 1 ] = fastpow ( fac[ MAXN - 1 ] , MOD - 2 ) ;
    for ( int i = MAXN - 2 ; i >= 0 ; -- i ) {
        inv[ i ] = ( inv[ i + 1 ] * ( i + 1 ) ) % MOD ;
    }
}

ll comb ( int up , int down ) {
    if ( up < down || down < 0 ) { return 0 ; }
    ll ret = fac[ up ] ;
    ret = ( ret * inv[ down ] ) % MOD ;
    ret = ( ret * inv[ up - down ] ) % MOD ;
    return ret ;
}


void solve ( ) {
    cin >> n ;
    w[ 0 ].clear ( ) ; w[ 1 ].clear ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        pref[ i ] = pref[ i - 1 ] + a[ i ] ;
    }
    ll eq = 0 ;
    for ( int i = 1 ; i < n ; ++ i ) {
        if ( 2 * pref[ i ] == pref[ n ] ) { ++ eq ; }
        if ( pref[ i ] < pref[ n ] - pref[ i ] ) {
            ++ w[ 0 ][ pref[ i ] ] ;
        }
        else {
            ++ w[ 1 ][ pref[ i ] ] ;
        }
    }
    ll ans = 1 ;
    for ( auto e : w[ 0 ] ) {
        int x = e.se , y = w[ 1 ][ pref[ n ] - e.fi ] ;
        int len = min ( x , y ) ;
        if ( len > 0 ) {
            ll nw = 1 ; 
            for ( int i = 1 ; i <= len ; ++ i ) {
                ll hh1 = comb ( x , i ) ;
                ll hh2 = comb ( y , i ) ;
                hh1 = ( hh1 * hh2 ) % MOD ;
                nw = ( nw + hh1 ) % MOD ;
            }
            ans = ( ans * nw ) % MOD ;
        }
    }
    ll nw = 1 ;
    for ( int i = 1 ; i <= eq ; ++ i ) {
        nw = ( nw + comb ( eq , i ) ) % MOD ;
    }
    ans = ( ans * nw ) % MOD ;
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    init ( ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}
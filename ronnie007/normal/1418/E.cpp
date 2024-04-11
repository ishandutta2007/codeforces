#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 2e5 + 7 ;
const int MOD = 998244353 ;

int n , q ;
int a[ MAXN ] ;
ll pref[ MAXN ] ;

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

ll fac[ MAXN ] , inv[ MAXN ] ;

int f ( int sr ) {
    if ( sr <= a[ 1 ] ) { return 0 ; }
    int l = 1 , r = n , mid ; 
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( a[ mid ] < sr ) { l = mid ; }
        else { r = mid ; }
    }
    while ( a[ r ] >= sr ) { -- r ; }
    return r ;
}


void solve ( ) {
    cin >> n >> q ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        pref[ i ] = pref[ i - 1 ] + a[ i ] ;
    }
    fac[ 0 ] = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        fac[ i ] = ( fac[ i - 1 ] * i ) % MOD ;
    }
    inv[ n ] = fastpow ( fac[ n ] , MOD - 2 ) ;
    for ( int i = n - 1 ; i >= 0 ; -- i ) {
        inv[ i ] = ( inv[ i + 1 ] * ( i + 1 ) ) % MOD ;
    }
    while ( q -- ) {
        int charges , mx ;
        cin >> charges >> mx ;
        int cnt_small = f ( mx ) ;
        int cnt_big = n - cnt_small ;
        ll sm_small = pref[ cnt_small ] ;
        ll sm_big = pref[ n ] - sm_small ;
        sm_small %= MOD , sm_big %= MOD ;
        ll ans = 0 ;
        if ( cnt_big >= charges ) {
            ll coef = ( ( cnt_big - charges ) * fastpow ( cnt_big , MOD - 2 ) ) % MOD ;
            ans = ( ans + sm_big * coef ) % MOD ;

            coef = ( ( cnt_big - charges + 1 ) * fastpow ( cnt_big + 1 , MOD - 2 ) ) % MOD ;
            ans = ( ans + sm_small * coef ) % MOD ;
        }
        cout << ans << "\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; // cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}
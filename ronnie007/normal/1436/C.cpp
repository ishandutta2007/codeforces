#include<bits/stdc++.h>
using namespace std ;

#define MOD 1000000007
#define MAXN 1007

int n , x , pos ;
int cnt1 , cnt2 ;

long long fac[ MAXN ] ;
long long inv[ MAXN ] ;

long long fastpow ( long long aux , long long pw ) {
    long long ret = 1 ;
    while ( pw > 0 ) {
        if ( ( pw % 2 ) == 0 ) {
            aux = ( aux * aux ) % MOD ;
            pw /= 2 ;
        }
        else {
            ret = ( ret * aux ) % MOD ;
            -- pw ;
        }
    }
    return ret ;
}

long long calc ( int h1 , int h2 ) {
    if ( h2 > h1 ) { return 0 ; }
    return ( fac[ h1 ] * inv[ h1 - h2 ] ) % MOD ;
}

void input ( ) {
    cin >> n >> x >> pos ;
}

void solve ( ) {
    int l , r , mid ;
    l = 0 ; r = n ;
    while ( l < r ) {
        mid = ( l + r ) / 2 ;
        if ( mid <= pos ) { l = mid + 1 ; ++ cnt1 ; }
        else { r = mid ; ++ cnt2 ; }
    }
    -- cnt1 ;
    fac[ 0 ] = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        fac[ i ] = ( fac[ i - 1 ] * i ) % MOD ;
    }
    inv[ n ] = fastpow ( fac[ n ] , MOD - 2 ) ;
    for ( int i = n - 1 ; i >= 0 ; -- i ) {
        inv[ i ] = ( inv[ i + 1 ] * ( i + 1 ) ) % MOD ;
    }
    long long ans = calc ( n - x , cnt2 ) ;
    ans = ( ans * calc ( x - 1 , cnt1 ) ) % MOD ;
    ans = ( ans * fac[ n - cnt1 - cnt2 - 1 ] ) % MOD ;
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
#include<bits/stdc++.h>
using namespace std ;

#define MOD 1000000007
#define MAXN 200007

int n , m , k ;
int cnt[ MAXN ] ;

long long fac[ MAXN ] ;
long long inv[ MAXN ] ;

long long fastpow ( long long x , long long pw ) {
    long long ret = 1 ;
    while ( pw > 0 ) {
        if ( ( pw % 2 ) == 0 ) {
            pw /= 2 ;
            x = ( x * x ) % MOD ;
        }
        else {
            -- pw ;
            ret = ( ret * x ) % MOD ;
        }
    }
    return ret ;
}

long long comb ( int x , int y ) {
    if ( y > x ) { return 0 ; }
    long long ret = fac[ x ] ;
    ret = ( ret * inv[ y ] ) % MOD ;
    ret = ( ret * inv[ x - y ] ) % MOD ;
    return ret ;
}

void input ( ) {
    cin >> n >> m >> k ;
    // m = 3 ; k = 2 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cnt[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        int x ; 
        cin >> x ;
        ++ cnt[ x ] ;
    }
}

void solve ( ) {
    int aux = 0 ;
    long long ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        aux += cnt[ i ] ;
        if ( i > k + 1 ) {
            aux -= cnt[ i - k - 1 ] ;
        }
        ans += comb ( aux , m ) ;
        // ans -= comb ( aux - cnt[ i ] , m ) ;
        ans = ( ans - comb ( aux - cnt[ i ] , m ) + MOD ) % MOD ;
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    fac[ 0 ] = 1 ;
    for ( int i = 1 ; i < MAXN ; ++ i ) {
        fac[ i ] = ( fac[ i - 1 ] * i ) % MOD ;
    }
    inv[ MAXN - 1 ] = fastpow ( fac[ MAXN - 1 ] , MOD - 2 ) ;
    for ( int i = MAXN - 2 ; i >= 0 ; -- i ) {
        inv[ i ] = ( inv[ i + 1 ] * ( i + 1 ) ) % MOD ;
    }
    int t ;
    cin >> t ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
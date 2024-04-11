#include<bits/stdc++.h>
using namespace std ;

#define MAXN 3000007
#define MOD 1000000007

int n , q ;

long long fac[ MAXN ] ;
long long inv[ MAXN ] ;
long long dp[ MAXN ][ 3 ] ;

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

long long comb ( int up , int down ) {
    long long ret = fac[ up ] ;
    ret = ( ret * inv[ down ] ) % MOD ;
    ret = ( ret * inv[ up - down ] ) % MOD ;
    return ret ;
}

void input ( ) {
    cin >> n >> q ;
    fac[ 0 ] = 1 ;
    for ( int i = 1 ; i < MAXN ; ++ i ) {
        fac[ i ] = ( fac[ i - 1 ] * i ) % MOD ;
    }
    inv[ MAXN - 1 ] = fastpow ( fac[ MAXN - 1 ] , MOD - 2 ) ;
    for ( int i = MAXN - 2 ; i >= 0 ; -- i ) {
        inv[ i ] = ( inv[ i + 1 ] * ( i + 1 ) ) % MOD ;
    }
}

void solve ( ) {
    dp[ 0 ][ 0 ] = dp[ 0 ][ 1 ] = dp[ 0 ][ 2 ] = n ;
    long long inv3 = fastpow ( 3 , MOD - 2 ) ;
    for ( int i = 1 ; i < 3 * n ; ++ i ) {
        long long sm = comb ( 3 * n , i + 1 ) ;
        dp[ i ][ 0 ] = sm - 2 * dp[ i - 1 ][ 0 ] - dp[ i - 1 ][ 1 ] ;
        while ( dp[ i ][ 0 ] < 0 ) { dp[ i ][ 0 ] += MOD ; }
        dp[ i ][ 0 ] = ( dp[ i ][ 0 ] * inv3 ) % MOD ;

        dp[ i ][ 1 ] = ( dp[ i ][ 0 ] + dp[ i - 1 ][ 0 ] ) % MOD ;
        dp[ i ][ 2 ] = ( dp[ i ][ 1 ] + dp[ i - 1 ][ 1 ] ) % MOD ;
    }
    while ( q -- ) {
        int x ; cin >> x ;
        cout << ( dp[ x ][ 0 ] + comb ( 3 * n , x ) ) % MOD << "\n" ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 403

int n ;
long long MOD ;


long long dp[ MAXN ][ MAXN ] ;

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

long long fac[ MAXN ] ;
long long inv[ MAXN ] ;

long long len[ MAXN ] ;

long long comb ( int up , int down ) {
    if ( down > up ) { return 0 ; }
    long long ret = fac[ up ] ;
    ret = ( ret * inv[ down ] ) % MOD ;
    ret = ( ret * inv[ up - down ] ) % MOD ;
    return ret ;
}

void init ( ) {
    fac[ 0 ] = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        fac[ i ] = ( fac[ i - 1 ] * i ) % MOD ;
    }
    inv[ n ] = fastpow ( fac[ n ] , MOD - 2 ) ;
    for ( int i = n - 1 ; i >= 0 ; -- i ) {
        inv[ i ] = ( inv[ i + 1 ] * ( i + 1 ) ) % MOD ;
    }
    len[ 0 ] = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        len[ i ] = 0 ;
        for ( int j = 1 ; j <= i ; ++ j ) {
            long long aux = comb ( i - 1 , j - 1 ) ;
            len[ i ] += aux ;
            len[ i ] %= MOD ;
        }
    }
}



void input ( ) {
    cin >> n >> MOD ;
}

void solve ( ) {
    init ( ) ;
    dp[ 1 ][ 1 ] = 1 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        dp[ i ][ i ] = len[ i ] ;
    }
    for ( int i = 3 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j < i ; ++ j ) {
            for ( int t = 1 ; t <= j ; ++ t ) {
                long long aux = dp[ i - t - 1 ][ j - t ] ;
                aux *= comb ( j , t ) ;
                aux %= MOD ;
                aux = ( aux * len[ t ] ) % MOD ;

                dp[ i ][ j ] += aux ;
                dp[ i ][ j ] %= MOD ;
            }
        }
    }
    long long ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        ans += dp[ n ][ i ] ;
        ans %= MOD ;
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
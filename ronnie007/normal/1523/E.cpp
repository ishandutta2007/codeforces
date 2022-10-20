#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MOD 1000000007
#define MAXN 100007

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

long long comb ( int up , int down ) {
    if ( up < down ) { return 0 ; }
    long long ret = fac[ up ] ;
    ret = ( ret * inv[ down ] ) % MOD ;
    ret = ( ret * inv[ up - down ] ) % MOD ;
    return ret ;
}

int n , k ;

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
}

void solve ( ) {
    long long ans = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int lft = n - ( i - 1 ) * ( k - 1 ) ;
        if ( lft < 0 ) { break ; }
        long long ret = comb ( lft , i ) ;
        ret = ( ret * fac[ i ] ) % MOD ;
        ret = ( ret * inv[ n ] ) % MOD ;
        ret = ( ret * fac[ n - i ] ) % MOD ;
        ans += ret ;
        if ( ans >= MOD ) { ans -= MOD ; }
    }
    printf ( "%lld\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    // t = 1 ;
    init ( ) ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
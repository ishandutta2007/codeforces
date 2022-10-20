#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MOD 998244353
#define MAXN 10007

int n , sm , lw ;

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

long long comb ( int up , int down ) {
    if ( down > up ) { return 0 ; }
    long long ret = fac[ up ] ;
    ret = ( ret * inv[ down ] ) % MOD ;
    ret = ( ret * inv[ up - down ] ) % MOD ;
    return ret ;
}

long long calc ( int lft , int lim , int cnt ) {
    if ( cnt == 0 ) {
        if ( lft == 0 ) { return 1 ; }
        return 0 ;
    }
    long long ans = 0 ;
    for ( int i = 0 ; i <= cnt ; ++ i ) {
        long long aux = comb ( cnt , i ) ;
        aux = ( aux * comb ( lft - lim * i + cnt - 1 , cnt - 1 ) ) % MOD ;
        
        if ( ( i % 2 ) == 0 ) { ans = ( ans + aux ) % MOD ; }
        else { ans = ( ans + MOD - aux ) % MOD ; }
    }
    return ans ;
}

void input ( ) {
    cin >> n >> sm >> lw ;
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
    long long ans = 0 ;
    long long tot = comb ( sm - lw + n - 1 , n - 1 ) ;
    for ( int i = lw ; i <= sm ; ++ i ) {
        for ( int j = 0 ; j < n ; ++ j ) {
            int lft = sm - i * ( j + 1 ) ;
            if ( lft < 0 ) { continue ; }
            long long aux = calc ( lft , i , n - j - 1 ) ;
            aux = ( aux * comb ( n - 1 , j ) ) % MOD ;
            aux = ( aux * fastpow ( j + 1 , MOD - 2 ) ) % MOD ;

            ans = ( ans + aux ) % MOD ;
        }
    }
    cout << ( ans * fastpow ( tot , MOD - 2 ) ) % MOD << "\n" ;
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
#include<bits/stdc++.h>
using namespace std ;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 14
#define MOD 1000000007

int n ;
int a[ MAXN ] ;



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

long long dp[ ( 1 << MAXN ) ] ;

long long inv[ MAXN ][ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> a[ i ] ;
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < n ; ++ j ) {
            inv[ i ][ j ] = fastpow ( a[ i ] + a[ j ] , MOD - 2 ) ;
        }
    }
}

void solve ( ) {
    long long ans = 0 ;
    for ( int i = 1 ; i < ( 1 << n ) ; ++ i ) {
        dp[ i ] = 1 ;
        for ( int j = 0 ; j < n ; ++ j ) {
            if ( ( i & ( 1 << j ) ) == 0 ) { continue ; }
            for ( int t = 0 ; t < n ; ++ t ) {
                if ( ( i & ( 1 << t ) ) > 0 ) { continue ; }
                dp[ i ] = ( dp[ i ] * a[ j ] ) % MOD ;
                dp[ i ] = ( dp[ i ] * inv[ j ][ t ] ) % MOD ;
            }
        }
        for ( int mask = i ; mask > 0 ; mask = ( mask - 1 ) & i ) {
            if ( mask == i ) { continue ; }
            long long coef = dp[ mask ] ;
            for ( int j = 0 ; j < n ; ++ j ) {
                if ( ( mask & ( 1 << j ) ) == 0 && ( i & ( 1 << j ) ) > 0 ) {
                    for ( int t = 0 ; t < n ; ++ t ) {
                        if ( ( i & ( 1 << t ) ) > 0 ) { continue ; }
                        coef = ( coef * a[ j ] ) % MOD ;
                        coef = ( coef * inv[ j ][ t ] ) % MOD ;                    
                    }
                }
            }
            dp[ i ] = ( dp[ i ] - coef + MOD ) % MOD ;
        }
        ans = ( ans + ( dp[ i ] * __builtin_popcount ( i ) ) % MOD + MOD ) % MOD ; 
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
#include<bits/stdc++.h>
using namespace std ;

#define MOD 998244353
#define MAXN 100007

int n ;
int cnt[ MAXN ] ;

long long ans[ MAXN ] ;

long long fastpow ( long long x , long long pw ) {
    if ( pw < 0 ) { return 0 ; }
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

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        cnt[ x ] = y ;
    }
}

void solve ( ) {
    for ( int i = MAXN - 1 ; i >= 1 ; -- i ) {
        long long tot = 0 ;
        long long sm = 0 ;
        long long sq = 0 ;
        long long w = 0 ;
        for ( int j = i ; j < MAXN ; j += i ) {
            tot += cnt[ j ] ;
            long long aux = ( 1LL * cnt[ j ] * j ) % MOD ;
            w = ( w + ( 2LL * sm * aux ) % MOD ) % MOD ;
            long long pairs = ( 1LL * cnt[ j ] * ( cnt[ j ] - 1 ) ) % MOD ;
            w = ( w + ( ( ( pairs * j ) % MOD ) * j ) % MOD ) % MOD ;
            sm = ( sm + aux ) % MOD ;
            sq = ( sq + ( ( ( 1LL * cnt[ j ] * j ) % MOD )* j ) % MOD ) % MOD ;
        }
        if ( tot == 0 ) { continue ; }
        long long coef = fastpow ( 2 , tot - 2 ) ;
        coef = ( coef * ( ( tot - 1 ) % MOD ) ) % MOD ;
        ans[ i ] = ( coef * sq ) % MOD ;

        coef = fastpow ( 2 , tot - 3 ) ;
        coef = ( coef * ( ( tot - 2 ) % MOD ) ) % MOD ;
        coef = ( coef + fastpow ( 2 , tot - 2 ) ) % MOD ;

        ans[ i ] = ( ans[ i ] + ( coef * w ) % MOD ) % MOD ;

        for ( int j = 2 * i ; j < MAXN ; j += i ) {
            ans[ i ] = ( ans[ i ] - ans[ j ] + MOD ) % MOD ;
        }
    }
    printf ( "%I64d\n" , ans[ 1 ] ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
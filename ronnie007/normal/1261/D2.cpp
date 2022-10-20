#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<stack>
#include<ctime>
#include<set>
using namespace std ;

#define MAXN 200007
#define MOD 998244353

long long n , k ;
int a[ MAXN ] ;
long long fac[ MAXN ] ;
long long inv[ MAXN ] ;
long long pw2[ MAXN ] ;
long long free_pw[ MAXN ] ;

long long fastpow ( long long x , long long st ) {
    long long ret = 1 ;
    while ( st > 0 ) {
        if ( ( st & 1 ) != 0 ) {
            ret = ( ret * x ) % MOD ;
            -- st ;
        }
        else {
            x = ( x * x ) % MOD ;
            st >>= 1 ;
        }
    }
    return ret ;
}

long long get_comb ( long long x , long long y ) {
    if ( x < y ) { return 0 ; }
    long long ret = fac[ x ] ;
    ret = ( ret * inv[ y ] ) % MOD ;
    ret = ( ret * inv[ x - y ] ) % MOD ;
    return ret ;
}


void input ( ) {
    scanf ( "%I64d%I64d" , &n , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    a[ n + 1 ] = a[ 1 ] ;
    fac[ 0 ] = pw2[ 0 ] = free_pw[ 0 ] = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        fac[ i ] = ( fac[ i - 1 ] * i ) % MOD ;
        pw2[ i ] = ( pw2[ i - 1 ] * 2 ) % MOD ;
        free_pw[ i ] = ( free_pw[ i - 1 ] * ( k - 2 ) ) % MOD ;
    }
    inv[ n ] = fastpow ( fac[ n ] , MOD - 2 ) ;
    for ( int i = n - 1 ; i >= 0 ; -- i ) {
        inv[ i ] = ( inv[ i + 1 ] * ( i + 1 ) ) % MOD ;
    }
}

void solve ( ) {
    int free = 0 ;
    long long aux = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ] == a[ i + 1 ] ) { ++ free , aux = ( aux * k ) % MOD ; }
    }
    long long ans = 0 ;
    for ( int i = 0 ; i < n - free ; ++ i ) {
        long long w = ( get_comb ( n - free , i ) * free_pw[ i ] ) % MOD ;
        int lft = n - free - i ;
        long long coef = pw2[ lft ] ;
        if ( ( lft & 1 ) == 0 ) {
            coef = ( coef - get_comb ( lft , lft / 2 ) + MOD ) % MOD ;
        }
        coef = ( coef * inv[ 2 ] ) % MOD ;
        ans = ( ans + ( w * coef ) % MOD ) % MOD ;
    }
    printf ( "%I64d\n" , ( aux * ans ) % MOD ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
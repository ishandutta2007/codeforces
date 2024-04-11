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
using namespace std ;


#define MOD 1000000007
#define MAXN 1007

int k ;
long long p1 , p2 ;
long long sm ;
long long pra , prb ;

long long dp[ MAXN ][ MAXN ] ;

long long fastpow ( long long a , long long x ) {
    long long ret = 1 ;
    while ( x != 0 ) {
        if ( ( x % 2 ) == 0 ) {
            a = ( a * a ) % MOD ;
            x /= 2 ;
        }
        else {
            ret = ( ret * a ) % MOD ;
            x -- ;
        }
    }
    return ret ;
}

long long dfs ( int x , int cur ) {
    if ( ( x + cur ) >= k ) {
        long long ret1 = ( ( ( prb * ( x + cur ) ) % MOD ) * ( fastpow ( ( 1 - pra + MOD ) % MOD , MOD - 2 ) ) ) % MOD ;
        long long aux = ( MOD + pra - 1 ) % MOD ;
        long long ret2 = ( prb * ( ( pra * fastpow ( ( aux * aux ) % MOD , MOD - 2 ) ) % MOD ) % MOD ) % MOD ;
        return ( ret1 + ret2 ) % MOD ;
    }
    if ( dp[ x ][ cur ] != -1 ) { return dp[ x ][ cur ] ; }
    dp[ x ][ cur ] = 0 ;
    if ( x == 0 ) {
        dp[ x ][ cur ] = ( ( ( pra * fastpow ( ( 1 - prb + MOD ) % MOD , MOD - 2 ) ) % MOD ) * dfs ( x + 1 , cur ) ) % MOD ;
        return dp[ x ][ cur ] ;
    }
    dp[ x ][ cur ] = ( pra * dfs ( x + 1 , cur ) ) % MOD ;
    dp[ x ][ cur ] = ( dp[ x ][ cur ] + ( ( prb * dfs ( x , cur + x ) ) % MOD ) ) % MOD ;
    return dp[ x ][ cur ] ;
}

void input ( ) {
    scanf ( "%d%I64d%I64d" , &k , &p1 , &p2 ) ;
    sm = ( p1 + p2 ) ;
    pra = ( p1 * fastpow ( p1 + p2 , MOD - 2 ) ) % MOD ;
    prb = ( p2 * fastpow ( p1 + p2 , MOD - 2 ) ) % MOD ;
}

void solve ( ) {
    int i , j ;
    for ( i = 0 ; i <= k ; i ++ ) {
        for ( j = 0 ; j <= k ; j ++ ) {
            dp[ i ][ j ] = -1 ;
        }
    }
    printf ( "%I64d\n" , dfs ( 0 , 0 ) ) ;
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
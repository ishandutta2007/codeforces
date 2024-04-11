#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std ;

#define MOD 998244353
#define MAXN 3607

int n , m ;
int r[ MAXN ] ;
int c[ MAXN ] ;

long long dp_r[ MAXN ][ MAXN ] ;
long long dp_c[ MAXN ][ MAXN ] ;

long long fac[ MAXN ] ;
long long inv[ MAXN ] ;

int total_rows ;
int total_cols ;

long long fastpow ( long long x , long long n ) {
    long long ret = 1 ;
    while ( n > 0 ) {
        if ( ( n & 1 ) == 0 ) {
            x = ( x * x ) % MOD ;
            n >>= 1 ;
        }
        else {
            ret = ( ret * x ) % MOD ;
            -- n ;
        }
    }
    return ret ;
}

long long f ( long long n , long long k ) {
    if ( n < k ) { return 0 ; }
    long long ret = fac[ n ] ;
    ret = ( ret * inv[ n - k ] ) % MOD ;
    return ret ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    int k ;
    scanf ( "%d" , &k ) ;
    while ( k -- ) {
        int aux1 , aux2 , aux3 , aux4 ;
        scanf ( "%d%d%d%d" , &aux1 , &aux2 , &aux3 , &aux4 ) ;
        if ( aux1 != aux3 ) {
            ++ r[ aux1 ] ;
            ++ r[ aux3 ] ;
            ++ c[ aux2 ] ;
        }
        else {
            ++ r[ aux1 ] ;
            ++ c[ aux2 ] ;
            ++ c[ aux4 ] ;
        }
    }
}

void solve ( ) {
    fac[ 0 ] = 1 ;
    for ( int i = 1 ; i < MAXN ; ++ i ) {
        fac[ i ] = ( fac[ i - 1 ] * i ) % MOD ;
    }
    inv[ MAXN - 1 ] = fastpow ( fac[ MAXN - 1 ] , MOD - 2 ) ;
    for ( int i = MAXN - 2 ; i >= 0 ; -- i ) {
        inv[ i ] = ( inv[ i + 1 ] * ( i + 1 ) ) % MOD ;
    }

    dp_r[ 0 ][ 0 ] = dp_c[ 0 ][ 0 ] = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        total_rows += ( 1 ^ r[ i ] ) ;
        for ( int j = 0 ; j <= n ; ++ j ) {
            dp_r[ i ][ j ] = dp_r[ i - 1 ][ j ] ;
            if ( j > 0 ) {
                if ( i >= 2 && ( r[ i ] | r[ i - 1 ] ) == 0 ) {
                    dp_r[ i ][ j ] += dp_r[ i - 2 ][ j - 1 ] ;
                    if ( dp_r[ i ][ j ] >= MOD ) { dp_r[ i ][ j ] -= MOD ; }
                }
            }
        }
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        total_cols += ( 1 ^ c[ i ] ) ;
        for ( int j = 0 ; j <= m ; ++ j ) {
            dp_c[ i ][ j ] = dp_c[ i - 1 ][ j ] ;
            if ( j > 0 ) {
                if ( i >= 2 && ( c[ i ] | c[ i - 1 ] ) == 0 ) {
                    dp_c[ i ][ j ] += dp_c[ i - 2 ][ j - 1 ] ;
                    if ( dp_c[ i ][ j ] >= MOD ) { dp_c[ i ][ j ] -= MOD ; }
                }
            }
        }
    }
    long long ans = 0 ;
    for ( int i = 0 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j <= m ; ++ j ) {
            if ( dp_r[ n ][ i ] > 0 && dp_c[ m ][ j ] > 0 ) {
                int lft_r = total_rows - 2 * i ;
                int lft_c = total_cols - 2 * j ;
                long long aux = ( dp_r[ n ][ i ] * dp_c[ m ][ j ] ) % MOD ;
                aux = ( aux * f ( lft_r , j ) ) % MOD ;
                aux = ( aux * f ( lft_c , i ) ) % MOD ;
                ans += aux ;
                if ( ans >= MOD ) { ans -= MOD ; }
            }
        }
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
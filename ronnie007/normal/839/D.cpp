#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
using namespace std ;

#define MOD 1000000007

#define MAXN 1000007
#define LIM 1000000

int n ;
int a[ MAXN ] ;
vector < int > divs[ MAXN ] ;

int sm[ MAXN ] ;

long long fac[ MAXN ] ;
long long inv[ MAXN ] ;
int br[ MAXN ] ;

int u[ MAXN ] ;
bool pr[ MAXN ] ;

long long f[ MAXN ] ;

long long fpow ( long long a , long long x ) {
    long long ret = 1 ;
    while ( x != 0 ) {
        if ( ( x % 2 ) == 1 ) {
            ret = ( ret * a ) % MOD ;
            x -- ;
        }
        else {
            a = ( a * a ) % MOD ;
            x /= 2 ;
        }
    }
    return ret ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        br[ a[ i ] ] ++ ;
    }
}

void solve ( ) {
    int i , j ;
    for ( i = 2 ; i <= LIM ; i ++ ) {
        for ( j = i ; j <= LIM ; j += i ) {
            if ( i != j ) {
                pr[ j ] = false ;
                if ( pr[ i ] == true ) {
                    sm[ j ] = ( sm[ j ] + ( j / i ) ) % MOD ;
                }
            }
            u[ i ] += br[ j ] ;
        }
    }
    fac[ 0 ] = 1 ;
    inv[ 0 ] = 1 ;
    for ( i = 1 ; i <= LIM ; i ++ ) {
        fac[ i ] = ( fac[ i - 1 ] * i ) % MOD ;
        inv[ i ] = fpow ( fac[ i ] , MOD - 2 ) ;
    }
    long long ans = 0 ;
    for ( i = 2 ; i <= LIM ; i ++ ) {
        if ( u[ i ] == 0 ) { continue ; }
        for ( j = 1 ; j <= u[ i ] ; j ++ ) {
            long long cur = ( fac[ u[ i ] ] * inv[ j ] ) % MOD ;
            cur = ( cur * inv[ u[ i ] - j ] ) % MOD ;
            cur = ( cur * j ) % MOD ;
            ///cur = ( cur * ( i - sm[ i ] ) ) % MOD ;
            if ( cur < 0 ) { cur += MOD ; }
            f[ i ] = ( f[ i ] + cur ) % MOD ;
        }
    }
    for ( i = LIM ; i >= 2 ; i -- ) {
        long long lst = 0 ;
        int id = 0 ;
        for ( j = 2 * i ; j <= LIM ; j += i ) {
            f[ i ] = ( f[ i ] - f[ j ] + MOD ) % MOD ;
        }
        long long cur = ( f[ i ] * i ) % MOD ;
        ans = ( ans + cur ) % MOD ;
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    //ios::sync_with_stdio ( false ) ;
    //cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
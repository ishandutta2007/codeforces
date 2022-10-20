#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
using namespace std ;

#define MAXN 2007
#define MOD 1000000007

int n , m , k ;

long long f[ MAXN ][ MAXN ] ;
long long pref[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &k ) ;
}

void solve ( ) {
    int i , j ;
    f[ 0 ][ 0 ] = 0 ;
    for ( i = 1 ; i <= 1000 ; i ++ ) {
        f[ i ][ 0 ] = 1 ;
        pref[ i ] = 1 ;
        if ( i != 0 ) { pref[ i ] += pref[ i - 1 ] ; }
    }
    for ( j = 1 ; j <= 1000 ; j ++ ) {
        long long cur = 0 ;
        for ( i = 2 * j + 1 ; i <= 1000 ; i ++ ) {
            cur += pref[ i - 2 ] ;
            cur %= MOD ;
            f[ i ][ j ] = cur ;
        }
        pref[ 0 ] = 0 ;
        for ( i = 1 ; i <= 1000 ; i ++ ) {
            pref[ i ] = f[ i ][ j ] + pref[ i - 1 ] ;
            pref[ i ] %= MOD ;
        }
    }
    long long ans = f[ n ][ k ] * f[ m ][ k ] ;
    ans %= MOD ;
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
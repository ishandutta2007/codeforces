#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
using namespace std ;

#define MAXN 200007
#define MOD 998244353

int n ;

long long ans[ MAXN ] ;
long long fac[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
}

void solve ( ) {
    fac[ 0 ] = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        fac[ i ] = ( fac[ i - 1 ] * 10 ) % MOD ;
    }
    ans[ n ] = 10 ;
    for ( int i = 1 ; i < n ; ++ i ) {
        long long aux = 20LL * 9 * fac[ n - i - 1 ] ;
        ans[ i ] = ( ans[ i ] + aux ) % MOD ;
    }
    for ( int i = 1 ; i <= n - 2 ; ++ i ) {
        long long aux = 10LL * 9 * 9 * ( n - i - 1 ) ;
        aux = ( aux * fac[ n - i - 2 ] ) % MOD ;
        ans[ i ] = ( ans[ i ] + aux ) % MOD ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        printf ( "%I64d " , ans[ i ] ) ;
    }
    printf ( "\n" ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
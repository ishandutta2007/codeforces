#include<iostream>
#include<stdio.h>
using namespace std ;


#define MOD 1000000007

string a ;
int k ;

long long fastpow ( int y , int x ) {
    long long r = 1 ;
    long long b = y ;
    while ( x != 0 ) {
        if ( x % 2 == 0 ) {
            b = b * b ;
            b %= MOD ;
            x /= 2 ;
        }
        else {
            r = r * b ;
            r %= MOD ;
            x -- ;
        }
    }
    r %= MOD ;
    return r ;
}


int main ( ) {
    cin >> a ;
    cin >> k ;
    int i ;
    int n = a.size ( ) ;
    long long q = fastpow( 2 , n ) ;

    long long x = ( fastpow( q , k ) + MOD - 1 ) % MOD ;
    long long y = ( q + MOD - 1 ) % MOD ;
    y = fastpow ( y , MOD - 2 ) % MOD ;

    long long sum = ( x * y ) % MOD ;
    long long ans = 0 ;
    long long ret ;
    for ( i = 0 ; i < n ; i ++ ) {
        if ( a[ i ] == '0' || a[ i ] == '5' ) {
            ret = ( sum * fastpow ( 2 , i ) ) % MOD ;
            ans += ret ;
            ans %= MOD ;
        }
    }
    cout << ans << "\n" ;
}
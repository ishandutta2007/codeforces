#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
using namespace std ;

#define MOD 1000000007

int n ;
string a ;

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    int i ;
    int br = 0 ;
    long long cur = 1 ;
    long long ans = 0 ;
    for ( i = 0 ; i < n ; i ++ ) {
        if ( a[ i ] == 'a' ) {
            br ++ ;
            cur *= 2 ;
            cur %= MOD ;
        }
        else {
            ans += ( cur - 1 + MOD ) % MOD ;
            ans %= MOD ;
        }
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
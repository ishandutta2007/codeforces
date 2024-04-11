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

#define MAXN 250007

long long n , MOD ;
long long fac[ MAXN ] ;

void input ( ) {
    cin >> n >> MOD ;
}

void solve ( ) {
    fac[ 0 ] = 1 ;
    for ( long long i = 1 ; i <= n ; ++ i ) {
        fac[ i ] = ( fac[ i - 1 ] * i ) % MOD ;
    }
    long long ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        long long aux = 0 ;
        aux = ( fac[ i ] * ( n - i + 1 ) ) % MOD ;
        aux = ( aux * ( n - i + 1 ) ) % MOD ;
        aux = ( aux * fac[ n - i ] ) % MOD ;
        ans = ( ans + aux ) % MOD ;
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
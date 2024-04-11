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

#define MAXN 2007
#define MOD 998244353

long long n , m , k ;

long long dp[ MAXN ][ MAXN ] ;

void input ( ) {
    cin >> n >> m >> k ;
}

void solve ( ) {
    int i , j ;
    dp[ 1 ][ 0 ] = m ;
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 0 ; j < i ; j ++ ) {
            dp[ i + 1 ][ j ] = ( dp[ i + 1 ][ j ] + dp[ i ][ j ] ) % MOD ;
            dp[ i + 1 ][ j + 1 ] = ( dp[ i + 1 ][ j + 1 ] + dp[ i ][ j ] * ( m - 1 ) ) % MOD ;
        }
    }
    cout << dp[ n ][ k ] << "\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
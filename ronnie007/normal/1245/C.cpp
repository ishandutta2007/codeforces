#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std ;

#define MOD 1000000007
#define MAXN 100007

long long dp[ MAXN ] ;

int n ;
string a ;


void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    int cnt = 1 ;
    long long ans = 1 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( a[ i ] == 'w' || a[ i ] == 'm' ) { ans = 0 ; }
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        if ( a[ i ] == a[ i - 1 ] ) { ++ cnt ; }
        else {
            if ( a[ i - 1 ] != 'u' && a[ i - 1 ] != 'n' ) { cnt = 1 ; }
            ans = ( ans * dp[ cnt ] ) % MOD ;
            cnt = 1 ;
        }
    }
    if ( a[ n - 1 ] != 'u' && a[ n - 1 ] != 'n' ) { cnt = 1 ; }
    ans = ( ans * dp[ cnt ] ) % MOD ;
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    dp[ 0 ] = dp[ 1 ] = 1 ;
    for ( int i = 2 ; i < MAXN ; ++ i ) {
        dp[ i ] = ( dp[ i - 1 ] + dp[ i - 2 ] ) % MOD ;

    }
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
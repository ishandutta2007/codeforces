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

long long lim , MOD ;
long long dp[ 37 ][ 37 ] ;
long long pw[ 37 ] ;


void input ( ) {
    cin >> lim >> MOD ;
}

void solve ( ) {
    for ( int i = 0 ; i <= 33 ; ++ i ) {
        for ( int j = 0 ; j <= 33 ; ++ j ) {
            dp[ i ][ j ] = 0 ;
        }
    }
    dp[ 0 ][ 0 ] = 1 ;
    for ( int i = 1 ; i <= 33 ; ++ i ) {
        if ( pw[ i - 1 ] > lim ) { continue ; }
        for ( int j = 1 ; j <= 33 ; ++ j ) {
            for ( int lst = 0 ; lst < i ; ++ lst ) {
                if ( dp[ lst ][ j - 1 ] == 0 ) { continue ; }
                long long ways = min ( pw[ i - 1 ] , lim - pw[ i - 1 ] + 1 ) ;
                dp[ i ][ j ] += ( dp[ lst ][ j - 1 ] * ways ) % MOD ;
                dp[ i ][ j ] %= MOD ;
            }
        }
    }
    long long ans = 0 ;
    for ( int i = 1 ; i <= 33 ; ++ i ) {
        for ( int j = 1 ; j <= 33 ; ++ j ) {
            ans += dp[ i ][ j ] ;
            ans %= MOD ;
        }
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    pw[ 0 ] = 1 ;
    for ( int i = 1 ; i <= 33 ; ++ i ) {
        pw[ i ] = ( pw[ i - 1 ] * 2 ) ;
    }
    int t ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
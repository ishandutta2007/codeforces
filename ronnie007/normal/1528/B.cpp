#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007
#define MOD 998244353

int n ;
long long dp[ MAXN ] ;
int divs[ MAXN ] ;


void input ( ) {
    scanf ( "%d" , &n ) ;
}

void solve ( ) {
    long long pref = 1 ;
    dp[ 0 ] = dp[ 1 ] = 1 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        for ( int j = i ; j <= n ; j += i ) {
            ++ divs[ j ] ;
        }
        dp[ i ] = ( 1 + divs[ i ] + pref ) % MOD ;
        pref = ( pref + dp[ i ] ) % MOD ;
    }
    printf ( "%lld\n" , dp[ n ] ) ;
}

int main ( ) {
    //freopen ( "dictionary.in" , "r" , stdin ) ;
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
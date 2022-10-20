#include<bits/stdc++.h>
using namespace std ;

#define MAXN 4000007

int n ;
long long MOD ;

long long dp[ MAXN ] ;
long long add[ MAXN ] ;

void upd ( int i ) {
    for ( int z = 2 ; i * z <= n ; ++ z ) {
        add[ i * z ] = ( add[ i * z ] + dp[ i ] ) % MOD ;
        if ( ( i + 1 ) * z <= n ) {
            add[ ( i + 1 ) * z ] = ( add[ ( i + 1 ) * z ] - dp[ i ] + MOD ) % MOD ;
        }
    }
}

void input ( ) {
    cin >> n >> MOD ;
}

void solve ( ) {
    long long pref = 1 ;
    dp[ 1 ] = 1 ;
    upd ( 1 ) ;
    long long sm = 0 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        sm = ( sm + add[ i ] ) % MOD ;
        dp[ i ] = ( sm + pref ) % MOD ;
        upd ( i ) ;
        pref = ( pref + dp[ i ] ) % MOD ;
    }
    cout << dp[ n ] << "\n" ;
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
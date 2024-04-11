#include<bits/stdc++.h>
using namespace std ;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 200007
#define MOD 998244353

int n ;
int a[ MAXN ] ;

long long dp[ MAXN ][ 2 ] ;
long long pref[ MAXN ][ 2 ] ;

long long aux[ MAXN ][ 2 ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    stack < int > s ;
    dp[ 0 ][ 0 ] = pref[ 0 ][ 0 ] = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        while ( s.empty ( ) == false && a[ s.top ( ) ] >= a[ i ] ) {
            s.pop ( ) ;
        }
        int lst = 0 ;
        if ( s.empty ( ) == false ) {
            lst = s.top ( ) ;
        }
        long long x = pref[ i - 1 ][ 1 ] ;
        if ( lst > 0 ) { x = ( x - pref[ lst - 1 ][ 1 ] + MOD ) % MOD ; }
        
        long long y = pref[ i - 1 ][ 0 ] ;
        if ( lst > 0 ) { y = ( y - pref[ lst - 1 ][ 0 ] + MOD ) % MOD ; }

        dp[ i ][ 0 ] = ( aux[ lst ][ 0 ] + ( x * a[ i ] ) ) % MOD ;
        dp[ i ][ 1 ] = ( aux[ lst ][ 1 ] + ( y * a[ i ] ) ) % MOD ;
        
        pref[ i ][ 0 ] = ( pref[ i - 1 ][ 0 ] + dp[ i ][ 0 ] ) % MOD ;
        pref[ i ][ 1 ] = ( pref[ i - 1 ][ 1 ] + dp[ i ][ 1 ] ) % MOD ;

        aux[ i ][ 0 ] = ( aux[ lst ][ 0 ] + ( x * a[ i ] ) ) % MOD ;
        aux[ i ][ 1 ] = ( aux[ lst ][ 1 ] + ( y * a[ i ] ) ) % MOD ;

        s.push ( i ) ;
    }
    if ( ( n % 2 ) == 1 ) {
        cout << ( dp[ n ][ 1 ] - dp[ n ][ 0 ] + MOD ) % MOD << "\n" ;
    }
    else {
        cout << ( dp[ n ][ 0 ] - dp[ n ][ 1 ] + MOD ) % MOD << "\n" ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
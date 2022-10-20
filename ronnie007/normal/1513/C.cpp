#include<bits/stdc++.h>
using namespace std ;

#define MOD 1000000007

#define MAXN 200007

int dp[ MAXN ][ 11 ] ;

void init ( ) {
    for ( int i = 0 ; i < 10 ; ++ i ) {
        dp[ 0 ][ i ] = 1 ;
    }
    for ( int i = 1 ; i < MAXN ; ++ i ) {
        for ( int j = 0 ; j < 9 ; ++ j ) {
            dp[ i ][ j ] = dp[ i - 1 ][ j + 1 ] ;
        }
        dp[ i ][ 9 ] = dp[ i - 1 ][ 0 ] + dp[ i - 1 ][ 1 ] ;
        dp[ i ][ 9 ] %= MOD ;
    }
}

string s ;
int k ;

void input ( ) {
    cin >> s >> k ;
}

void solve ( ) {
    int n = s.size ( ) ;
    int ans = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        int val = ( s[ i ] - '0' ) ;
        ans += dp[ k ][ val ] ;
        if ( ans >= MOD ) { ans -= MOD ; }
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    // scanf ( "%d" , &t ) ;
    init ( ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
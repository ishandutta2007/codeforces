#include<bits/stdc++.h>
using namespace std ;

#define MOD 1000000007
#define MAXN 1007

int n , m ;
string a[ MAXN ] ;

long long mask[ MAXN ] ;
long long dp[ MAXN ][ MAXN ] ;
long long hh[ MAXN ] ;

void input ( ) {
    cin >> m >> n ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> a[ i ] ;
        for ( int j = 0 ; j < m ; ++ j ) {
            if ( a[ i ][ j ] == '1' ) {
                mask[ j ] += (1LL<<i) ;
            }
        }
    }
}

void solve ( ) {
    dp[ 0 ][ 0 ] = 1 ;
    for ( int i = 0 ; i < m ; ++ i ) {
        for ( int j = 0 ; j <= i ; ++ j ) {
            dp[ i + 1 ][ j + 1 ] = ( dp[ i + 1 ][ j + 1 ] + dp[ i ][ j ] ) % MOD ;
            dp[ i + 1 ][ j ] = ( dp[ i + 1 ][ j ] + ( dp[ i ][ j ] * j ) % MOD ) % MOD ;
        }
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        for ( int j = 1 ; j <= i ; ++ j ) {
            hh[ i ] = ( hh[ i ] + dp[ i ][ j ] ) % MOD ;
        }
    }
    sort ( mask , mask + m ) ;
    long long ans = 1 ;
    int len = 1 ;
    for ( int i = 1 ; i < m ; ++ i ) {
        if ( mask[ i ] == mask[ i - 1 ] ) { ++ len ; }
        else {
            ans = ( ans * hh[ len ] ) % MOD ;
            len = 1 ;
        }
    }
    ans = ( ans * hh[ len ] ) % MOD ;
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
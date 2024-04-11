#include<bits/stdc++.h>
using namespace std ;

#define MAXN 5007
#define MOD 998244353


int n ;
int a[ MAXN ] ;
int cnt[ MAXN ] ;

long long dp[ 2 ][ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    int pos = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        while ( pos < n && a[ pos + 1 ] * 2 <= a[ i ] ) { ++ pos ; }
        cnt[ i ] = pos ;
    }
}

void solve ( ) {
    int prv = 0 , nxt = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        dp[ prv ][ i ] = 1 ;
        dp[ nxt ][ i ] = 0 ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            dp[ nxt ][ j ] += ( dp[ prv ][ j ] * ( cnt[ j ] - i + 1 ) ) % MOD ;
            if ( dp[ nxt ][ j ] >= MOD ) { dp[ nxt ][ j ] -= MOD ; }
        }
        long long sm = 0 ;
        int pos = 0 ;
        for ( int j = 1 ; j <= n ; ++ j ) {
            while ( pos < n && a[ pos + 1 ] * 2 <= a[ j ] ) {
                ++ pos ;
                sm = sm + dp[ prv ][ pos ] ;
                if ( sm >= MOD ) { sm -= MOD ; }
            }
            dp[ nxt ][ j ] += sm ;
            if ( dp[ nxt ][ j ] >= MOD ) { dp[ nxt ][ j ] -= MOD ; }
        }
        for ( int j = 1 ; j <= n ; ++ j ) {
            dp[ prv ][ j ] = 0 ;
        }
        prv ^= 1 ; nxt ^= 1 ;
    }
    long long ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        ans += dp[ prv ][ i ] ;
        if ( ans >= MOD ) { ans -= MOD ; }
    }
    printf ( "%lld\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 100007
#define MOD 998244353


int n , m ;
int l[ 52 ] , r[ 52 ] ;
long long dp[ 2 ][ MAXN ] ;

long long ans[ MAXN ] ;

long long f ( int x ) {
    int lim = ( m / x ) ;
    int prv = 0 , nxt = 1 ;
    for ( int i = 0 ; i <= lim ; ++ i ) {
        dp[ prv ][ i ] = 0 ;
    }
    dp[ prv ][ 0 ] = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        long long aux = 0 ;
        int mn = ( l[ i ] + x - 1 ) / x ;
        int mx = r[ i ] / x ;
        for ( int j = 0 ; j <= lim ; ++ j ) {
            if ( j - mn >= 0 ) {
                aux = ( aux + dp[ prv ][ j - mn ] ) % MOD ;
            }
            
            dp[ nxt ][ j ] = aux ;
            
            if ( j - mx >= 0 ) {
                aux = ( aux - dp[ prv ][ j - mx ] + MOD ) % MOD ;
            }
        }
        prv ^= 1 , nxt ^= 1 ;
    }
    long long ret = 0 ;
    for ( int i = 0 ; i <= lim ; ++ i ) {
        ret = ( ret + dp[ prv ][ i ] ) % MOD ;
    }
    return ret ;
}

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> l[ i ] >> r[ i ] ;
    }
}

void solve ( ) {
    for ( int i = MAXN - 1 ; i >= 1 ; -- i ) {
        ans[ i ] = f ( i ) ;
        for ( int j = 2 * i ; j < MAXN ; j += i ) {
            ans[ i ] = ( ans[ i ] + MOD - ans[ j ] ) % MOD ;
        }
    }
    cout << ans[ 1 ] << "\n" ;
}

int main ( ) {
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
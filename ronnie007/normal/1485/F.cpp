#include<bits/stdc++.h>
using namespace std ;

#define MOD 1000000007
#define MAXN 200007

int n ;
long long b[ MAXN ] ;

long long dp[ MAXN ] ;
long long nonzero[ MAXN ] ;

map < long long , long long > w ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> b[ i ] ;
    }
}

void solve ( ) {
    dp[ 0 ] = 1 ;
    nonzero[ 0 ] = 0 ;
    
    long long offset = 0 ;
    w.clear ( ) ;
    w[ 0 ] = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        dp[ i ] = ( dp[ i - 1 ] + nonzero[ i - 1 ] ) % MOD ;

        w[ offset ] += nonzero[ i - 1 ] ;
        w[ offset ] %= MOD ;        

        offset += b[ i ] ;
        nonzero[ i ] = ( dp[ i ] - w[ offset ] + MOD ) % MOD ;
        
    }
    cout << dp[ n ] << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // cin >> t ;
    // t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
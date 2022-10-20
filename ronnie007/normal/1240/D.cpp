#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 300007

int n ;
int a[ MAXN ] ;
map < int , int > w[ MAXN ] ;
int wh[ MAXN ] ;
int dp[ MAXN ] ;

long long ans = 0 ;


void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        w[ i ].clear ( ) ;
        dp[ i ] = 0 ;
        wh[ i ] = i ;
    }
    w[ 0 ].clear ( ) ;
}

void solve ( ) {
    ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int x = a[ i ] ;
        if ( w[ wh[ i - 1 ] ][ x ] != 0 ) {
            int pos = w[ wh[ i - 1 ] ][ x ] ;
            dp[ i ] = dp[ pos - 1 ] + 1 ;
            ans += dp[ i ] ;

            wh[ i ] = wh[ pos - 1 ] ;
        }
        w[ wh[ i ] ][ x ] = i ;
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
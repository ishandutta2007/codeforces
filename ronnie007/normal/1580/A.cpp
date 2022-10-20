#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 407
#define inf 1000000007


int n , m ;
string a[ MAXN ] ;
int pref[ MAXN ][ MAXN ] ;
int hh[ MAXN ] ;

int get ( int lx , int ly , int hx , int hy ) {
    return pref[ hx ][ hy ] - pref[ lx - 1 ][ hy ] - pref[ hx ][ ly - 1 ] + pref[ lx - 1 ][ ly - 1 ] ;
}

void input ( ) {
    cin >> n >> m ;
    a[ 0 ].clear ( ) ;
    for ( int i = 0 ; i <= m ; ++ i ) {
        a[ 0 ] += '#' ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        a[ i ] = '#' + a[ i ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            pref[ i ][ j ] = ( a[ i ][ j ] - '0' ) + pref[ i - 1 ][ j ] + pref[ i ][ j - 1 ] - pref[ i - 1 ][ j - 1 ] ;
        }
    }
}

void solve ( ) {
    int ans = inf ;
    for ( int l = 1 ; l <= m ; ++ l ) {
        for ( int r = l + 3 ; r <= m ; ++ r ) {
            hh[ 0 ] = 0 ;
            for ( int i = 1 ; i <= n ; ++ i ) {
                hh[ i ] = hh[ i - 1 ] ;
                hh[ i ] += get ( i , l + 1 , i , r - 1 ) ;
                if ( a[ i ][ l ] == '0' ) { ++ hh[ i ] ; }
                if ( a[ i ][ r ] == '0' ) { ++ hh[ i ] ; }
            }
            int mx = -inf ;
            for ( int en = 5 ; en <= n ; ++ en ) {
                int st = en - 4 ;
                int aux = hh[ st ] - ( ( r - l - 1 ) - get ( st , l + 1 , st , r - 1 ) ) ;
                mx = max ( mx , aux ) ;
                ans = min ( ans , hh[ en - 1 ] - mx + ( ( r - l - 1 ) - get ( en , l + 1 , en , r - 1 ) ) ) ;
            }
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    cin >> t ;
    // t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
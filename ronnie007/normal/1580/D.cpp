#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 4007

int n , m ;
int a[ MAXN ] ;

int mn[ MAXN ][ MAXN ] ;
long long dp[ MAXN ][ MAXN ] ;

void f ( int l , int r ) {
    if ( l >= r ) { return ; }
    int wh = mn[ l ][ r ] ;
    f ( l , wh - 1 ) ;
    f ( wh + 1 , r ) ;
    int tp = 0 ;
    for ( int x = 0 ; x <= wh - l ; ++ x ) {
        for ( int y = 0 ; y <= r - wh ; ++ y ) {
            long long aux = 0 ;
            aux += dp[ mn[ l ][ wh - 1 ] ][ x ] ;
            if ( l <= wh - 1 ) {
                aux += 1LL * ( a[ mn[ l ][ wh - 1 ] ] - a[ mn[ l ][ r ] ] ) * x * ( m - x ) ;
            }
            aux += dp[ mn[ wh + 1 ][ r ] ][ y ] ;
            if ( wh + 1 <= r ) {
                aux += 1LL * ( a[ mn[ wh + 1 ][ r ] ] - a[ mn[ l ][ r ] ] ) * y * ( m - y ) ;
            }
            dp[ wh ][ x + y ] = max ( dp[ wh ][ x + y ] , aux ) ;
        }
    }
    for ( int i = r - l + 1 ; i >= 1 ; -- i ) {
        dp[ wh ][ i ] = max ( dp[ wh ][ i ] , dp[ wh ][ i - 1 ] ) ;
    }
}

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        mn[ i ][ i ] = i ;
        for ( int j = i + 1 ; j <= n ; ++ j ) {
            mn[ i ][ j ] = mn[ i ][ j - 1 ] ;
            if ( a[ j ] < a[ mn[ i ][ j ] ] ) {
                mn[ i ][ j ] = j ;
            }
        }
    }
}   

void solve ( ) {
    f ( 1 , n ) ;
    cout << dp[ mn[ 1 ][ n ] ][ m ] << "\n" ;
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
#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 200007

int n ;
int a[ MAXN ] ;
vector < int > v[ MAXN ] ;

int dp[ MAXN ][ 2 ] ;
int mx[ MAXN ][ 2 ] ;
int ans ;

void dfs ( int vertex , int prv ) {
    dp[ vertex ][ 0 ] = dp[ vertex ][ 1 ] = 0 ;
    mx[ vertex ][ 0 ] = mx[ vertex ][ 1 ] = 0 ;
    if ( a[ vertex ] == 1 ) { dp[ vertex ][ 0 ] = 1 ; }
    if ( a[ vertex ] == 2 ) { dp[ vertex ][ 1 ] = 1 ; }
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        dfs ( x , vertex ) ;
        for ( int j = 0 ; j < 2 ; ++ j ) {
            for ( int t = 0 ; t < 2 ; ++ t ) {
                int aux = mx[ vertex ][ j ] + dp[ x ][ t ] ;
                if ( j == t ) {
                    if ( a[ vertex ] == 0 || a[ vertex ] - 1 == j ) { -- aux ; }
                    else { ++ aux ; }
                }
                ans = max ( ans , aux ) ;
            }
        }
        if ( a[ vertex ] == 0 ) {
            dp[ vertex ][ 0 ] = max ( dp[ vertex ][ 0 ] , dp[ x ][ 0 ] ) ;
            dp[ vertex ][ 1 ] = max ( dp[ vertex ][ 1 ] , dp[ x ][ 1 ] ) ;
        }
        else if ( a[ vertex ] == 1 ) {
            dp[ vertex ][ 0 ] = max ( dp[ vertex ][ 0 ] , dp[ x ][ 0 ] ) ;
            dp[ vertex ][ 0 ] = max ( dp[ vertex ][ 0 ] , dp[ x ][ 1 ] + 1 ) ;
        }
        else {
            dp[ vertex ][ 1 ] = max ( dp[ vertex ][ 1 ] , dp[ x ][ 0 ] + 1 ) ;
            dp[ vertex ][ 1 ] = max ( dp[ vertex ][ 1 ] , dp[ x ][ 1 ] ) ;            
        }
        
        mx[ vertex ][ 0 ] = max ( mx[ vertex ][ 0 ] , dp[ x ][ 0 ] ) ;
        mx[ vertex ][ 1 ] = max ( mx[ vertex ][ 1 ] , dp[ x ][ 1 ] ) ;
    }
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        v[ i ].clear ( ) ;
        cin >> a[ i ] ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ; cin >> x >> y ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    ans = 0 ;
    dfs ( 1 , -1 ) ;
    cout << ( ans + 2 ) / 2 << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 1007
#define mxval 200007

int n , m , q ;
pair < int , int > a[ mxval ] ;

int dp[ MAXN ][ MAXN ] ;

struct query {
    int x , y ;
    int lim ;
    int id ;
    query ( ) { x = y = lim = id = 0 ; }
    query ( int _x , int _y , int _lim , int _id ) {
        x = _x , y = _y , lim = _lim , id = _id ;
    }
};
vector < query > v[ mxval ] ;

bool ans[ mxval ] ;

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &q ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
    }
    for ( int i = 1 ; i <= q ; ++ i ) {
        int l , r , x , y ; scanf ( "%d%d%d%d" , &l , &r , &x , &y ) ;
        v[ l ].push_back ( query ( x , y , r , i ) ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            dp[ i ][ j ] = mxval ;
        }
        dp[ i ][ i ] = 0 ; 
    }
    for ( int i = m ; i >= 1 ; -- i ) {
        dp[ a[ i ].first ][ a[ i ].second ] = dp[ a[ i ].second ][ a[ i ].first ] = i ;
        for ( int j = 1 ; j <= n ; ++ j ) {
            if ( j == a[ i ].first || j == a[ i ].second ) { continue ; }
            int sr = min ( dp[ a[ i ].first ][ j ] , dp[ a[ i ].second ][ j ] ) ;
            dp[ a[ i ].first ][ j ] = dp[ a[ i ].second ][ j ] = max ( i , sr ) ;
        }
        for ( auto [ x , y , lim , id ] : v[ i ] ) {
            if ( dp[ x ][ y ] <= lim ) { ans[ id ] = true ; }
        }
    }
    for ( int i = 1 ; i <= q ; ++ i ) {
        if ( ans[ i ] == true ) { printf ( "Yes\n" ) ; }
        else { printf ( "No\n" ) ; }
    }
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
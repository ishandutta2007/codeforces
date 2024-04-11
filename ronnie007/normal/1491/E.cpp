#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
pair < int , int > edge_list[ MAXN ] ;
vector < pair < int , int > > v[ MAXN ] ;

long long fib[ 37 ] ;

int subtree[ MAXN ] ;
bool ban[ MAXN ] ;
map < pair < int , int > , int > edge_map ;

pair < int , int > dfs ( int vertex , int prv , int tar1 , int tar2 ) {
    subtree[ vertex ] = 1 ;
    for ( auto [ x , id ] : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        if ( ban[ id ] == true ) { continue ; }
        auto ret = dfs ( x , vertex , tar1 , tar2 ) ;
        if ( ret.first > -1 ) { return ret ; }
        if ( subtree[ x ] == tar1 ) {
            return { x , vertex } ;
        }
        else if ( subtree[ x ] == tar2 ) {
            return { vertex , x } ;
        }
        subtree[ vertex ] += subtree[ x ] ;
    }
    return { -1 , -1 } ;
}

bool check ( int st , int k ) {
    if ( k <= 1 ) { return true ; }
    auto [ x , y ] = dfs ( st , -1 , fib[ k - 1 ] , fib[ k - 2 ] ) ;
    if ( x < 0 ) { return false ; }
    int edge_id = edge_map[ { x , y } ] ;
    ban[ edge_id ] = true ;
    return ( check ( x , k - 1 ) & check ( y , k - 2 ) ) ;
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        cin >> x >> y ;
        edge_map[ { x , y } ] = edge_map[ { y , x } ] = i ;
        v[ x ].push_back ( { y , i } ) ;
        v[ y ].push_back ( { x , i } ) ;
    }
    fib[ 0 ] = fib[ 1 ] = 1 ;
    for ( int i = 2 ; i <= 30 ; ++ i ) {
        fib[ i ] = fib[ i - 1 ] + fib[ i - 2 ] ;
    }
}

void solve ( ) {
    int k = -1 ;
    for ( int i = 0 ; i <= 30 ; ++ i ) {
        if ( fib[ i ] == n ) { k = i ; break ; }
    }
    if ( k == -1 ) {
        cout << "NO\n" ;
        return ;
    }
    if ( check ( 1 , k ) == true ) {
        cout << "YES\n" ;
    }
    else { cout << "NO\n" ; }
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
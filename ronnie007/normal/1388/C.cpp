#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , m ;
int cnt[ MAXN ] ;
long long h[ MAXN ] ;

vector < int > v[ MAXN ] ;

bool bad = false ;

long long subtree[ MAXN ] ;
long long happy[ MAXN ] ;
long long sad[ MAXN ] ;

void dfs ( int x , int prv ) {
    int sz = v[ x ].size ( ) ;
    subtree[ x ] = cnt[ x ] ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ x ][ i ] == prv ) { continue ; }
        dfs ( v[ x ][ i ] , x ) ;
        subtree[ x ] += subtree[ v[ x ][ i ] ] ;
    }
    sad[ x ] = ( subtree[ x ] - h[ x ] ) / 2 ;
    happy[ x ] = ( subtree[ x ] - sad[ x ] ) ;
    if ( happy[ x ] - sad[ x ] != h[ x ] ) { bad = true ; return ; }
    if ( happy[ x ] < 0 || sad[ x ] < 0 ) { bad = true ; return ; }
    
    long long total = subtree[ x ] - cnt[ x ] ;
    long long sr = happy[ x ] ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ x ][ i ] == prv ) { continue ; }
        sr -= happy[ v[ x ][ i ] ] ;
        total -= happy[ v[ x ][ i ] ] + sad[ v[ x ][ i ] ] ;
        if ( sr < 0 ) { bad = true ; return ; }
        if ( total < 0 ) { bad = true ; return ; }
    }
    if ( total != 0 ) { bad = true ; return ; }
}


void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> cnt[ i ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> h[ i ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        v[ i ].clear ( ) ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        cin >> x >> y ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    bad = false ;
    dfs ( 1 , -1 ) ;
    if ( bad == false ) { cout << "YES\n" ; }
    else { cout << "NO\n" ; }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
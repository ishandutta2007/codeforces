#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007

int n ;
int a[ MAXN ] ;
vector < int > g[ MAXN ] , v[ MAXN ] ;
int lvl[ MAXN ] , subtree[ MAXN ] ;
bool used[ MAXN ] ;
int tot ;


void dfs ( int vertex , int prv ) {
    subtree[ vertex ] = a[ vertex ] ;
    for ( auto x : g[ vertex ] ) {
        if ( x == prv ) { continue ; }
        lvl[ x ] = lvl[ vertex ] + 1 ;
        dfs ( x , vertex ) ;
        subtree[ vertex ] += subtree[ x ] ;
    }
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        tot += a[ i ] ;
    }
    for ( int i = 1 , x , y ; i < n ; ++ i ) {
        cin >> x >> y ;
        g[ x ].push_back ( y ) ;
        g[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    dfs ( 1 , -1 ) ;
    for ( int x = 1 ; x <= n ; ++ x ) {
        for ( auto y : g[ x ] ) {
            if ( a[ y ] == 1 ) {
                v[ y ].push_back ( x ) ;
                continue ;
            }
            if ( lvl[ x ] < lvl[ y ] ) {
                if ( subtree[ y ] >= 2 ) {
                    v[ y ].push_back ( x ) ;
                }
            }
            else {
                if ( tot - subtree[ x ] >= 2 ) {
                    v[ y ].push_back ( x ) ;
                }
            }
        }
    }
    queue < int > q ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ] == 1 ) { q.push ( i ) , used[ i ] = true ; }
    }
    while ( q.empty ( ) == false ) {
        int x = q.front ( ) ;
        q.pop ( ) ;
        for ( auto y : v[ x ] ) {
            if ( used[ y ] == false ) {
                q.push ( y ) , used[ y ] = true ;
            }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == true ) { cout << "1 " ; }
        else { cout << "0 " ; }
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    /// cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
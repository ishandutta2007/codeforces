#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n , m ;
struct edge {
    int type , x , y ;
};

edge a[ MAXN ] ;

vector < int > hh[ MAXN ] ;

int ori[ MAXN ] ;
int ans[ MAXN ] ;

bool bad = false ;

void dfs ( int vertex ) {
    for ( auto x : hh[ vertex ] ) {
        if ( bad == true ) { return ; }
        if ( ori[ x ] == 0 ) {
            ori[ x ] = 3 - ori[ vertex ] ;
            dfs ( x ) ;
        }
        else {
            if ( ori[ x ] != 3 - ori[ vertex ] ) {
                bad = true ;
                return ;
            }
        }
    }
}

vector < int > v[ MAXN ] ;
int indeg[ MAXN ] ;

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        cin >> a[ i ].type >> a[ i ].x >> a[ i ].y ;
        hh[ a[ i ].x ].push_back ( a[ i ].y ) ;
        hh[ a[ i ].y ].push_back ( a[ i ].x ) ;
    }
}

queue < int > q ;

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( ori[ i ] == 0 ) {
            ori[ i ] = 1 ;
            dfs ( i ) ;
        }
    }
    if ( bad == true ) {
        cout << "NO\n" ;
        return ;
    }
    /// 1 = <--
    /// 2 = --->
    /// irrelevant = <--- --->
    /// destined = ---> <---
    for ( int i = 1 ; i <= m ; ++ i ) {
        if ( ori[ a[ i ].x ] == 2 ) { swap ( a[ i ].x , a[ i ].y ) ; }
        if ( a[ i ].type == 1 ) {
            v[ a[ i ].x ].push_back ( a[ i ].y ) ;
            ++ indeg[ a[ i ].y ] ;
        }
        else {
            v[ a[ i ].y ].push_back ( a[ i ].x ) ;
            ++ indeg[ a[ i ].x ] ;
        }
    }
    int tp = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( indeg[ i ] == 0 ) {
            q.push ( i ) ;
        }
    }
    while ( q.empty ( ) == false ) {
        int vertex = q.front ( ) ;
        q.pop ( ) ;
        ans[ vertex ] = ++ tp ;
        for ( auto y : v[ vertex ] ) {
            -- indeg[ y ] ;
            if ( indeg[ y ] == 0 ) {
                q.push ( y ) ;
            }
        }
    }
    if ( tp != n ) {
        cout << "NO\n" ;
        return ;
    }
    cout << "YES\n" ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( ori[ i ] == 1 ) { cout << "L " ; }
        else { cout << "R " ; }

        cout << ans[ i ] << "\n" ;
    }
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
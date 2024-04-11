#include<bits/stdc++.h>
using namespace std ;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 100007

int n , m ;

struct edge {
    int x , y ;
    int cost ;
    edge ( ) { x = y = cost = 0 ; }
    edge ( int _x , int _y , int _cost ) {
        x = _x , y = _y , cost = _cost ;
    }
};

edge a[ 4 * MAXN ] ;
bool kill[ 4 * MAXN ] ;
int nxt[ 4 * MAXN ] ;
int ori[ 4 * MAXN ] ;
int par[ MAXN ] ;
bool used[ MAXN ] ;

vector < int > v[ MAXN ][ 4 ] ;

void dfs ( int vertex ) {
    used[ vertex ] = true ;
    for ( auto id : v[ vertex ][ 0 ] ) {
        int x = a[ id ].x + a[ id ].y - vertex ;

        if ( ori[ id ] == 0 ) {
            if ( vertex == a[ id ].x ) { ori[ id ] = 1 ; }
            else { ori[ id ] = 2 ; }
        }
        if ( used[ x ] == false ) {
            dfs ( x ) ;
        }
    }
}

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        cin >> a[ i ].x >> a[ i ].y >> a[ i ].cost ;
        v[ a[ i ].x ][ a[ i ].cost ].push_back ( i ) ;
        v[ a[ i ].y ][ a[ i ].cost ].push_back ( i ) ;
        if ( a[ i ].cost == 1 ) {
            par[ a[ i ].x ] ^= 1 , par[ a[ i ].y ] ^= 1 ;
        }
    }
}

queue < int > q ;
int sz[ MAXN ] ;

void solve ( ) {
    int tp = m ;
    for ( int type = 1 ; type <= 2 ; ++ type ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            sz[ i ] = v[ i ][ type ].size ( ) ;
            if ( sz[ i ] >= 2 ) {
                q.push ( i ) ;
            }
        }
        while ( q.empty ( ) == false ) {
            int x = q.front ( ) ;
            q.pop ( ) ;
            int fst = -1 , scd = -1 ;
            while ( v[ x ][ type ].size ( ) > 0 && scd == -1 ) {
                int hh = v[ x ][ type ].back ( ) ;
                v[ x ][ type ].pop_back ( ) ;
                if ( kill[ hh ] == true ) { continue ; }
                if ( fst == -1 ) { fst = hh ; }
                else { scd = hh ; }
            }
            if ( scd == -1 ) { continue ; }
            kill[ fst ] = kill[ scd ] = true ;
            if ( a[ fst ].x + a[ fst ].y == a[ scd ].x + a[ scd ].y ) {
                int hh = a[ fst ].x + a[ fst ].y - x ;
                if ( a[ fst ].y == hh ) { ori[ fst ] = 1 ; }
                else { ori[ fst ] = 2 ; }

                if ( a[ scd ].x == hh ) { ori[ scd ] = 1 ; }
                else { ori[ scd ] = 2 ; }
            }
            else {
                ++ tp ;
                nxt[ fst ] = nxt[ scd ] = tp ;
                int st = a[ fst ].x + a[ fst ].y - x , en = a[ scd ].x + a[ scd ].y - x ;
                a[ tp ] = edge ( st , en , type ) ;
                v[ st ][ type ].push_back ( tp ) ;
                v[ en ][ type ].push_back ( tp ) ;
            }
            sz[ x ] -= 2 ;
            if ( sz[ x ] >= 2 ) { q.push ( x ) ; }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int type = 1 ; type <= 2 ; ++ type ) {
            for ( auto x : v[ i ][ type ] ) {
                if ( kill[ x ] == true ) { continue ; }
                v[ i ][ 0 ].push_back ( x ) ;
            }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( v[ i ][ 0 ].size ( ) == 1 && used[ i ] == false ) {
            dfs ( i ) ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == false ) {
            dfs ( i ) ;
        }
    }
    for ( int i = tp ; i >= 1 ; -- i ) {
        if ( ori[ i ] != 0 ) { continue ; }
        int st , en ;
        if ( ori[ nxt[ i ] ] == 1 ) {
            st = a[ nxt[ i ] ].x , en = a[ nxt[ i ] ].y ;
        }
        else {
            st = a[ nxt[ i ] ].y , en = a[ nxt[ i ] ].x ;
        }

        if ( a[ i ].x == st || a[ i ].y == en ) {
            ori[ i ] = 1 ;
        }
        else { ori[ i ] = 2 ; }
    }
    int ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) { ans += par[ i ] ; }
    cout << ans << "\n" ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        cout << ori[ i ] ;
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    /// cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
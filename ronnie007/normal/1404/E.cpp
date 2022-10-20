#include<bits/stdc++.h>
using namespace std ;

#define MAXN 207

int n , m ;
string a[ MAXN ] ;

namespace flow {
    #define MAXN 201 * 201
    #define inf 1000000007
    int n ;
    int source ;
    int sink ;
    struct tuhla {
        int to ;
        int flow , cap ;
        int rev ;
        tuhla ( ) { to = flow = cap = rev = 0 ; }
        tuhla ( int _to , int _cap , int _rev ) {
            to = _to , cap = _cap , flow = 0 , rev = _rev ;
        }
    };
    vector < tuhla > v[ MAXN ] ;
    int sz[ MAXN ] ;
    int lvl[ MAXN ] ;
    int pos[ MAXN ] ;
    void add_edge ( int x , int y , int cap ) {
        v[ x ].push_back ( tuhla ( y , cap , sz[ y ] ) ) ;
        v[ y ].push_back ( tuhla ( x , 0 , sz[ x ] ) ) ;
        ++ sz[ x ] , ++ sz[ y ] ;
    }
    bool bfs ( int st ) {
        queue < int > q ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            lvl[ i ] = pos[ i ] = 0 ;
        }
        lvl[ st ] = 1 ;
        q.push ( st ) ;
        while ( !q.empty ( ) ) {
            int x = q.front ( ) ;
            q.pop ( ) ;
            for ( int i = 0 ; i < sz[ x ] ; ++ i ) {
                if ( lvl[ v[ x ][ i ].to ] == 0 && v[ x ][ i ].flow != v[ x ][ i ].cap ) {
                    lvl[ v[ x ][ i ].to ] = lvl[ x ] + 1 , q.push ( v[ x ][ i ].to ) ;
                }
            }
        }
        return ( lvl[ sink ] != 0 ) ;
    }
    int dfs ( int vertex , int curr ) {
        if ( curr == 0 || vertex == sink ) { return curr ; }
        for ( ; pos[ vertex ] < sz[ vertex ] ; ++ pos[ vertex ] ) {
            if ( lvl[ v[ vertex ][ pos[ vertex ] ].to ] == lvl[ vertex ] + 1 ) {
                int aux = dfs ( v[ vertex ][ pos[ vertex ] ].to , min ( curr , v[ vertex ][ pos[ vertex ] ].cap - v[ vertex ][ pos[ vertex ] ].flow ) ) ;
                v[ vertex ][ pos[ vertex ] ].flow += aux ;
                v[ v[ vertex ][ pos[ vertex ] ].to ][ v[ vertex ][ pos[ vertex ] ].rev ].flow -= aux ;
                if ( aux > 0 ) { return aux ; }
            }
        }
        return 0 ;
    }
    long long maxflow ( ) {
        long long maxflow = 0 ;
        while ( bfs ( source ) == true ) {
            while ( 1 ) {
                int flow = dfs ( source , inf ) ;
                if ( flow == 0 ) { break ; }
                maxflow += flow ;
            }
        }
        return maxflow ;
    }
}

int encode ( int x , int y ) {
    return ( x - 1 ) * m + y ;
}

void input ( ) {
    cin >> n >> m ;
    for ( int i = 0 ; i <= m ; ++ i ) {
        a[ 0 ] += '.' ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        a[ i ] = '.' + a[ i ] ;
    }
}

void solve ( ) {
    flow :: n = flow :: sink = n * m + 2 ;
    flow :: source = n * m + 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            if ( a[ i ][ j ] == '.' ) { continue ; }
            if ( a[ i - 1 ][ j ] == '.' ) {
                flow :: add_edge ( flow :: source , encode ( i , j ) , 1 ) ;
            }
            else {
                flow :: add_edge ( encode ( i - 1 , j ) , encode ( i , j ) , 1 ) ;
            }
            if ( a[ i ][ j - 1 ] == '.' ) {
                flow :: add_edge ( encode ( i , j ) , flow :: sink , 1 ) ;
            }
            else {
                flow :: add_edge ( encode ( i , j ) , encode ( i , j - 1 ) , 1 ) ;
            }
        }
    }
    cout << flow :: maxflow ( ) << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
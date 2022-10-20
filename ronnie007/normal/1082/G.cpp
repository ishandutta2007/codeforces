#include<bits/stdc++.h>
using namespace std ;

#define MAXN 3007
#define inf 2000000007

namespace flow {
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

int n , m ;
long long sm = 0 ;

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    flow :: source = n + m + 1 ;
    flow :: sink = n + m + 2 ;
    flow :: n = n + m + 2 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int x ;
        scanf ( "%d" , &x ) ;
        flow :: add_edge ( m + i , flow :: sink , x ) ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y , z ;
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        flow :: add_edge ( flow :: source , i , z ) ;
        flow :: add_edge ( i , m + x , inf ) ;
        flow :: add_edge ( i , m + y , inf ) ;
        sm += z ;
    }
}

void solve ( ) {
    printf ( "%I64d\n" , sm - flow :: maxflow ( ) ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
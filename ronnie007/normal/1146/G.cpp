#include<bits/stdc++.h>
using namespace std ;

#define MAXN 57
#define inf 1000000007

int n , h , m ;

struct tuhla {
    int l , r ;
    int x , c ;
};
tuhla a[ MAXN ] ;

namespace flow {
    #define MAXN 3007

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

void input ( ) {
    scanf ( "%d%d%d" , &n , &h , &m ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        scanf ( "%d%d%d%d" , &a[ i ].l , &a[ i ].r , &a[ i ].x , &a[ i ].c ) ;
    }
    flow :: n = n * ( h + 1 ) + m + 2 ;
    flow :: sink = flow :: n ;
    flow :: source = flow :: n - 1 ;
}

void solve ( ) {
    int en = n * ( h + 1 ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j <= h ; ++ j ) {
            if ( j == 0 ) {
                flow :: add_edge ( flow :: source , i * ( h + 1 ) + j + 1 , inf ) ;
            }
            if ( j > 0 ) {
                flow :: add_edge ( i * ( h + 1 ) + j + 1 , i * ( h + 1 ) + j , inf ) ;
            }
            if ( j < h ) {
                flow :: add_edge ( i * ( h + 1 ) + j + 1 , i * ( h + 1 ) + j + 2 , h * h - j * j ) ;
            }
            for ( int t = 1 ; t <= m ; ++ t ) {
                if ( i + 1 < a[ t ].l || a[ t ].r < i + 1 ) { continue ; }
                if ( j > a[ t ].x ) {
                    flow :: add_edge ( i * ( h + 1 ) + j + 1 , en + t , inf ) ;
                }
            }
        }
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        flow :: add_edge ( en + i , flow :: sink , a[ i ].c ) ;
    }
    printf ( "%d\n" , n * h * h - flow :: maxflow ( ) ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
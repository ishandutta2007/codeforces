#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1007
#define MAXM 30007

int n , m ;
int source , target ;

struct edge {
    int x , y ;
    int cost ;
    int id ;
};
edge a[ MAXM ] ;

int prv[ MAXN ] ;
int rnk[ MAXM ] ;

vector < pair < int , int > > v[ MAXN ] ;

vector < edge > b ;
vector < pair < int , int > > mst[ MAXN ] ;

int used[ MAXN ] ;
int lvl[ MAXN ] ;
int mnback[ MAXN ] ;
bool fl[ MAXN ] ;
int edge_val ;
int edge_id ;

int find ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    int y = find ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}

void unite ( edge aux ) {
    int k1 = find ( aux.x ) ;
    int k2 = find ( aux.y ) ;
    if ( k1 != k2 ) {
        b.push_back ( aux ) ;
        if ( rnk[ k1 ] >= rnk[ k2 ] ) {
            prv[ k2 ] = k1 ;
            rnk[ k1 ] += ( rnk[ k1 ] == rnk[ k2 ] ) ;
        }
        else {
            prv[ k1 ] = k2 ;
        }
    }
}

void dfs ( int vertex , int lst , int ignore ) {
    int sz = v[ vertex ].size ( ) ;
    used[ vertex ] = 1 ;
    mnback[ vertex ] = lvl[ vertex ] ;
    if ( vertex == target ) {
        fl[ vertex ] = true ;
    }
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ].first ;
        int id = v[ vertex ][ i ].second ;
        if ( id == lst || id == ignore ) { continue ; }
        if ( used[ h ] > 0 ) {
            mnback[ vertex ] = min ( mnback[ vertex ] , lvl[ h ] ) ;
        }
        else {
            lvl[ h ] = lvl[ vertex ] + 1 ;
            dfs ( h , id , ignore ) ;
            mnback[ vertex ] = min ( mnback[ vertex ] , mnback[ h ] ) ;
            if ( fl[ h ] == true ) { fl[ vertex ] = true ; }
            if ( mnback[ h ] == lvl[ h ] && fl[ h ] == true ) {
                if ( edge_id == 0 ) {
                    edge_id = id ;
                    edge_val = a[ id ].cost ;
                }
                if ( edge_val > a[ id ].cost ) {
                    edge_id = id ;
                    edge_val = a[ id ].cost ;
                }
            }
        }
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    scanf ( "%d%d" , &source , &target ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        prv[ i ] = -1 ;
        rnk[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        scanf ( "%d%d%d" , &a[ i ].x , &a[ i ].y , &a[ i ].cost ) ;
        a[ i ].id = i ;
        unite ( a[ i ] ) ;
        v[ a[ i ].x ].push_back ( { a[ i ].y , i } ) ;
        v[ a[ i ].y ].push_back ( { a[ i ].x , i } ) ;
    }
}

void solve ( ) {
    if ( find ( source ) != find ( target ) ) {
        printf ( "0\n0\n" ) ;
        return ;
    }
    int sz = b.size ( ) ;
    int ans = -1 ;
    vector < int > hh ; 
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( find ( b[ i ].x ) != find ( source ) ) { continue ; }
        for ( int j = 1 ; j <= n ; ++ j ) {
            used[ j ] = 0 ;
            mnback[ j ] = MAXN ;
            fl[ j ] = false ;
        }
        edge_id = edge_val = 0 ;
        dfs ( source , -1 , b[ i ].id ) ;
        if ( used[ target ] == 0 ) {
            if ( ans < 0 || ans > b[ i ].cost ) {
                ans = b[ i ].cost ;
                hh.clear ( ) ;
                hh.push_back ( b[ i ].id ) ;
            }
        }
        if ( edge_id > 0 ) {
            if ( ans < 0 || ans > b[ i ].cost + edge_val ) {
                ans = b[ i ].cost + edge_val ;
                hh.clear ( ) ;
                hh.push_back ( b[ i ].id ) ;
                hh.push_back ( edge_id ) ;
            }
        }
    }
    printf ( "%d\n" , ans ) ;
    if ( ans != -1 ) {
        sz = hh.size ( ) ;
        printf ( "%d\n" , sz ) ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            printf ( "%d " , hh[ i ] ) ;
        }
        printf ( "\n" ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
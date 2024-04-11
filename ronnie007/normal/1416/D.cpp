#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std ;

#define MAXN 500007

int n , m , q ;

int val[ MAXN ] ;

struct edge {
    int x , y ;
    int id ;
    int tm ;
};

edge e[ MAXN ] ;

bool cmp ( edge p1 , edge p2 ) {
    return ( p1.tm > p2.tm ) ;
}

vector < pair < int , int > > v[ MAXN ] ;

int prv[ MAXN ] ;
int prv_edge_val[ MAXN ] ;
int rnk[ MAXN ] ;

pair < int , int > query_list[ MAXN ] ;

int find ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    return find ( prv[ x ] ) ;
}

void UNITE ( edge aux ) {
    int k1 = find ( aux.x ) ;
    int k2 = find ( aux.y ) ;
    if ( k1 != k2 ) {
        if ( rnk[ k1 ] >= rnk[ k2 ] ) {
            rnk[ k1 ] += ( rnk[ k1 ] == rnk[ k2 ] ) ;
            prv[ k2 ] = k1 ;
            prv_edge_val[ k2 ] = aux.tm ;
            v[ k1 ].push_back ( { k2 , aux.tm } ) ;
        }
        else {
            prv[ k1 ] = k2 ;
            prv_edge_val[ k1 ] = aux.tm ;
            v[ k2 ].push_back ( { k1 , aux.tm } ) ;
        }
    }
}

int tpsz ;
int st[ MAXN ] ;
int en[ MAXN ] ;

void init_dfs ( int vertex ) {
    st[ vertex ] = ++ tpsz ;
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        init_dfs ( v[ vertex ][ i ].first ) ;
    }
    en[ vertex ] = tpsz ;
}

class Tree {
public :
    pair < int , int > tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = { 0 , 0 } ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }

    void update ( int where , int IL , int IR , int pos , int nw ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ] = { nw , IL } ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , nw ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , nw ) ;
        }
        tr[ where ] = max ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    pair < int , int > query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( CURL > CURR ) { return { 0 , 0 } ; }
        if ( IL > IR ) { return { 0 , 0 } ; }
        if ( CURR < IL || IR < CURL ) { return { 0 , 0 } ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return max ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};

Tree w ;

int obtain ( int x , int aux ) {
    while ( prv[ x ] != -1 && prv_edge_val[ x ] > aux ) {
        x = prv[ x ] ;
    }
    int l , r , mid ;
    l = 0 ;
    r = v[ x ].size ( ) - 1 ;
    while ( r - l > 3 ) {
        int mid = ( l + r ) / 2 ;
        if ( v[ x ][ mid ].second < aux ) { l = mid ; }
        else { r = mid ; }
    }
    pair < int , int > hh = w.query ( 1 , 1 , n , st[ x ] , st[ x ] ) ;
    while ( l < v[ x ].size ( ) && v[ x ][ l ].second < aux ) { ++ l ; }
    if ( l < v[ x ].size ( ) ) {
        hh = max ( hh , w.query ( 1 , 1 , n , st[ v[ x ][ l ].first ] , en[ x ] ) ) ;
    }
    if ( hh.first > 0 ) {
        w.update ( 1 , 1 , n , hh.second , 0 ) ;
    }
    return hh.first ;
}

void input ( ) {
    cin >> n >> m >> q ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> val[ i ] ;
        prv[ i ] = -1 ;
        rnk[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        cin >> e[ i ].x >> e[ i ].y ;
        e[ i ].id = i ;
        e[ i ].tm = q + 1 ;
    }
    for ( int i = 1 ; i <= q ; ++ i ) {
        cin >> query_list[ i ].first >> query_list[ i ].second ;
        if ( query_list[ i ].first == 2 ) {
            e[ query_list[ i ].second ].tm = i ;
        }
    }
    sort ( e + 1 , e + m + 1 , cmp ) ;
}

bool by_second ( pair < int , int > p1 , pair < int , int > p2 ) {
    return ( p1.second < p2.second ) ;
}

void solve ( ) {
    for ( int i = 1 ; i <= m ; ++ i ) {
        UNITE ( e[ i ] ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        sort ( v[ i ].begin ( ) , v[ i ].end ( ) , by_second ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( prv[ i ] == -1 ) {
            init_dfs ( i ) ;
        }
    }
    w.init ( 1 , 1 , n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        w.update ( 1 , 1 , n , st[ i ] , val[ i ] ) ;
    }
    for ( int i = 1 ; i <= q ; ++ i ) {
        if ( query_list[ i ].first == 1 ) {
            cout << obtain ( query_list[ i ].second , i ) << "\n" ;
        }
    }

}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
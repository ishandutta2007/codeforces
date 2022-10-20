#include<bits/stdc++.h>
using namespace std ;

#define MAXN 500007

int n ;
vector < pair < int , int > > v[ MAXN ] ;
pair < int , int > edge_list[ MAXN ] ;
int diam[ 2 ] ;


class Tree {
    int root ;
    vector < int > ord ;
    int st[ MAXN ] , en[ MAXN ] ;
    int rev[ MAXN ] ;
    int depth[ MAXN ] , parity[ MAXN ] ;
    void dfs ( int vertex , int prv ) {
        ord.push_back ( vertex ) ;
        st[ vertex ] = ord.size ( ) ;
        rev[ st[ vertex ] ] = vertex ;
        int sz = v[ vertex ].size ( ) ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            int to , cost ;
            to = v[ vertex ][ i ].first ;
            cost = v[ vertex ][ i ].second ;
            if ( to == prv ) { continue ; }
            depth[ to ] = depth[ vertex ] + 1 ;
            parity[ to ] = parity[ vertex ] ^ cost ;
            dfs ( to , vertex ) ;
        }
        en[ vertex ] = ord.size ( ) ;
    }
    int tr[ 4 * MAXN ][ 2 ] ;
    int lazy[ 4 * MAXN ] ;
    void unite ( int where ) {
        for ( int i = 0 ; i < 2 ; ++ i ) {
            tr[ where ][ i ] = max ( tr[ 2 * where ][ i ] , tr[ 2 * where + 1 ][ i ] ) ;
        }
    }
    void init_segtree ( int where , int IL , int IR ) {
        lazy[ where ] = 0 ;
        if ( IL == IR ) {
            int x = rev[ IL ] ;
            tr[ where ][ parity[ x ] ] = depth[ x ] ;
            tr[ where ][ parity[ x ] ^ 1 ] = 0 ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init_segtree ( 2 * where , IL , mid ) ;
        init_segtree ( 2 * where + 1 , mid + 1 , IR ) ;
        unite ( where ) ;
    }
    void push_lazy ( int where , int IL , int IR ) {
        if ( lazy[ where ] == 0 ) { return ; }
        swap ( tr[ where ][ 0 ] , tr[ where ][ 1 ] ) ;
        if ( IL != IR ) {
            lazy[ 2 * where ] ^= 1 ;
            lazy[ 2 * where + 1 ] ^= 1 ;
        }
        lazy[ where ] = 0 ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( IL > IR || CURL > CURR ) { return ; }
        if ( CURR < IL || IR < CURL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazy[ where ] ^= 1 ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
        unite ( where ) ;
    }
public :
    void init ( int _root ) {
        root = _root ;
        depth[ root ] = parity[ root ] = 0 ;
        ord.clear ( ) ;
        dfs ( root , -1 ) ;
        init_segtree ( 1 , 1 , n ) ;
    }
    void handle ( int id ) {
        int x = edge_list[ id ].first ;
        int y = edge_list[ id ].second ;
        if ( st[ x ] < st[ y ] ) { swap ( x , y ) ; }
        update ( 1 , 1 , n , st[ x ] , en[ x ] ) ;
    }
    int query ( ) { return tr[ 1 ][ 0 ] ; }
};
Tree w[ 2 ] ;

int len[ MAXN ] ;
int bfs ( int ori ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        len[ i ] = MAXN ;
    }
    len[ ori ] = 0 ;
    queue < int > q ;
    q.push ( ori ) ;
    while ( q.empty ( ) == false ) {
        int x = q.front ( ) ;
        q.pop ( ) ;
        int sz = v[ x ].size ( ) ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            int to = v[ x ][ i ].first ;
            if ( len[ to ] == MAXN ) {
                len[ to ] = len[ x ] + 1 ;
                q.push ( to ) ;
            }
        }
    }
    int mx , id ;
    mx = id = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( mx < len[ i ] ) {
            mx = len[ i ] ;
            id = i ;
        }
    }
    return id ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y , z ;
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        v[ x ].push_back ( { y , z } ) ;
        v[ y ].push_back ( { x , z } ) ;
        edge_list[ i ] = { x , y } ;
    }
    diam[ 0 ] = bfs ( 1 ) ;
    diam[ 1 ] = bfs ( diam[ 0 ] ) ;
}

void solve ( ) {
    for ( int i = 0 ; i < 2 ; ++ i ) {
        w[ i ].init ( diam[ i ] ) ;
    }
    int q ;
    scanf ( "%d" , &q ) ;
    while ( q -- ) {
        int x ;
        scanf ( "%d" , &x ) ;
        w[ 0 ].handle ( x ) ; w[ 1 ].handle ( x ) ;
        printf ( "%d\n" , max ( w[ 0 ].query ( ) , w[ 1 ].query ( ) ) ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
using namespace std ;

#define MAXN 900007

int n , q , st ;
vector < pair < int , int > > v[ MAXN ] ;

int pos[ MAXN ] ;
long long dist[ MAXN ] ;
int trsz ;
int enleaf1[ MAXN ] ;
int enleaf2[ MAXN ] ;

int tot ;

struct tuhla {
    int vertex ;
    long long len ;
    tuhla ( ) { vertex = len = 0 ; }
    tuhla ( int _vertex , long long _len ) {
        vertex = _vertex ;
        len = _len ;
    }
};
bool operator < ( tuhla p1 , tuhla p2 ) {
    return ( p1.len > p2.len ) ;
}

priority_queue < tuhla > pq ;

void init ( int where , int IL , int IR ) {
    trsz ++ ;
    if ( IL == IR ) {
        enleaf1[ IL ] = where ;
        return ;
    }
    int mid = ( IL + IR ) / 2 ;
    v[ where ].push_back ( make_pair ( 2 * where , 0 ) ) ;
    v[ where ].push_back ( make_pair ( 2 * where + 1 , 0 ) ) ;
    init ( 2 * where , IL , mid ) ;
    init ( 2 * where + 1 , mid + 1 , IR ) ;
}
void w ( int where , int IL , int IR ) {
    if ( IL == IR ) {
        enleaf2[ IL ] = trsz + where ;
        return ;
    }
    int mid = ( IL + IR ) / 2 ;
    v[ trsz + 2 * where ].push_back ( make_pair ( trsz + where , 0 ) ) ;
    v[ trsz + 2 * where + 1 ].push_back ( make_pair ( trsz + where , 0 ) ) ;
    w ( 2 * where , IL , mid ) ;
    w ( 2 * where + 1 , mid + 1 , IR ) ;
}

void upd1 ( int where , int IL , int IR , int CURL , int CURR , int from , int len ) {
    if ( IR < CURL || CURR < IL ) { return ; }
    if ( CURL <= IL && IR <= CURR ) {
        v[ pos[ from ] ].push_back ( make_pair ( where , len ) ) ;
        return ;
    }
    int mid = ( IL + IR ) / 2 ;
    upd1 ( 2 * where , IL , mid , CURL , CURR , from , len ) ;
    upd1 ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , from , len ) ;
}

void upd2 ( int where , int IL , int IR , int CURL , int CURR , int to , int len ) {
    if ( IR < CURL || CURR < IL ) { return ; }
    if ( CURL <= IL && IR <= CURR ) {
        v[ trsz + where ].push_back ( make_pair ( pos[ to ] , len ) ) ;
        return ;
    }
    int mid = ( IL + IR ) / 2 ;
    upd2 ( 2 * where , IL , mid , CURL , CURR , to , len ) ;
    upd2 ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , to , len ) ;
}

void input ( ) {
    scanf ( "%d%d%d" , &n , &q , &st ) ;
    tot = n ;
    while ( (tot&(tot-1)) != 0 ) { tot ++ ; }
    init ( 1 , 1 , tot ) ;
    w ( 1 , 1 , tot ) ;
    int i ;
    for ( i = 1 ; i <= tot ; i ++ ) {
        pos[ i ] = 2 * trsz + i ;
        v[ enleaf1[ i ] ].push_back ( make_pair ( pos[ i ] , 0 ) ) ;
        v[ pos[ i ] ].push_back ( make_pair ( enleaf2[ i ] , 0 ) ) ;
    }
    for ( i = 1 ; i <= q ; i ++ ) {
        int type ;
        scanf ( "%d" , &type ) ;
        int x , y , z , t ;
        if ( type == 1 ) {
            scanf ( "%d%d%d" , &x , &y , &t ) ;
            v[ pos[ x ] ].push_back ( make_pair ( pos[ y ] , t ) ) ;
        }
        else if ( type == 2 ) {
            scanf ( "%d%d%d%d" , &x , &y , &z , &t ) ;
            upd1 ( 1 , 1 , tot , y , z , x , t ) ;
        }
        else {
            scanf ( "%d%d%d%d" , &x , &y , &z , &t ) ;
            upd2 ( 1 , 1 , tot , y , z , x , t ) ;
        }
    }
}

void solve ( ) {
    int i ;
    for ( i = 1 ; i <= pos[ tot ] ; i ++ ) {
        dist[ i ] = -1 ;
    }
    dist[ pos[ st ] ] = 0 ;
    pq.push ( tuhla ( pos[ st ] , 0 ) ) ;
    while ( pq.empty ( ) == false ) {
        tuhla u = pq.top ( ) ;
        pq.pop ( ) ;
        if ( u.len != dist[ u.vertex ] ) { continue ; }
        int sz = v[ u.vertex ].size ( ) ;
        for ( i = 0 ; i < sz ; i ++ ) {
            int h = v[ u.vertex ][ i ].first ;
            long long c = v[ u.vertex ][ i ].second ;
            if ( dist[ h ] == -1 || dist[ h ] > u.len + c ) {
                dist[ h ] = u.len + c ;
                pq.push ( tuhla ( h , dist[ h ] ) ) ;
            }
        }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        cout << dist[ pos[ i ] ] << " " ;
    }
    cout << "\n" ;
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
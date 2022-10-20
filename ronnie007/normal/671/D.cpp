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

#define MAXN 300007

long long inf = 1e15 + 7 ;

int n , m ;
vector < int > v[ MAXN ] ;

vector < int > ord ;
int st[ MAXN ] ;
int en[ MAXN ] ;
int cost[ MAXN ] ;

vector < int > add[ MAXN ] ;
vector < int > rem[ MAXN ] ;
int qpos[ MAXN ] ;

long long dp[ MAXN ] ;


class Tree {
    public :
    long long tr[ 5 * MAXN ] ;
    long long aux[ 5 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = inf ;
        aux[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void pos_update ( int where , int IL , int IR , int pos , long long val ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ] = val ;
            if ( tr[ where ] > inf ) { tr[ where ] = inf ; }
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            pos_update ( 2 * where , IL , mid , pos , val ) ;
        }
        else {
            pos_update ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
        }
        tr[ where ] = min ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) + aux[ where ] ;
        if ( tr[ where ] > inf ) { tr[ where ] = inf ; }
    }
    void range_update ( int where , int IL , int IR , int CURL , int CURR , long long val ) {
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            aux[ where ] += val ;
            tr[ where ] += val ;
            if ( aux[ where ] > inf ) { aux[ where ] = inf ; }
            if ( tr[ where ] > inf ) { tr[ where ] = inf ; }
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        range_update ( 2 * where , IL , mid , CURL , CURR , val ) ;
        range_update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
        tr[ where ] = min ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) + aux[ where ] ;
        if ( tr[ where ] > inf ) { tr[ where ] = inf ; }
    }
    long long query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( CURR < IL || IR < CURL ) { return inf ; }
        if ( CURL <= IL && IR <= CURR ) { return min ( tr[ where ] , inf ) ; }
        int mid = ( IL + IR ) / 2 ;
        double ret = inf ;
        double cur = min ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) + aux[ where ] ;
        return min ( ret , cur ) ;
    }
};

Tree w ;


void dfs ( int vertex , int prv ) {
    st[ vertex ] = ord.size ( ) + 1 ;
    int i ;
    int sz = add[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        ord.push_back ( add[ vertex ][ i ] ) ;
        qpos[ add[ vertex ][ i ] ] = ord.size ( ) ;
    }
    sz = v[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        dfs ( v[ vertex ][ i ] , vertex ) ;
    }
    en[ vertex ] = ord.size ( ) ;
}

void calc ( int vertex , int prv ) {
    int i ;
    int sz = v[ vertex ].size ( ) ;
    long long sm = 0 ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        calc ( v[ vertex ][ i ] , vertex ) ;
        sm += dp[ v[ vertex ][ i ] ] ;
        if ( sm > 3 * inf ) { sm = 3 * inf ; }
    }
    if ( vertex == 1 ) { dp[ vertex ] = sm ; return ; }
    sz = add[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        w.pos_update ( 1 , 1 , m , qpos[ add[ vertex ][ i ] ] , sm + cost[ add[ vertex ][ i ] ] ) ;
    }
    sz = rem[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        w.pos_update ( 1 , 1 , m , qpos[ rem[ vertex ][ i ] ] , inf ) ;
    }
    sz = v[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        w.range_update ( 1 , 1 , m , st[ v[ vertex ][ i ] ] , en[ v[ vertex ][ i ] ] , sm - dp[ v[ vertex ][ i ] ] ) ;
    }
    dp[ vertex ] = w.query ( 1 , 1 , m , st[ vertex ] , en[ vertex ] ) ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    for ( i = 1 ; i < n ; i ++ ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
    for ( i = 1 ; i <= m ; i ++ ) {
        int x , y ;
        scanf ( "%d%d%d" , &x , &y , &cost[ i ] ) ;
        add[ x ].push_back ( i ) ;
        rem[ y ].push_back ( i ) ;
    }
}

void solve ( ) {
    w.init ( 1 , 1 , m ) ;
    dfs ( 1 , -1 ) ;
    calc ( 1 , -1 ) ;
    if ( dp[ 1 ] >= inf ) { dp[ 1 ] = -1 ; }
    printf ( "%I64d\n" , dp[ 1 ] ) ;
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
using namespace std ;

#define MAXN 100007
#define inf 1000000007

int n , root ;
int q ;
int a[ MAXN ] ;
vector < int > v[ MAXN ] ;

vector < int > ord ;

int st[ MAXN ] ;
int en[ MAXN ] ;
int lvl[ MAXN ] ;

class Tree {
    public :
    vector < int > tr[ 3 * MAXN ] ;
    vector < int > pref[ 3 * MAXN ] ;
    void merge ( int where , int IL , int IR ) {
        int sz1 = tr[ 2 * where ].size ( ) ;
        int sz2 = tr[ 2 * where + 1 ].size ( ) ;
        int id1 , id2 ;
        id1 = id2 = 0 ;
        while ( id1 != sz1 || id2 != sz2 ) {
            if ( id1 == sz1 ) {
                tr[ where ].push_back ( tr[ 2 * where + 1 ][ id2 ] ) ;
                id2 ++ ;
            }
            else if ( id2 == sz2 ) {
                tr[ where ].push_back ( tr[ 2 * where ][ id1 ] ) ;
                id1 ++ ;
            }
            else {
                if ( lvl[ tr[ 2 * where ][ id1 ] ] < lvl[ tr[ 2 * where + 1 ][ id2 ] ] ) {
                    tr[ where ].push_back ( tr[ 2 * where ][ id1 ] ) ;
                    id1 ++ ;
                }
                else {
                    tr[ where ].push_back ( tr[ 2 * where + 1 ][ id2 ] ) ;
                    id2 ++ ;
                }
            }
        }
        int i ;
        int sz = tr[ where ].size ( ) ;
        pref[ where ].resize ( sz ) ;
        pref[ where ][ 0 ] = a[ tr[ where ][ 0 ] ] ;
        for ( i = 1 ; i < sz ; i ++ ) {
            pref[ where ][ i ] = min ( pref[ where ][ i - 1 ] , a[ tr[ where ][ i ] ] ) ;
        }
    }
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            tr[ where ].push_back ( ord[ IL - 1 ] ) ;
            pref[ where ].push_back ( a[ ord[ IL - 1 ] ] ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        merge ( where , IL , IR ) ;
    }
    int calc ( int where , int sr ) {
        int l , r , mid ;
        l = 0 ;
        r = tr[ where ].size ( ) - 1 ;
        if ( lvl[ tr[ where ][ 0 ] ] > sr ) { return inf ; }
        while ( r - l > 3 ) {
            mid = ( l + r ) / 2 ;
            if ( lvl[ tr[ where ][ mid ] ] > sr ) { r = mid ; }
            else { l = mid ; }
        }
        while ( lvl[ tr[ where ][ r ] ] > sr ) { r -- ; }
        return pref[ where ][ r ] ;
    }
    int query ( int where , int IL , int IR , int CURL , int CURR , int sr ) {
        if ( IR < CURL || CURR < IL ) { return inf ; }
        if ( CURL <= IL && IR <= CURR ) {
            return calc ( where , sr ) ;
        }
        int mid = ( IL + IR ) / 2 ;
        return min ( query ( 2 * where , IL , mid , CURL , CURR , sr ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , sr ) ) ;
    }
};

Tree w ;

void dfs ( int vertex , int prv ) {
    ord.push_back ( vertex ) ;
    st[ vertex ] = ord.size ( ) ;
    int i ;
    int sz = v[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        lvl[ v[ vertex ][ i ] ] = lvl[ vertex ] + 1 ;
        dfs ( v[ vertex ][ i ] , vertex ) ;
    }
    en[ vertex ] = ord.size ( ) ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &root ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( i = 1 ; i < n ; i ++ ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    dfs ( root , -1 ) ;
    w.init ( 1 , 1 , n ) ;
    scanf ( "%d" , &q ) ;
    int lst = 0 ;
    int i ;
    int x , y ;
    for ( i = 1 ; i <= q ; i ++ ) {
        scanf ( "%d%d" , &x , &y ) ;
        x = ( ( x + lst ) % n + 1 ) ;
        y = ( ( y + lst ) % n ) ;
        lst = w.query ( 1 , 1 , n , st[ x ] , en[ x ] , lvl[ x ] + y ) ;
        printf ( "%d\n" , lst ) ;
    }
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
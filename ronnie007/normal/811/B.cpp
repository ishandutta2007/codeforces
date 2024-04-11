#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std ;

#define MAXN 10007

int n , q ;
int a[ MAXN ] ;

int ans[ MAXN ] ;
int pos[ MAXN ] ;
struct tuhla {
    int l , r ;
    int id ;
    tuhla ( ) { l = r = id = 0 ; }
    tuhla ( int _l , int _r , int _id ) {
        l = _l ;
        r = _r ;
        id = _id ;
    }
};
vector < tuhla > to_ask[ MAXN ] ;

class Tree {
    public :
    int tr[ 12 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos , int val ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ] += val ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , pos , val ) ;
        update ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
        tr[ where ] = ( tr[ 2 * where ] + tr[ 2 * where + 1 ] ) ;
    }
    int query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IR < CURL || CURR < IL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) {
            return tr[ where ] ;
        }
        int mid = ( IL + IR ) / 2 ;
        return ( query ( 2 * where , IL , mid , CURL , CURR ) + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};

Tree w ;

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        pos[ a[ i ] ] = i ;
    }
    for ( i = 1 ; i <= q ; i ++ ) {
        int x , y , z ;
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        to_ask[ z ].push_back ( tuhla ( x , y , i ) ) ;
    }
}

void solve ( ) {
    w.init ( 1 , 1  , n ) ;
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        int sz = to_ask[ pos[ i ] ].size ( ) ;
        for ( j = 0 ; j < sz ; j ++ ) {
            int br = w.query ( 1 , 1 , n , to_ask[ pos[ i ] ][ j ].l , to_ask[ pos[ i ] ][ j ].r ) ;
            if ( br == pos[ i ] - to_ask[ pos[ i ] ][ j ].l ) {
                ans[ to_ask[ pos[ i ] ][ j ].id ] = 1 ;
            }
            else {
                ans[ to_ask[ pos[ i ] ][ j ].id ] = 0 ;
            }
        }
        w.update ( 1 , 1 , n , pos[ i ] , 1 ) ;
    }
    for ( i = 1 ; i <= q ; i ++ ) {
        if ( ans[ i ] == 0 ) { printf ( "No\n" ) ; }
        else { printf ( "Yes\n" ) ; }
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
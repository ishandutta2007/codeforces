#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std ;


#define MAXN 200007

int n , q ;
int a[ MAXN ] ;

struct query {
    int x , y ;
    int id ;
    query ( ) { x = y = id = 0 ; }
    query ( int _x , int _y , int _id ) {
        x = _x ;
        y = _y ;
        id = _id ;
    }
};
vector < struct query > v[ MAXN ] ;


class Tree {
    public :
    int tr[ 4 * MAXN ][ 107 ] ;
    void merge ( int where ) {
        int i ;
        for ( i = 1 ; i <= 100 ; i ++ ) {
            tr[ where ][ i ] = tr[ 2 * where + 1 ][ tr[ 2 * where ][ i ] ] ;
        }
    }
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            int i ;
            for ( i = 1 ; i <= 100 ; i ++ ) {
                tr[ where ][ i ] = i ;
            }
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        merge ( where ) ;
    }
    void update ( int where , int IL , int IR , int pos , int id , int val ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ][ id ] = val ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , id , val ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , id , val ) ;
        }
        merge ( where ) ;
    }
};
Tree w ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    scanf ( "%d" , &q ) ;
    for ( i = 1 ; i <= q ; i ++ ) {
        int l , r , x , y ;
        scanf ( "%d%d%d%d" , &l , &r , &x , &y ) ;
        v[ l ].push_back ( query ( x , y , i ) ) ;
        v[ r + 1 ].push_back ( query ( x , x , i ) ) ;
    }
}

void solve ( ) {
    w.init ( 1 , 1 , q ) ;
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        int sz = v[ i ].size ( ) ;
        for ( j = 0 ; j < sz ; j ++ ) {
            w.update ( 1 , 1 , q , v[ i ][ j ].id , v[ i ][ j ].x , v[ i ][ j ].y ) ;
        }
        printf ( "%d" , w.tr[ 1 ][ a[ i ] ] ) ;
        if ( i == n ) { printf ( "\n" ) ; }
        else { printf ( " " ) ; }
    }
}


int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
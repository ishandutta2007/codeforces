#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
using namespace std ;

#define MAXN 500007

int n , q ;
int a[ MAXN ] ;

int nxt[ MAXN ] ;
int lst[ MAXN ] ;
bool used[ MAXN ] ;
int ans[ MAXN ] ;

struct query {
    int to ;
    int id ;
    query ( ) { to = id = 0 ; }
    query ( int _to , int _id ) {
        to = _to ;
        id = _id ;
    }
};

vector < struct query > v[ MAXN ] ;

struct node {
    int val ;
    int id ;
    node ( ) { val = id = 0 ; }
    node ( int _val , int _id ) {
        val = _val ;
        id = _id ;
    }
};

node merge ( node p1 , node p2 ) {
    if ( p1.val < p2.val ) {
        return p2 ;
    }
    else { return p1 ; }
}

class Tree {
    public :
    node tr[ 5 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = node ( 0 , IL ) ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos , int val ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ] = node ( val , pos ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , val ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
        }
        tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    node query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IR < CURL || CURR < IL ) { return node ( 0 , 0 ) ; }
        if ( CURL <= IL && IR <= CURR ) {
            return tr[ where ] ;
        }
        int mid = ( IL + IR ) / 2 ;
        return ( merge ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ) ;
    }
};
Tree w ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    w.init ( 1 , 1 , n ) ;
    for ( i = 1 ; i <= 500000 ; i ++ ) {
        lst[ i ] = n + 1 ;
    }
    for ( i = n ; i >= 1 ; i -- ) {
        nxt[ i ] = lst[ a[ i ] ] ;
        lst[ a[ i ] ] = i ;
    }
    for ( i = 1 ; i <= 500000 ; i ++ ) {
        used[ lst[ i ] ] = true ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( used[ i ] == true ) {
            w.update ( 1 , 1 , n , i , nxt[ i ] - 1 ) ;
        }
    }
    scanf ( "%d" , &q ) ;
    for ( i = 1 ; i <= q ; i ++ ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( query ( y , i ) ) ;
    }
}

void solve ( ) {
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        int sz = v[ i ].size ( ) ;
        for ( j = 0 ; j < sz ; j ++ ) {
            node ret = w.query ( 1 , 1 , n , i , v[ i ][ j ].to ) ;
            if ( ret.val < v[ i ][ j ].to ) { ret.id = 0 ; }
            ans[ v[ i ][ j ].id ] = a[ ret.id ] ;
        }
        if ( used[ i ] == true ) {
            w.update ( 1 , 1 , n , i , 0 ) ;
            used[ nxt[ i ] ] = true ;
            if ( nxt[ i ] <= n ) {
                w.update ( 1 , 1 , n , nxt[ i ] , nxt[ nxt[ i ] ] - 1 ) ;
            }
        }
    }
    for ( i = 1 ; i <= q ; i ++ ) {
        printf ( "%d\n" , ans[ i ] ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
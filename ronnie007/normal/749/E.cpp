#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;
int inv[ MAXN ] ;

struct node {
    double val ;
    int cnt ;
    node ( ) { val = 0.0 ; cnt = 0 ; }
    node ( double _val , int _cnt ) {
        val = _val ; cnt = _cnt ;
    }
};
node unite ( node p1 , node p2 ) {
    node ret = p1 ;
    ret.val += p2.val ;
    ret.cnt += p2.cnt ;
    return ret ;
}

class Tree {
public :
    node tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = node ( 0.0 , 0 ) ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos , double add ) {
        tr[ where ].val += add ;
        ++ tr[ where ].cnt ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , add ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , add ) ;
        }
    }
    node query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IL > IR || CURL > CURR ) { return node ( 0.0 , 0 ) ; }
        if ( CURR < IL || IR < CURL ) { return node ( 0.0 , 0 ) ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return unite ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};
Tree w ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        inv[ a[ i ] ] = i ;
    }
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    double ans = 0.0 ;
    double coef = 1.0 / ( 1.0 * n * ( n + 1 ) / 2.0 ) ;
    for ( int i = n ; i >= 1 ; -- i ) {
        node ret = w.query ( 1 , 1 , n , 1 , inv[ i ] ) ;
        ans += ret.cnt ;
        ans -= ret.val * ( n - inv[ i ] + 1 ) / 2.0 ;
        w.update ( 1 , 1 , n , inv[ i ] , coef * inv[ i ] ) ;
    }
    w.init ( 1 , 1 , n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        node ret = w.query ( 1 , 1 , n , 1 , inv[ i ] ) ;
        ans += ret.val * ( n - inv[ i ] + 1 ) / 2.0 ;
        w.update ( 1 , 1 , n , inv[ i ] , coef * inv[ i ] ) ;
    }
    printf ( "%.12lf\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<queue>
using namespace std ;

#define MAXN 500007

int n , val ;
int a[ MAXN ] ;

vector < int > v[ MAXN ] ;

int pref[ MAXN ] ;
int suff[ MAXN ] ;

struct tuhla {
    int ans ;
    int val ;
    tuhla ( ) { ans = val = 0 ; }
    tuhla ( int _ans , int _val ) {
        ans = _ans ;
        val = _val ;
    }
};

tuhla unite ( tuhla p1 , tuhla p2 ) {
    tuhla ret ;
    ret.ans = max ( p1.ans , p1.val + p2.ans ) ;
    ret.val = ( p1.val + p2.val ) ;
    return ret ;
}

class Tree {
    public :
    tuhla tr[ 5 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ].val = 0 ;
        if ( IL == IR ) {
            tr[ where ].ans = suff[ IR + 1 ] ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = unite ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    void update ( int where , int IL , int IR , int pos , int add ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ].val += add ;
            tr[ where ].ans += add ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , add ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , add ) ;
        }
        tr[ where ] = unite ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    tuhla query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( CURR < IL || IR < CURL ) { return tuhla ( 0 , 0 ) ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return ( unite ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ) ;
    }
};

Tree w ;


void input ( ) {
    scanf ( "%d%d" , &n , &val ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        v[ a[ i ] ].push_back ( i ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        pref[ i ] = pref[ i - 1 ] + ( ( a[ i ] == val ) ? 1 : 0 ) ;
    }
    for ( i = n ; i >= 1 ; i -- ) {
        suff[ i ] = suff[ i + 1 ] + ( ( a[ i ] == val ) ? 1 : 0 ) ;
    }
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    int i , j ;
    int ans = 0 ;
    for ( i = 1 ; i <= 500000 ; i ++ ) {
        int sz = v[ i ].size ( ) ;
        for ( j = 0 ; j < sz ; j ++ ) {
            w.update ( 1 , 1 , n , v[ i ][ j ] , 1 ) ;
        }
        for ( j = 0 ; j < sz ; j ++ ) {
            ans = max ( ans , (w.query ( 1 , 1 , n , v[ i ][ j ] , n ).ans) + pref[ v[ i ][ j ] - 1 ] )  ;
        }
        for ( j = 0 ; j < sz ; j ++ ) {
            w.update ( 1 , 1 , n , v[ i ][ j ] , -1 ) ;
        }
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
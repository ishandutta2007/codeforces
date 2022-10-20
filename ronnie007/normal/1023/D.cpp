#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<stack>
using namespace std ;

#define MAXN 200007

int n , q ;
int a[ MAXN ] ;

int st[ MAXN ] ;
int en[ MAXN ] ;

int nxt_l[ MAXN ] ;
int nxt_r[ MAXN ] ;
vector < int > v[ MAXN ] ;


class Tree {
    public :
    int tr[ 5 * MAXN ] ;
    int mark[ 5 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = MAXN ;
        mark[ where ] = -1 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos , int val ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ] = val ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , val ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
        }
        tr[ where ] = min ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    int query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IR < CURL || CURR < IL ) { return MAXN ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return ( min ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ) ;
    }
    void fill_interval ( int where , int IL , int IR , int CURL , int CURR , int val ) {
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            mark[ where ] = val ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        fill_interval ( 2 * where , IL , mid , CURL , CURR , val ) ;
        fill_interval ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
    }
    int get_val ( int where , int IL , int IR , int pos ) {
        if ( IR < pos || pos < IL ) { return -1 ; }
        if ( IL == IR ) { return mark[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        int ret ;
        if ( pos <= mid ) { ret = get_val ( 2 * where , IL , mid , pos ) ; }
        else { ret = get_val ( 2 * where + 1 , mid + 1 , IR , pos ) ; }
        ret = max ( ret , mark[ where ] ) ;
        return ret ;
    }
};

Tree w ;

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        v[ a[ i ] ].push_back ( i ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( st[ a[ i ] ] == 0 ) { st[ a[ i ] ] = i ; }
        en[ a[ i ] ] = i ;
    }
    int h = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( a[ i ] != 0 ) { h = a[ i ] ; }
        else { nxt_l[ i ] = h ; }
    }
    h = 0 ;
    for ( i = n ; i >= 1 ; i -- ) {
        if ( a[ i ] != 0 ) { h = a[ i ] ; }
        else { nxt_r[ i ] = h ; }
    }
}

void solve ( ) {
    int i ;
    int mx = 0 ;
    int br_mx = 0 ;
    int tot_zero = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( mx < a[ i ] ) { mx = a[ i ] ; }
        if ( a[ i ] == q ) { br_mx ++ ; }
        if ( a[ i ] == 0 ) { tot_zero ++ ; }
    }
    if ( mx == 0 ) {
        printf ( "YES\n" ) ;
        for ( i = 1 ; i <= n ; i ++ ) {
            printf ( "%d " , q ) ;
        }
        printf ( "\n" ) ;
        return ;
    }
    w.init ( 1 , 1 , n ) ;
    for ( i = 1 ; i <= q ; i ++ ) {
        if ( st[ i ] == 0 ) { continue ; }
        int h = w.query ( 1 , 1 , n , st[ i ] , en[ i ] ) ;
        if ( h < i ) { printf ( "NO\n" ) ; return ; }
        int sz = v[ i ].size ( ) ;
        for ( int j = 0 ; j < sz ; j ++ ) {
            w.update ( 1 , 1 , n , v[ i ][ j ] , i ) ;
        }
        w.fill_interval ( 1 , 1 , n , st[ i ] , en[ i ] , i ) ;
    }
    if ( br_mx == 0 ) {
        for ( i = 1 ; i <= n ; i ++ ) {
            if ( a[ i ] == 0 ) {
                a[ i ] = q ; break ;
            }
        }
        if ( i <= n ) {
            int h = 0 ;
            int j ;
            for ( j = 1 ; j <= n ; j ++ ) {
                if ( a[ j ] != 0 ) { h = a[ j ] ; }
                else { nxt_l[ j ] = h ; }
            }
            h = 0 ;
            for ( j = n ; j >= 1 ; j -- ) {
                if ( a[ j ] != 0 ) { h = a[ j ] ; }
                else { nxt_r[ j ] = h ; }
            }
        }
        else { printf ( "NO\n" ) ; return ; }
    }
    printf ( "YES\n" ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( a[ i ] != 0 ) { printf ( "%d " , a[ i ] ) ; }
        else {
            int ret = w.get_val ( 1 , 1 , n , i ) ;
            if ( ret > -1 ) { printf ( "%d " , ret ) ; }
            else { printf ( "%d " , max ( nxt_l[ i ] , nxt_r[ i ] ) ) ; }
        }
    }
    printf ( "\n" ) ;
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
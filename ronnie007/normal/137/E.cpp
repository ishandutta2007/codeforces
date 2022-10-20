#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
using namespace std ;


#define MAXN 200007

int n ;
string a ;
int pref[ MAXN ] ;


class Tree {
    public :
    int tr[ 12 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = MAXN ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos , int val ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ] = min ( tr[ where ] , val ) ;
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
        if ( CURL > CURR ) { return MAXN ; }
        if ( CURR < IL || IR < CURL ) { return MAXN ; }
        if ( CURL <= IL && IR <= CURR ) {
            return tr[ where ] ;
        }
        int mid = ( IL + IR ) / 2 ;
        return min ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};

Tree w ;

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        if ( a[ i ] >= 'A' && a[ i ] <= 'Z' ) {
            int val = ( a[ i ] - 'A' ) ;
            a[ i ] = char ( 'a' + val ) ;
        }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( a[ i - 1 ] == 'a' || a[ i - 1 ] == 'e' || a[ i - 1 ] == 'i' || a[ i - 1 ] == 'o' || a[ i - 1 ] == 'u' ) {
            pref[ i ] = pref[ i - 1 ] + 1 ;
        }
        else { pref[ i ] = pref[ i - 1 ] - 2 ; }
    }
}

void solve ( ) {
    w.init ( 1 , 1 , 3 * MAXN ) ;
    int i ;
    w.update ( 1 , 1 , 3 * MAXN , 2 * MAXN , 0 ) ;
    int ans = 0 ;
    int tm = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        int ret = w.query ( 1 , 1 , 3 * MAXN , 2 * MAXN + pref[ i ] , 3 * MAXN ) ;
        if ( ans < ( i - ret ) ) {
            ans = ( i - ret ) ;
            tm = 0 ;
        }
        if ( ans == ( i - ret ) ) {
            tm ++ ;
        }
        w.update ( 1 , 1 , 3 * MAXN , 2 * MAXN + pref[ i ] , i ) ;
    }
    if ( ans == 0 ) { printf ( "No solution\n" ) ; return ; }
    printf ( "%d %d\n" , ans , tm ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
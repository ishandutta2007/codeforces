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

#define MAXN 500007

int n ;
int a[ MAXN ] ;

int get_gcd ( int x , int y ) {
    if ( x < y ) { swap ( x , y ) ; }
    if ( y == 0 ) { return x ; }
    return get_gcd ( y , ( x % y ) ) ;
}

class Tree {
    public :
    int tr[ 10 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            tr[ where ] = a[ IL ] ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = get_gcd ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
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
        tr[ where ] = get_gcd ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    int get_val ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IR < CURL || CURR < IL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) {
            return tr[ where ] ;
        }
        int mid = ( IL + IR ) / 2 ;
        int ret1 = get_val ( 2 * where , IL , mid , CURL , CURR ) ;
        int ret2 = get_val ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
        return get_gcd ( ret1 , ret2 ) ;
    }
    int get_id ( int where , int IL , int IR , int st , int val ) {
        if ( IR < st ) { return 0 ; }
        if ( IL == IR ) {
            if ( ( tr[ where ] % val ) == 0 ) { return 0 ; }
            return IL ;
        }
        if ( st <= IL ) {
            if ( ( tr[ where ] % val ) == 0 ) { return 0 ; }
        }
        int mid = ( IL + IR ) / 2 ;
        int ret1 = get_id ( 2 * where , IL , mid , st , val ) ;
        if ( ret1 != 0 ) {
            return ret1 ;
        }
        ret1 = get_id ( 2 * where + 1 , mid + 1 , IR , st , val ) ;
        return ret1 ;
    }
};

Tree w ;


void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    int q ;
    int type , x , y , z ;
    scanf ( "%d" , &q ) ;
    while ( q != 0 ) {
        q -- ;
        scanf ( "%d" , &type ) ;
        if ( type == 1 ) {
            scanf ( "%d%d%d" , &x , &y , &z ) ;
            int id = w.get_id ( 1 , 1 , n , x , z ) ;
            if ( id == 0 ) { id = n ; }
            if ( id >= y ) { printf ( "YES\n" ) ; }
            else {
                int h = w.get_val( 1 , 1 , n , id + 1 , y ) ;
                if ( ( h % z ) == 0 ) { printf ( "YES\n" ) ; }
                else { printf ( "NO\n" ) ; }
            }
        }
        else {
            scanf ( "%d%d" , &x , &y ) ;
            w.update ( 1 , 1 , n , x , y ) ;
            a[ x ] = y ;
        }
    }
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std ;

#define MAXN 100007

int n , q ;
int a[ MAXN ] ;
struct node {
	long long sm ;
    int mx ;
    node ( ) { sm = mx = 0 ; }
    node ( int val ) { sm = mx = val ; }
};

node merge ( node p1 , node p2 ) {
	node ret = node ( ) ;
    ret.sm = ( p1.sm + p2.sm ) ;
    ret.mx = max ( p1.mx , p2.mx ) ;
    return ret ;
}

struct segment_tree {
	node tr[ 10 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
    	if ( IL == IR ) {
        	if ( IL <= n ) { tr[ where ] = node ( a[ IL ] ) ; }
        	else { tr[ where ] = node ( ) ; }
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    void update_val ( int where , int val ) {
    	tr[ where ] = node ( val ) ;
        where /= 2 ;
        while ( where != 0 ) {
        	tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
            where /= 2 ;
        }
    }
    void update_mod ( int where , int IL , int IR , int CURL , int CURR , int val ) {
    	if ( IL > IR ) { return ; }
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( tr[ where ].mx < val ) { return ; }
        if ( IL == IR && CURL <= IL && IR <= CURR ) {
        	tr[ where ] = node ( ( tr[ where ].sm % val ) ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update_mod ( 2 * where , IL , mid , CURL , CURR , val ) ;
        update_mod ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
        tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    node query ( int where , int IL , int IR , int CURL , int CURR ) {
    	if ( IL > IR ) { return node ( 0 ) ; }
        if ( IR < CURL || CURR < IL ) { return node ( 0 ) ; }
        if ( CURL <= IL && IR <= CURR ) {
            return tr[ where ] ;
        }
        int mid = ( IL + IR ) / 2 ;
        return ( merge ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ) ;
    }
};

segment_tree w ;

void input ( ) {
	scanf ( "%d%d" , &n , &q ) ;
	int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
	int LEAVES = 1 ;
    while ( LEAVES < n ) { LEAVES *= 2 ; }
	w.init ( 1 , 1 , LEAVES ) ;
    int type , x , y , z ;
    while ( q != 0 ) {
    	q -- ;
        scanf ( "%d" , &type ) ;
        if ( type == 1 ) {
        	scanf ( "%d%d" , &x , &y ) ;
        	printf ( "%I64d\n" , w.query ( 1 , 1 , LEAVES , x , y ) ) ;
        }
        else if ( type == 2 ) {
        	scanf ( "%d%d%d" , &x , &y , &z ) ;
            w.update_mod ( 1 , 1 , LEAVES , x , y , z ) ;
        }
        else {
        	scanf ( "%d%d" , &x , &y ) ;
            w.update_val ( LEAVES + x - 1 , y ) ;
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
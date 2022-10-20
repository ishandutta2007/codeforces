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

int n ;
int a[ 2 * MAXN ] ;
int id[ MAXN ] ;

struct node {
	int st , en ;
	int f[ 62 ] ;
	node ( ) {
		st = en = 0 ;
		int i ;		
		for ( i = 0 ; i < 60 ; i ++ ) { f[ i ] = 0 ; } 		
	}
	node ( int x ) {
		st = en = x ;
		int i ;		
		for ( i = 0 ; i < 60 ; i ++ ) {
			if ( a[ x ] != 1000000 && ( i % a[ x ] ) == 0 ) { f[ i ] = 2 ; }
			else { f[ i ] = 1 ; }
		} 		
	}
};




node merge ( node p1 , node p2 ) {
	if ( p1.st == 0 ) { return p2 ; }
	if ( p2.st == 0 ) { return p1 ; }
	int i ;
	node ret ;
	ret.st = p1.st ;
	ret.en = p2.en ;
	for ( i = 0 ; i < 60 ; i ++ ) {
		int tm = i ;
		ret.f[ i ] = p1.f[ i ] + p2.f[ ( i + p1.f[ i ] ) % 60 ] ;
	}
	return ret ;
}

struct segment_tree {
	node tr[ 5 * MAXN ] ;
	void init ( int where , int IL , int IR ) {
		if ( IL > IR ) { return ; }
		if ( IL == IR ) {
			id[ IL ] = where ; 
			tr[ where ] = node ( IL ) ;
			return ;
		}
		int mid = ( IL + IR ) / 2 ;
		init ( 2 * where , IL , mid ) ;
		init ( 2 * where + 1 , mid + 1 , IR ) ;
		tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
	}
	void update ( int where , int val ) {
		tr[ where ] = node ( tr[ where ].st ) ;
		where /= 2 ;
		while ( where != 0 ) {
			tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
			where /= 2 ;
		}
	}
	node query ( int where , int IL , int IR , int CURL , int CURR ) {
		if ( CURL > CURR ) { return node ( 0 ) ; }
		if ( IL > IR ) { return node ( 0 ) ; }
		if ( IR < CURL || CURR < IL ) { return node ( 0 ) ; }
		if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
		int mid = ( IL + IR ) / 2 ;
		return merge ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
	}
};

segment_tree w ;

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
	a[ 0 ] = 1000000 ; 
}

void solve ( ) {
	w.init ( 1 , 1 , n ) ;
	int q ;
	scanf ( "%d" , &q ) ;
	char c ;
	int x , y ;
	while ( q != 0 ) {
		q -- ;
		scanf ( "\n%c" , &c ) ;
		scanf ( "%d%d" , &x , &y ) ;
		if ( c == 'A' ) {
			y -- ;
			 printf ( "%d\n" , w.query ( 1 , 1 , n , x , y ).f[ 0 ] ) ;
		}
		else {
			a[ x ] = y ;
			w.update ( id[ x ] , y ) ;
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
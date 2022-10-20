#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<set>
#include<map>
using namespace std ;

#define MAXN 200007
#define LEAVES 16384
int n , val , k ;

int a[ MAXN ] ;
int t[ MAXN ] ;

int id[ MAXN ] ;

struct node {
	int br ;
	int sm1 , sm2 ;
	node ( ) { br = sm1 = sm2 = 0 ; }
	node ( int x ) {
		br = 1 ;
		sm1 = x ;
		sm2 = ( x + 1 ) / 2 ;
	}
};

node merge ( node p1 , node p2 ) {
	node ret ;
	ret.br = ( p1.br + p2.br ) ;
	ret.sm1 = ( p1.sm1 + p2.sm1 ) ;
	ret.sm2 = ( p1.sm2 + p2.sm2 ) ;
	return ret ;
}

struct segment_tree {
	node tr[ MAXN ] ;
	void init ( int where , int IL , int IR ) {
		if ( IL > IR ) { return ; }	
		if ( IL == IR ) {
			id[ IL ] = where ;
			tr[ where ] = node ( ) ;
			return ;
		}
		int mid = ( IL + IR ) / 2 ;
		init ( 2 * where , IL , mid ) ;
		init ( 2 * where + 1 , mid + 1 , IR ) ;
		tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
	}
	void update ( int where , int g ) {
		if ( g > 0 ) {
			tr[ where ].br ++ ;
			tr[ where ].sm1 += g ;
			tr[ where ].sm2 += ( g + 1 ) / 2 ;
		}
		else {
			g = -g ;
			tr[ where ].br -- ;
			tr[ where ].sm1 -= g ;
			tr[ where ].sm2 -= ( g + 1 ) / 2 ;			
		}
		where /= 2 ;
		while ( where != 0 ) {
			tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
			where /= 2 ;
		}
	}
	int query ( int where , int IL , int IR , int lft ) {
		if ( IL > IR ) { return 0 ; }
		if ( lft == 0 ) {
			return tr[ where ].sm1 ;
		}
		if ( lft >= tr[ where ].br ) {
			return tr[ where ].sm2 ;
		}
		if ( IL == IR ) {
			int base1 = ( tr[ where ].sm1 / tr[ where ].br ) ;
			int base2 = ( tr[ where ].sm2 / tr[ where ].br ) ;
			return ( lft * base2 + ( tr[ where ].br - lft ) * base1 ) ;
		}
		int mid = ( IL + IR ) / 2 ;
		int val = ( lft - tr[ 2 * where + 1 ].br ) ;
		return query ( 2 * where , IL , mid , max ( val , 0 ) ) + query ( 2 * where + 1 , mid + 1 , IR , lft ) ;
	}
};

segment_tree w ;

void input ( ) {
	scanf ( "%d%d%d" , &n , &val , &k ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &t[ i ] ) ;
	}
}

void solve ( ) {
	w.init ( 1 , 1 , LEAVES ) ;
	int i ;
	int r = 0 ;
	int cur = 0 ;
	int ans = 0 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( ( ( t[ i ] + 1 ) / 2 ) > k ) { continue ; }
		if ( r < i ) {
			w.update ( id[ t[ i ] ] , t[ i ] ) ;
			cur += a[ i ] ;
			r = i ;
		}
		while ( r < n && w.query ( 1 , 1 , LEAVES , val ) <= k ) {
			r ++ ;
			cur += a[ r ] ; 
			w.update ( id[ t[ r ] ] , t[ r ] ) ;
		}
		while ( r > i && w.query ( 1 , 1 , LEAVES , val ) > k ) {
			cur -= a[ r ] ;
			w.update ( id[ t[ r ] ], -t[ r ] ) ;			
			r -- ;
		}
		if ( ans < cur ) { ans = cur ; }
		cur -= a[ i ] ;
		w.update ( id[ t[ i ] ] , -t[ i ] ) ;
	}
	printf ( "%d\n" , ans ) ;
}

int main ( ) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
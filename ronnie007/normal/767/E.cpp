#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
#include<set>
#include<stack>
using namespace std ;

#define MAXN 100007

int n , k ;
int a[ MAXN ] ;
int b[ MAXN ] ;
int z[ MAXN ] ;

bool g[ MAXN ] ;
int LEAVES ;
struct segment_tree {
	int tr[ 3 * MAXN ] ;
	int mn[ 3 * MAXN ] ;
	void merge ( int where ) {
		tr[ where ] = tr[ 2 * where ] + tr[ 2 * where + 1 ] ;
		mn[ where ] = min ( mn[ 2 * where ] , tr[ 2 * where ] + mn[ 2 * where + 1 ] ) ;
	}
	void init ( int where , int IL , int IR ) {
		if ( IL == IR ) {
			tr[ where ] = mn[ where ] = z[ IL ] ;
			return ;
		}
		int mid = ( IL + IR ) / 2 ;
		init ( 2 * where , IL , mid ) ;
		init ( 2 * where + 1 , mid + 1 , IR ) ;
		merge ( where ) ;
	}
	void update ( int where , int val ) {
		tr[ where ] = mn[ where ] = val ;
		where /= 2 ;
		while ( where != 0 ) {
			merge ( where ) ;
			where /= 2 ;
		}
	}
	int query ( int where ) {
		if ( where < LEAVES ) { return 0 ; }
		int ret = 0 ;
		while ( where != 0 ) {
			if ( (where&(where-1)) == 0 ) { ret += tr[ where ] ; return ret ; }
			if ( ( where % 2 ) == 1 ) { where /= 2 ; }
			else { ret += tr[ where ] ; where -- ; }
		}
		return ret ;
	}
};

segment_tree w ;


struct tuhla {
	int pos ;
	long long val ;
};

tuhla srt[ MAXN ] ;

bool cmp ( tuhla p1 , tuhla p2 ) {
	if ( p1.val != p2.val ) { return ( p1.val > p2.val ) ; }
	return ( p1.pos > p2.pos ) ;
}

void input ( ) {
	scanf ( "%d%d" , &n , &k ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &b[ i ] ) ;
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		int u = ( a[ i ] % 100 ) ;
		u = ( 100 - u ) ;
		u %= 100 ;
		z[ i ] = u ;
		srt[ i ].pos = i ;
		srt[ i ].val = 1LL * u * b[ i ] ;
	}
	sort ( srt + 1 , srt + n + 1 , cmp ) ;
}

void solve ( ) {
	LEAVES = 1 ;
	while ( LEAVES < n ) { LEAVES *= 2 ; }
	w.init ( 1 , 1 , LEAVES ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		int sm = k + w.query ( LEAVES + srt[ i ].pos - 2 ) ;
		if ( sm >= ( a[ srt[ i ].pos ] % 100 ) ) {
			g[ srt[ i ].pos ] = true ;
			w.update ( LEAVES + srt[ i ].pos - 1 , - ( a[ srt[ i ].pos ] % 100 ) ) ;
			if ( w.mn[ 1 ] + k < 0 ) {
				g[ srt[ i ].pos ] = false ;
				w.update ( LEAVES + srt[ i ].pos - 1 , z[ srt[ i ].pos ] ) ;				
			}
		}
	}
	long long tot = 0 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( g[ i ] == false ) { tot += 1LL * z[ i ] * b[ i ] ; }
	}
	printf ( "%I64d\n" , tot ) ;
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( g[ i ] == true ) {
			printf ( "%d %d\n" , ( a[ i ] / 100 ) , ( a[ i ] % 100 ) ) ;
		}
		else {
			int h = ( a[ i ] / 100 ) ;
			if ( ( a[ i ] % 100 ) != 0 ) { h ++ ; }
			printf ( "%d 0\n" , h ) ;
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
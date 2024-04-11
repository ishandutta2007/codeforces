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

#define MAXN 57
#define MAXLEN 250007

#define inf 1000000007

int n , m ;
vector < int > v[ MAXN ] ;
int a[ MAXLEN ] ;


struct node {
	long long ans ;
	long long tot ;
	long long lsum , rsum ;
	node ( ) { ans = tot = lsum = rsum = 0 ; }
};
struct node h[ MAXN ] ;

struct node merge ( struct node p1 , struct node p2 ) {
	struct node ret ;
	ret.tot = p1.tot + p2.tot ;
	ret.lsum = max ( p1.lsum , p1.tot + p2.lsum ) ;
	ret.rsum = max ( p1.rsum + p2.tot , p2.rsum ) ;
	ret.ans = max ( p1.ans , p2.ans ) ;
	ret.ans = max ( ret.ans , p1.rsum + p2.lsum ) ;
	return ret ;
}

struct segment_tree {
	struct node tr[ 3 * MAXLEN ] ;
	void init ( int where , int IL , int IR ) {
		if ( IL == IR ) {
			tr[ where ] = h[ a[ IL ] ] ;
			return ;
		}
		int mid = ( IL + IR ) / 2 ;
		init ( 2 * where , IL , mid ) ;
		init ( 2 * where + 1 , mid + 1 , IR ) ;
		tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
	}
};

segment_tree w ;

void input ( ) {
	scanf ( "%d%d" , &n , &m ) ;
	int i , j , t , z ;
	for ( i = 1 ; i <= n ; i ++ ) {
		int sz ;
		scanf ( "%d" , &sz ) ;
		v[ i ].resize ( sz ) ;
		for ( j = 0 ; j < sz ; j ++ ) {
			scanf ( "%d" , &v[ i ][ j ] ) ;
		}
		for ( j = 0 ; j < sz ; j ++ ) {
			h[ i ].tot += v[ i ][ j ] ;
		}
		h[ i ].ans = h[ i ].lsum = h[ i ].rsum = -inf ;
		long long cur = 0 ;
		for ( j = 0 ; j < sz ; j ++ ) {
			//if ( h[ i ].lsum < cur ) { h[ i ].lsum = cur ; }
			cur += v[ i ][ j ] ;
			if ( h[ i ].lsum < cur ) { h[ i ].lsum = cur ; }			
		}
		cur = 0 ;
		for ( j = sz - 1 ; j >= 0 ; j -- ) {
			//if ( h[ i ].rsum < cur ) { h[ i ].rsum = cur ; }
			cur += v[ i ][ j ] ;
			if ( h[ i ].rsum < cur ) { h[ i ].rsum = cur ; }
		}
		for ( j = 0 ; j < sz ; j ++ ) {
			cur = 0 ;
			for ( t = j ; t < sz ; t ++ ) {
				//if ( h[ i ].ans < cur ) { h[ i ].ans = cur ; }
				cur += v[ i ][ t ] ;
				if ( h[ i ].ans < cur ) { h[ i ].ans = cur ; }
			}
		}
	}
	for ( i = 1 ; i <= m ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
}

void solve ( ) {
	w.init ( 1 , 1 , m ) ;
	cout << w.tr[ 1 ].ans << "\n" ;
}

int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
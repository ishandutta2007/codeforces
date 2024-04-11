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

#define MAXN 300007

int n , q ;
pair < int , int > a[ MAXN ] ;

vector < int > st[ 10 * MAXN ] ;

vector < int > merge ( vector < int > v1 , vector < int > v2 ) {
	int i , j ;
	i = j = 0 ;
	int sz1 = v1.size ( ) ;
	int sz2 = v2.size ( ) ;
	vector < int > ret ;
	while ( i < sz1 || j < sz2 ) {
		if ( i == sz1 ) {
			ret.push_back ( v2[ j ] ) ;
			j ++ ;
		}
		else if ( j == sz2 ) {
			ret.push_back ( v1[ i ] ) ;
			i ++ ;
		}
		else {
			if ( v1[ i ] < v2[ j ] ) {
				ret.push_back ( v1[ i ] ) ;
				i ++ ;
			}
			else {
				ret.push_back ( v2[ j ] ) ;
				j ++ ;
			}
		}
	}
	return ret ;
}

struct Tree {
	vector < int > tr[ 10 * MAXN ] ;
	void init ( int where , int IL , int IR ) {
		if ( IL == IR ) {
			tr[ where ] = st[ IL ] ;
			return ;
		}
		int mid = ( IL + IR ) / 2 ;
		init ( 2 * where , IL , mid ) ;
		init ( 2 * where + 1 , mid + 1 , IR ) ;
		tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
	}
	int query ( int where , int IL , int IR , int CURL , int CURR , int val ) {
		if ( IL > IR ) { return 0 ; }
		if ( CURL > CURR ) { return 0 ; }
		if ( IR < CURL || CURR < IL ) { return 0 ; }
		if ( CURL <= IL && IR <= CURR ) {
			return ( upper_bound ( tr[ where ].begin ( ) , tr[ where ].end ( ) , val ) - tr[ where ].begin ( ) ) ;
		}
		int mid = ( IL + IR ) / 2 ;
		return ( query ( 2 * where , IL , mid , CURL , CURR , val ) + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ) ;
	}
};

Tree w ;

void input ( ) {
	scanf ( "%d%d" , &n , &q ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
		st[ a[ i ].first ].push_back ( a[ i ].second ) ;
	}
	for ( i = 1 ; i <= 1000000 ; i ++ ) {
		if ( st[ i ].size ( ) == 0 ) { continue ; }
		sort ( st[ i ].begin ( ) , st[ i ].end ( ) ) ;
	}
	w.init ( 1 , 1 , 1000000 ) ;
}

void solve ( ) {
	int sz ;
	int i ;
	int x ;
	int lst = 0 ;		
	while ( q != 0 ) {
		q -- ;
		scanf ( "%d" , &sz ) ;
		lst = 0 ;
		int ans = 0 ;
		while ( sz != 0 ) {
			sz -- ;
			scanf ( "%d" , &x ) ;
			ans += w.query ( 1 , 1 , 1000000 , lst + 1 , x - 1 , x - 1 ) ;
			lst = x ; 
		}
		ans += w.query ( 1 , 1 , 1000000 , lst + 1 , 1000000 , 1000000 ) ;
		ans = n - ans ;
		printf ( "%d\n" , ans ) ;
	}
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
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

int n , q ;
vector < int > v[ MAXN ] ;

int pos_in_tree[ MAXN ] ;
int root[ MAXN ] ;

int st[ MAXN ] ;
int en[ MAXN ] ;

int lvl[ MAXN ] ;
int LEAVES ;
struct Tree {
	int tr[ 3 * MAXN ] ;
	int lazy[ 3 * MAXN ] ;
	void init ( int where , int IL , int IR ) {
		tr[ where ] = 0 ;
		lazy[ where ] = 0 ;	
		if ( IL == IR ) {
			return ;
		}
		int mid = ( IL + IR ) / 2 ;
		init ( 2 * where , IL , mid ) ;
		init ( 2 * where + 1 , mid + 1 , IR ) ;
	}
	void push_lazy ( int where ) {
		tr[ where ] += lazy[ where ] ;
		if ( where < LEAVES ) {
			lazy[ 2 * where ] += lazy[ where ] ;
			lazy[ 2 * where + 1 ] += lazy[ where ] ;
		}
		lazy[ where ] = 0 ;
	}
	void update ( int where , int IL , int IR , int CURL , int CURR , int val ) {
		if ( CURL > CURR ) { return ; }
		push_lazy ( where ) ;
		if ( IR < CURL || CURR < IL ) { return ; }
		if ( CURL <= IL && IR <= CURR ) {
			lazy[ where ] += val ;

			push_lazy ( where ) ;
			return ;
		}
		int mid = ( IL + IR ) / 2 ;
		update ( 2 * where , IL , mid , CURL , CURR , val ) ;
		update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
		tr[ where ] = tr[ 2 * where ] + tr[ 2 * where + 1 ] ;
	}
	int query ( int where , int IL , int IR , int CURL , int CURR ) {
		if ( CURL > CURR ) { return 0 ; }
		push_lazy ( where ) ;		
		if ( IR < CURL || CURR < IL ) { return 0 ; }
		if ( CURL <= IL && IR <= CURR ) {
			return tr[ where ] ;
		}
		int mid = ( IL + IR ) / 2 ;
		return ( query ( 2 * where , IL , mid , CURL , CURR ) + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
	}
};

Tree w1 , w2 ;

void input ( ) {
	scanf ( "%d%d" , &n , &q ) ;
	int i ;
	for ( i = 1 ; i < n ; i ++ ) {
		int x , y ;
		scanf ( "%d%d" , &x , &y ) ;
		v[ x ].push_back ( y ) ;
		v[ y ].push_back ( x ) ;
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		root[ i ] = -1 ;
	}
	LEAVES = 1 ;
	while ( LEAVES < n ) { LEAVES *= 2 ; }
	w1.init ( 1 , 1 , LEAVES ) ;
	w2.init ( 1 , 1 , LEAVES ) ;
}

void solve ( ) {
	int i ;
	pos_in_tree[ 1 ] = 1 ;
	int sz = 0 ;
	int id = 2 ;
	lvl[ 1 ] = 1 ;
	sz = v[ 1 ].size ( ) ;
	for ( i = 0 ; i < sz ; i ++ ) {
		int u = v[ 1 ][ i ] ;
		st[ u ] = id ;
		lvl[ u ] = 2 ; 
		while ( 1 ) {
			root[ u ] = v[ 1 ][ i ] ;
			pos_in_tree[ u ] = id ;
			id ++ ;
			if ( v[ u ].size ( ) == 1 ) { break ; }
			if ( lvl[ v[ u ][ 0 ] ] == 0 ) {
				lvl[ v[ u ][ 0 ] ] = lvl[ u ] + 1 ;
				u = v[ u ][ 0 ] ;
			}
			else {
				lvl[ v[ u ][ 1 ] ] = lvl[ u ] + 1 ;
				u = v[ u ][ 1 ] ;
			}
		}
		en[ v[ 1 ][ i ] ] = ( id - 1 ) ;
	}
	int type ;
	int x , y , z ;
	while ( q != 0 ) {
		q -- ;
		scanf ( "%d" , &type ) ;
		if ( type == 0 ) {
			scanf ( "%d%d%d" , &x , &y , &z ) ;
			if ( ( lvl[ x ] - 2 ) >= z ) {
				int id = root[ x ] ;
				int h1 = pos_in_tree[ x ] - z ;
				int h2 = min ( pos_in_tree[ x ] + z , en[ id ] ) ;
				w1.update ( 1 , 1 , LEAVES , h1 , h2 , y ) ;
			}
			else {
				int val = z - ( lvl[ x ] - 2 ) ;
				w2.update ( 1 , 1 , LEAVES , 1 , val , y ) ;
				int id = root[ x ] ;
				int h1 = pos_in_tree[ x ] ;
				h1 = h1 + ( val + 1 - lvl[ x ] ) ;
				int h2 = min ( pos_in_tree[ x ] + z , en[ id ] ) ;
				w1.update ( 1 , 1 , LEAVES , h1 , h2 , y ) ;
			}
		}
		else {
			scanf ( "%d" , &x ) ;
			printf ( "%d\n" , w1.query ( 1 , 1 , LEAVES , pos_in_tree[ x ] , pos_in_tree[ x ] ) + w2.query ( 1 , 1 , LEAVES , lvl[ x ] , lvl[ x ] ) ) ;
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
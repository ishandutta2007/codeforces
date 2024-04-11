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
vector < int > v[ MAXN ] ;

vector < pair < int , int > > tosolve[ MAXN ] ;

int subtree[ MAXN ] ;
int mxchild[ MAXN ] ;
int col[ MAXN ] ;
int ans[ MAXN ] ;

int LEAVES ; 

struct segment_tree {
	int tr[ 3 * MAXN ] ;
	void update ( int where , int val ) {
		while ( where != 0 ) {
			tr[ where ] += val ;
			where /= 2 ;
		}
	}
	int query ( int where ) {
		int ret = 0 ;
		if ( where < LEAVES ) { return 0 ; }
		if ( where >= 2 * LEAVES ) { return tr[ 1 ] ; }
		while ( where != 0 ) {
			if ( (where&(where-1)) == 0 ) {
				ret += tr[ where ] ;
				break ;
			}
			if ( ( where % 2 ) == 0 ) {
				ret += tr[ where ] ;
				where -- ;
			}
			else { where /= 2 ; }
		}
		return ret ;
	}
};

segment_tree w ;

void add ( int id , int val ) {
	if ( col[ id ] != 0 ) { w.update ( LEAVES + col[ id ] - 1 , -1 ) ; }
	col[ id ] += val ;
	if ( col[ id ] != 0 ) { w.update ( LEAVES + col[ id ] - 1 , 1 ) ; }
}

void add_rec ( int vertex , int prv , int val ) {
	int sz = v[ vertex ].size ( ) ;
	add ( a[ vertex ] , val ) ;
	int i ;
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( v[ vertex ][ i ] == prv ) { continue ; }
		add_rec ( v[ vertex ][ i ] , vertex , val ) ;
	}
}

void dfs_init ( int vertex , int prv ) {
	int sz = v[ vertex ].size ( ) ;
	int i ;
	subtree[ vertex ] = 1 ;
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( v[ vertex ][ i ] == prv ) { continue ; }
		dfs_init ( v[ vertex ][ i ] , vertex ) ;
		subtree[ vertex ] += subtree[ v[ vertex ][ i ] ] ;
		if ( subtree[ v[ vertex ][ i ] ] > subtree[ mxchild[ vertex ] ] ) {
			mxchild[ vertex ] = v[ vertex ][ i ] ;
		}
	}
}

void dfs ( int vertex , int prv , bool fl ) {
	int sz = v[ vertex ].size ( ) ;
	int i , j ;
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( v[ vertex ][ i ] == prv ) { continue ; }
		if ( mxchild[ vertex ] != v[ vertex ][ i ] ) {
			dfs ( v[ vertex ][ i ] , vertex , false ) ;
		}
	}
	if ( mxchild[ vertex ] != -1 ) { dfs ( mxchild[ vertex ] , vertex , true ) ; }
	add ( a[ vertex ] , 1 ) ;
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( v[ vertex ][ i ] == prv ) { continue ; }
		if ( v[ vertex ][ i ] == mxchild[ vertex ] ) { continue ; }
		add_rec ( v[ vertex ][ i ] , vertex , 1 ) ;
	}
	int u = tosolve[ vertex ].size ( ) ;
	for ( i = 0 ; i < u ; i ++ ) {
		ans[ tosolve[ vertex ][ i ].second ] = w.tr[ 1 ] - w.query ( LEAVES + tosolve[ vertex ][ i ].first - 2 ) ;
	}
	if ( fl == true ) { return ; }
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( v[ vertex ][ i ] == prv ) { continue ; }
		add_rec ( v[ vertex ][ i ] , vertex , -1 ) ;
	}
	add ( a[ vertex ] , -1 ) ;
}

void input ( ) {
	scanf ( "%d%d" , &n , &q ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
		mxchild[ i ] = -1 ;
	}
	for ( i = 1 ; i < n ; i ++ ) {
		int x , y ;
		scanf ( "%d%d" , &x , &y ) ;
		v[ x ].push_back ( y ) ;
		v[ y ].push_back ( x ) ;
	}
	for ( i = 1 ; i <= q ; i ++ ) {
		int x , y ;
		scanf ( "%d%d" , &x , &y ) ;
		tosolve[ x ].push_back ( make_pair ( y , i ) ) ;
	}
}

void solve ( ) {
	LEAVES = 1 ;
	while ( LEAVES < n ) { LEAVES *= 2 ; }
	dfs_init ( 1 , -1 ) ;
	dfs ( 1 , -1 , false ) ;
	int i ;
	for ( i = 1 ; i <= q ; i ++ ) { printf ( "%d\n" , ans[ i ] ) ; }
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
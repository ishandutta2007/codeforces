#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<map>
using namespace std ;

#define MAXN 200007

int n , q ;
vector < int > v[ MAXN ] ;

int stval[ MAXN ] ;

int lvl[ MAXN ] ;
vector < int > ord ;
int st[ MAXN ] ;
int en[ MAXN ] ;

int LEAVES ;

struct segment_tree {
	int tr[ 6 * MAXN ] ;
	void update ( int where , int IL , int IR , int CURL , int CURR , int val ) {
		if ( CURL > CURR ) { return ; }
		if ( IL > IR ) { return ; }
		if ( IR < CURL || CURR < IL ) { return ; }
		if ( CURL <= IL && IR <= CURR ) {
			tr[ where ] += val ;
			return ;
		}
		int mid = ( IL + IR ) / 2 ;
		update ( 2 * where , IL , mid , CURL , CURR , val ) ;
		update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
	}
	int query ( int where ) {
		int ret = 0 ;
		while ( where != 0 ) {
			ret += tr[ where ] ;
			where /= 2 ;
		}
		return ret ;
	}
};

segment_tree odd , even ;

void dfs ( int vertex , int prv ) {
	ord.push_back ( vertex ) ;
	st[ vertex ] = ord.size ( ) ;
	int i , sz ;
	sz = v[ vertex ].size ( ) ;
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( v[ vertex ][ i ] == prv ) { continue ; }
		lvl[ v[ vertex ][ i ] ] = lvl[ vertex ] + 1 ;
		dfs ( v[ vertex ][ i ] , vertex ) ;
	}
	ord.push_back ( vertex ) ;
	en[ vertex ] = ord.size ( ) ;
}

void input ( ) {
	scanf ( "%d%d" , &n , &q ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &stval[ i ] ) ;
	}
	for ( i = 1 ; i < n ; i ++ ) {
		int x , y ; 
		scanf ( "%d%d" , &x , &y ) ;
		v[ x ].push_back ( y ) ;
		v[ y ].push_back ( x ) ;
	}
}

void solve ( ) {
	dfs ( 1 , -1 ) ;
	LEAVES = 1 ;
	while ( LEAVES < ord.size ( ) ) { LEAVES *= 2 ; }
	int type , x , y ;
	while ( q != 0 ) {
		q -- ;
		scanf ( "%d" , &type ) ;
		if ( type == 1 ) {
			scanf ( "%d%d" ,  &x , &y ) ;
			if ( ( lvl[ x ] % 2 ) == 0 ) {
				even.update ( 1 , 1 , LEAVES , st[ x ] , en[ x ] , y ) ;
				odd.update ( 1 , 1 , LEAVES , st[ x ] , en[ x ] , -y ) ;
			}
			else {
				odd.update ( 1 , 1 , LEAVES , st[ x ] , en[ x ] , y ) ;
				even.update ( 1 , 1 , LEAVES , st[ x ] , en[ x ] , -y ) ;				
			}
		}
		else {
			scanf ( "%d" , &x ) ;
			if ( ( lvl[ x ] % 2 ) == 0 ) { printf ( "%d\n" , stval[ x ] + even.query ( LEAVES + st[ x ] - 1 ) ) ; }
			else { printf ( "%d\n" , stval[ x ] + odd.query ( LEAVES + st[ x ] - 1 ) ) ; }
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
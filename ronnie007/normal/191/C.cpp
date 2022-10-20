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

#define MAXN 100007

int n ;
vector < pair < int , int > > v[ MAXN ] ;

int lca[ MAXN ][ 22 ] ;
int lvl[ MAXN ] ;

int add[ MAXN ] ;
int cur[ MAXN ] ;

int ans[ MAXN ] ;

void dfs ( int vertex , int prv ) {
	int i ;
	int sz = v[ vertex ].size ( ) ;
	for ( i = 1 ; i <= 20 ; i ++ ) {
		lca[ vertex ][ i ] = lca[ lca[ vertex ][ i - 1 ] ][ i - 1 ] ;
	}
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( v[ vertex ][ i ].first == prv ) { continue ; }
		lvl[ v[ vertex ][ i ].first ] = lvl[ vertex ] + 1 ;
		lca[ v[ vertex ][ i ].first ][ 0 ] = vertex ;
		dfs ( v[ vertex ][ i ].first , vertex ) ;
	}
}

int LCA ( int x , int y ) {
	int i ;
	for ( i = 20 ; i >= 0 ; i -- ) {
		int u = (1<<i) ;
		if ( lvl[ x ] - u >= lvl[ y ] ) {
			x = lca[ x ][ i ] ;
		}
		if ( lvl[ y ] - u >= lvl[ x ] ) {
			y = lca[ y ][ i ] ;
		}
	}
	for ( i = 20 ; i >= 0 ; i -- ) {
		if ( lca[ x ][ i ] != lca[ y ][ i ] ) {
			x = lca[ x ][ i ] ;
			y = lca[ y ][ i ] ;
		}
	}
	if ( x != y ) { x = lca[ x ][ 0 ] ; }
	return x ;
}

void mark ( int vertex , int prv ) {
	int i , sz ;
	sz = v[ vertex ].size ( ) ;
	cur[ vertex ] = add[ vertex ] ;
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( v[ vertex ][ i ].first == prv ) { continue ; }
		mark ( v[ vertex ][ i ].first , vertex ) ;
		ans[ v[ vertex ][ i ].second ] = cur[ v[ vertex ][ i ].first ] ;
		cur[ vertex ] += cur[ v[ vertex ][ i ].first ] ;
	}
}

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i < n ; i ++ ) {
		int x , y ;
		scanf ( "%d%d" , &x , &y ) ;
		v[ x ].push_back ( make_pair ( y , i ) ) ;
		v[ y ].push_back ( make_pair ( x , i ) ) ;
	}
}

void solve ( ) {
	dfs ( 1 , -1 ) ;
	int q ;
	int x , y ;
	scanf ( "%d" , &q ) ;
	while ( q != 0 ) {
		q -- ;
		scanf ( "%d%d" , &x , &y ) ;
		int u = LCA ( x , y ) ;
		add[ u ] -= 2 ;
		add[ x ] ++ ;
		add[ y ] ++ ;
	}
	mark ( 1 , -1 ) ;
	int i ;
	for ( i = 1 ; i < n ; i ++ ) {
		printf ( "%d" , ans[ i ] ) ;
		if ( i == ( n - 1 ) ) { printf ( "\n" ) ; }
		else { printf ( " " ) ; }
	}
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
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

#define MAXN 1000007

int n , q ;
vector < int > v[ MAXN ] ;

int lca[ MAXN ][ 22 ] ;
int lvl[ MAXN ] ;

void dfs ( int vertex , int lst ) {
	int i , sz ;
	for ( i = 1 ; i <= 20 ; i ++ ) {
		lca[ vertex ][ i ] = lca[ lca[ vertex ][ i - 1 ] ][ i - 1 ] ;
	}
	sz = v[ vertex ].size ( ) ;
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( v[ vertex ][ i ] == lst ) { continue ; }
		lvl[ v[ vertex ][ i ] ] = lvl[ vertex ] + 1 ;
		lca[ v[ vertex ][ i ] ][ 0 ] = vertex ;
		dfs ( v[ vertex ][ i ] , vertex ) ;
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

int dist ( int x , int y ) {
	int f = LCA ( x , y ) ;
	return ( lvl[ x ] + lvl[ y ] - 2 * lvl[ f ] ) ;
}

void input ( ) {
	scanf ( "%d" , &q ) ;
	int i ;
	for ( i = 2 ; i <= 4 ; i ++ ) {
		v[ 1 ].push_back ( i ) ;
		v[ i ].push_back ( 1 ) ;
	}
	n = 4 ;
	for ( i = 1 ; i <= q ; i ++ ) {
		int x ;
		scanf ( "%d" , &x ) ;
		v[ x ].push_back ( n + 1 ) ;
		v[ n + 1 ].push_back ( x ) ;
		v[ x ].push_back ( n + 2 ) ;
		v[ n + 2 ].push_back ( x ) ;
		n += 2 ;
	}
}

void solve ( ) {
	dfs ( 1 , -1 ) ;
	int w1 , w2 ;
	int i ;
	w1 = 2 ;
	w2 = 3 ;
	int id = 5 ;
	for ( i = 1 ; i <= q ; i ++ ) {
		int u1 , u2 , u3 ;
		u1 = dist ( w1 , w2 ) ;
		u2 = dist ( w1 , id ) ;
		u3 = dist ( w2 , id ) ;
		if ( u2 > u1 && u2 >= u3 ) {
			w2 = id ;
		}
		else if ( u3 > u1 && u3 > u2 ) {
			w1 = id ;
		}
		id ++ ;
		u1 = dist ( w1 , w2 ) ;
		u2 = dist ( w1 , id ) ;
		u3 = dist ( w2 , id ) ;
		if ( u2 > u1 && u2 >= u3 ) {
			w2 = id ;
		}
		else if ( u3 > u1 && u3 > u2 ) {
			w1 = id ;
		}
		id ++ ;
		printf ( "%d\n" , dist ( w1 , w2 ) ) ;
	}
}

int main ( ) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
#include<set>
using namespace std ;

#define MAXN 200007

int n , q ;
struct query {
	int type ;
	int x , y ;
};

query a[ MAXN ] ;

vector < int > v[ MAXN ] ;
int prv[ MAXN ][ 22 ] ;
int lvl[ MAXN ] ;
int lst[ MAXN ] ;
bool root[ MAXN ] ;

int revid[ MAXN ] ;

int ans[ MAXN ] ;

vector < int > tosolve[ MAXN ] ;

void dfs ( int vertex , int y ) {
	int i ;
	for ( i = 1 ; i <= 20 ; i ++ ) {
		prv[ vertex ][ i ] = prv[ prv[ vertex ][ i - 1 ] ][ i - 1 ] ;
	}
	int sz = v[ vertex ].size ( ) ;
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( v[ vertex ][ i ] == y ) { continue ; }
		prv[ v[ vertex ][ i ] ][ 0 ] = vertex ;
		lvl[ v[ vertex ][ i ] ] = lvl[ vertex ] + 1 ;
		dfs ( v[ vertex ][ i ] , vertex ) ;
	}
}

int LCA ( int x , int y ) {
	int i ;
	for ( i = 20 ; i >= 0 ; i -- ) {
		if ( lvl[ x ] - (1<<i) >= lvl[ y ] ) {
			x = prv[ x ][ i ] ;
		}
		if ( lvl[ y ] - (1<<i) >= lvl[ x ] ) {
			y = prv[ y ][ i ] ;
		}
	}
	for ( i = 20 ; i >= 0 ; i -- ) {
		if ( prv[ x ][ i ] != prv[ y ][ i ] ) {
			x = prv[ x ][ i ] ;
			y = prv[ y ][ i ] ;
		}
	}
	if ( x != y ) { x = prv[ x ][ 0 ] ; }
	return x ;
}

int find ( int x ) {
	if ( lst[ x ] == -1 ) { return x ; }
	int y = find ( lst[ x ] ) ;
	lst[ x ] = y ;
	return y ;
}

void UNITE ( int x , int y ) {
	int k1 = find ( x ) ;
	int k2 = find ( y ) ;
	if ( k1 != k2 ) { lst[ k1 ] = k2 ; }
}

void input ( ) {
	scanf ( "%d%d" , &n , &q ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		root[ i ] = true ;
		lst[ i ] = -1 ;
	}
	int tot = 1 ;
	for ( i = 1 ; i <= q ; i ++ ) {
		scanf ( "%d" , &a[ i ].type ) ;
		if ( a[ i ].type == 1 ) {
			scanf ( "%d%d" , &a[ i ].x , &a[ i ].y ) ;
			root[ a[ i ].x ] = false ;
			v[ a[ i ].y ].push_back ( a[ i ].x ) ;
			v[ a[ i ].x ].push_back ( a[ i ].y ) ;
		}
		else if ( a[ i ].type == 2 ) {
			scanf ( "%d" , &a[ i ].x ) ;
			revid[ tot ] = i ;
			tot ++ ;
		}
		else {
			scanf ( "%d%d" , &a[ i ].x , &a[ i ].y ) ;
			int h = revid[ a[ i ].y ] ;
			tosolve[ h ].push_back ( i ) ;
		}
	}
}

void solve ( ) {
	int st = -1 ;
	int i , j ;
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( root[ i ] == true ) { dfs ( i , -1 ) ; }
	}
	for ( i = 1 ; i <= q ; i ++ ) {
		if ( a[ i ].type == 1 ) {
			UNITE ( a[ i ].x , a[ i ].y ) ;
		}
		else if ( a[ i ].type == 2 ) {
			int sz = tosolve[ i ].size ( ) ;
			for ( j = 0 ; j < sz ; j ++ ) {
				int w1 , w2 ;
				w1 = a[ i ].x ;				
				w2 = a[ tosolve[ i ][ j ] ].x ;
				int u = LCA ( w1 , w2 ) ;
				int k1 = find ( w1 ) ;
				int k2 = find ( w2 ) ;
				if ( k1 == k2 && u == w2 ) { ans[ tosolve[ i ][ j ] ] = 1 ; }
			}
		}
		else { continue ; }
	}
	for ( i = 1 ; i <= q ; i ++ ) {
		if ( a[ i ].type != 3 ) { continue ; }
		if ( ans[ i ] == 1 ) { printf ( "YES\n" ) ; }
		else { printf ( "NO\n" ) ; }
	}
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
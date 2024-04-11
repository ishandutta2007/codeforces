#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std ;

#define MAXN 300007

int n , q ;
int par[ MAXN ] ;
vector < int > v[ MAXN ] ;

int sz[ MAXN ] ;
int mxdp[ MAXN ] ;
int cntr[ MAXN ] ;

void dfs ( int vertex , int prv ) {
	int i ; 
	int m = v[ vertex ].size ( ) ;
	int id = 0 ;
	for ( i = 0 ; i < m ; i ++ ) {
		if ( v[ vertex ][ i ] == prv ) { continue ; }
		dfs ( v[ vertex ][ i ] , vertex ) ;
		sz[ vertex ] += ( sz[ v[ vertex ][ i ] ] + 1 ) ;
		if ( ( sz[ v[ vertex ][ i ] ] + 1 ) > mxdp[ vertex ] ) {
			mxdp[ vertex ] = ( sz[ v[ vertex ][ i ] ] + 1 ) ;
			id = v[ vertex ][ i ] ;
		}
	}
	if ( m == 1 && prv != -1 ) { cntr[ vertex ] = vertex ; return ; }
	int h = cntr[ id ] ;
	int sr = ( sz[ vertex ] + 1 ) / 2 ;
	while ( h != vertex && ( mxdp[ h ] > sr || ( sz[ vertex ] - sz[ h ] ) > sr ) ) { h = par[ h ] ; }
	cntr[ vertex ] = h ;
}

void input ( ) {
	scanf ( "%d%d" , &n , &q ) ;
	int i ;
	for ( i = 2 ; i <= n ; i ++ ) {
		scanf ( "%d" , &par[ i ] ) ;
		v[ par[ i ] ].push_back ( i ) ;
		v[ i ].push_back ( par[ i ] ) ;
	}
}

void solve ( ) {
	dfs ( 1 , -1 ) ;
	int x ;
	while ( q != 0 ) {
		q -- ;
		scanf ( "%d" , &x ) ;
		printf ( "%d\n" , cntr[ x ] ) ;
	}
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std ;

#define MAXN 1007

int n , m ;
vector < int > v[ MAXN ] ;
int used[ MAXN ] ;

void dfs ( int vertex ) {
	used[ vertex ] = 1 ;
	int sz = v[ vertex ].size ( ) ;
	int i ;
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( used[ v[ vertex ][ i ] ] == 0 ) { dfs ( v[ vertex ][ i ] ) ; }
	}
}

void input ( ) {
	scanf ( "%d%d" , &n , &m ) ;
	int i ;
	int x , y ;
	for ( i = 1 ; i <= m ; i ++ ) {
		scanf ( "%d%d" , &x , &y ) ;
		v[ x ].push_back ( y ) ;
		v[ y ].push_back ( x ) ;
	}
}

void solve ( ) {
	if ( m != ( n - 1 ) ) { printf ( "no\n" ) ; return ; }
	dfs ( 1 ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( used[ i ] == 0 ) { printf ( "no\n" ) ; return ; }
	}
	printf ( "yes\n" ) ;
}

int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
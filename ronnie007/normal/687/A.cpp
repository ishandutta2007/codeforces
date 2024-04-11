#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
using namespace std ;

#define MAXN 100007

int n , m ;
vector < int > v[ MAXN ] ;

int col[ MAXN ] ;

bool crap ;

vector < int > ans[ 3 ] ; 

void dfs ( int vertex ) {
	int i ;
	int sz = v[ vertex ].size ( ) ;
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( col[ v[ vertex ][ i ] ] == col[ vertex ] ) { crap = true ; }
		if ( col[ v[ vertex ][ i ] ] != 0 ) { continue ; }
		col[ v[ vertex ][ i ] ] = ( 3 - col[ vertex ] ) ;
		ans[ col[ v[ vertex ][ i ] ] ].push_back ( v[ vertex ][ i ] ) ;
		dfs ( v[ vertex ][ i ] ) ;
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
	int i , j ;
	crap = false ; 
	for ( i = 1 ; i <= n ; i ++ ) { col[ i ] = 0 ; }
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( col[ i ] == 0 ) {
			col[ i ] = 1 ;
			ans[ 1 ].push_back ( i ) ; 
			dfs ( i ) ;
		}
	}
	if ( crap == true ) { printf ( "-1\n" ) ; return ; }
	for ( i = 1 ; i <= 2 ; i ++ ) {
		int sz = ans[ i ].size ( ) ;
		printf ( "%d\n" , sz ) ;
		for ( j = 0 ; j < sz ; j ++ ) {
			printf ( "%d" , ans[ i ][ j ] ) ; 
			if ( j == sz - 1 ) { printf ( "\n" ) ; }
			else { printf ( " " ) ; }
		}
	}
}


int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
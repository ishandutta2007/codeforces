#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#include<iomanip>
using namespace std ;

#define MAXN 100007

int n ;
vector < int > v[ MAXN ] ;

int subtree[ MAXN ] ;
double ans[ MAXN ] ;

void dfs ( int vertex ) {
	int i , sz ;
	sz = v[ vertex ].size ( ) ;
	subtree[ vertex ] = 1 ;
	for ( i = 0 ; i < sz ; i ++ ) {
		dfs ( v[ vertex ][ i ] ) ;
		subtree[ vertex ] += subtree[ v[ vertex ][ i ] ] ;
	}
	for ( i = 0 ; i < sz ; i ++ ) {
		ans[ v[ vertex ][ i ] ] = ( subtree[ vertex ] - 1 -  subtree[ v[ vertex ][ i ] ] ) / 2.000 + 1.000000 ;
	}
}

void get_ans ( int vertex ) {
	int i , sz ;
	sz = v[ vertex ].size ( ) ;
	for ( i = 0 ; i < sz ; i ++ ) {
		ans[ v[ vertex ][ i ] ] += ans[ vertex ] ;
		get_ans ( v[ vertex ][ i ] ) ;
	}
}

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 2 ; i <= n ; i ++ ) {
		int x ;
		scanf ( "%d" , &x ) ;
		v[ x ].push_back ( i ) ;
	}
}

void solve ( ) {
	ans[ 1 ] = 1.0000000 ;
	dfs ( 1 ) ;
	get_ans ( 1 ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		printf ( "%.12lf" , ans[ i ] ) ;
		if ( i == n ) { printf ( "\n" ) ; }
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
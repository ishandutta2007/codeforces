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
#include<cstdlib>
using namespace std ;

#define MAXN 1000007

int n ;
int a[ MAXN ] ;
vector < int > v[ MAXN ] ;

int root ;

int subtree[ MAXN ] ;
int has1[ MAXN ] ;
int id[ MAXN ] ;

int sm ;

void init ( int vertex ) {
	int i ;
	int sz = v[ vertex ].size ( ) ;
	subtree[ vertex ] = a[ vertex ] ;
	int br = 0 ;
	for ( i = 0 ; i < sz ; i ++ ) {
		init ( v[ vertex ][ i ] ) ;
		subtree[ vertex ] += subtree[ v[ vertex ][ i ] ] ;
		if ( has1[ v[ vertex ][ i ] ] == true ) {
			has1[ vertex ] = true ;
			br ++ ;
			if ( br == 1 ) { id[ vertex ] = id[ v[ vertex ][ i ] ] ; }
			else {
				printf ( "%d %d\n" , id[ vertex ] , id[ v[ vertex ][ i ] ] ) ;
				exit ( 0 ) ;
			}
		}
	}
	if ( vertex == root ) { return ; }
	if ( subtree[ vertex ] == 2 * sm && has1[ vertex ] == true ) {
		printf ( "%d %d\n" , vertex , id[ vertex ] ) ;
		exit ( 0 ) ;
	}
	if ( has1[ vertex ] == false ) {
		if ( subtree[ vertex ] == sm ) { has1[ vertex ] = true ; id[ vertex ] = vertex ; }
	}
}


void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		int x ;
		scanf ( "%d%d" , &x , &a[ i ] ) ;
		sm += a[ i ] ;
		if ( x != 0 ) { v[ x ].push_back ( i ) ; }
		else { root = i ; }
	}
}

void solve ( ) {
	if ( ( sm % 3 ) != 0 ) { printf ( "-1\n" ) ; return ; }
	sm = sm / 3 ;
	init ( root ) ;
	printf ( "-1\n" ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
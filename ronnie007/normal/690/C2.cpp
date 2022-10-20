#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std ;

#define MAXN 500007

int n , m ;
vector < int > v[ MAXN ] ;
int used[ MAXN ] ;


void dfs ( int vertex , int pr ) {
	used[ vertex ] = used[ pr ] + 1 ;
	int i ;
	int sz = v[ vertex ].size ( ) ;
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( used[ v[ vertex ][ i ] ] == 0 ) {
			dfs ( v[ vertex ][ i ] , vertex ) ;
		}
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
	int i ;
	dfs ( 1 , 0 ) ;
	int mx = -1 ;
	int id = -1 ; 
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( mx < used[ i ] ) { mx = used[ i ] ; id = i ; }
		used[ i ] = 0 ; 
	}
	dfs ( id , 0 ) ;
	mx = -1 ;
	id = -1 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( mx < used[ i ] ) { mx = used[ i ] ; id = i ; }
		used[ i ] = 0 ; 
	}
	printf ( "%d\n" , ( mx - 1 ) ) ;
}

int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;
int dist[ MAXN ] ;



void bfs ( int x ) {
	queue < int > q ;
	q.push ( x ) ;
	while ( q.empty ( ) == false ) {
		x = q.front ( ) ;
		q.pop ( ) ;
		if ( dist[ a[ x ] ] == 0 ) {
			dist[ a[ x ] ] = dist[ x ] + 1 ;
			q.push ( a[ x ] ) ;
		}
		if ( x != n && dist[ x + 1 ] == 0 ) {
			dist[ x + 1 ] = dist[ x ] + 1 ;
			q.push ( x + 1 ) ;
		}
		if ( x != 1 && dist[ x - 1 ] == 0 ) {
			dist[ x - 1 ] = dist[ x ] + 1 ;
			q.push ( x - 1 ) ;
		}
	}
}

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
}

void solve ( ) {
	dist[ 1 ] = 1 ;
	bfs ( 1 ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		printf ( "%d" , ( dist[ i ] - 1 ) ) ;
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
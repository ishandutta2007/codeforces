#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

#define inf 1000000007
#define MAXN 407

int n , m ;
vector < int > v[ MAXN ] ;
pair < int , int > a[ MAXN * MAXN ] ; 
int g[ MAXN ][ MAXN ] ;
int dist[ MAXN ] ;


void bfs ( ) {
	queue < int > q ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		dist[ i ] = -1 ;
	}
	dist[ 1 ] = 0 ;
	q.push ( 1 ) ;
	while ( q.empty ( ) == false ) {
		int u = q.front ( ) ;
		q.pop ( ) ;
		int sz = v[ u ].size ( ) ;
		for ( i = 0 ; i < sz ; i ++ ) {
			int h = v[ u ][ i ] ;
			if ( dist[ h ] == -1 ) {
				dist[ h ] = dist[ u ] + 1 ; 
				q.push ( h ) ;
			}
		}
	}
}

void input ( ) ;
void solve ( ) ;


int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ; 
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( ) {
	scanf ( "%d%d" , &n , &m ) ;
	int i ;
	int u = 0 ;
	for ( i = 1 ; i <= m ; i ++ ) {
		scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
		if ( a[ i ].first > a[ i ].second ) { swap ( a[ i ].first , a[ i ].second ) ; }
		g[ a[ i ].first ][ a[ i ].second ] = 1 ;
		if ( a[ i ].first == 1 && a[ i ].second == n ) { u = 1 ; }
	}
	if ( u == 0 ) {
		for ( i = 1 ; i <= m ; i ++ ) {
			v[ a[ i ].first ].push_back ( a[ i ].second ) ;
			v[ a[ i ].second ].push_back ( a[ i ].first ) ;
		}
	}
	else {
		int j ;
		for ( i = 1 ; i <= n ; i ++ ) {
			for ( j = i + 1 ; j <= n ; j ++ ) {
				if ( g[ i ][ j ] == 0 ) {
					v[ i ].push_back ( j ) ;
					v[ j ].push_back ( i ) ;
				}
			}
		}
	}
}

void solve ( ) {
	bfs ( ) ;
	printf ( "%d\n" , dist[ n ] ) ;
}
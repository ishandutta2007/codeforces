#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std ;

#define MAXN 500007

int n , m ;

struct edge {
	int x , y ;
};
vector < struct edge > v ;
int ans[ MAXN ] ;


int id1 , id2 ;
int dist[ MAXN ] ;
int diam ;
int pr[ MAXN ][ 22 ] ;

int LCA ( int x , int y ) {
	int i ;
	for ( i = 20 ; i >= 0 ; i -- ) {
		int u = (1<<i) ;
		if ( dist[ x ] - u >= dist[ y ] ) {
			x = pr[ x ][ i ] ;
		}
		if ( dist[ y ] - u >= dist[ x ] ) {
			y = pr[ y ][ i ] ;
		}
	}
	for ( i = 20 ; i >= 0 ; i -- ) {
		int u = (1<<i) ;
		if ( pr[ x ][ i ] != pr[ y ][ i ] ) {
			x = pr[ x ][ i ] ;
			y = pr[ y ][ i ] ;
		}
	}
	if ( x != y ) { x = pr[ x ][ 0 ] ; }
	return x ;
}

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i , j ;
	struct edge u ;
	int x ;
	for ( i = 2 ; i <= n ; i ++ ) {
		scanf ( "%d" , &x ) ;
		dist[ i ] = dist[ x ] + 1 ;
		pr[ i ][ 0 ] = x ;
		for ( j = 1 ; j <= 20 ; j ++ ) {
			pr[ i ][ j ] = pr[ pr[ i ][ j - 1 ] ][ j - 1 ] ;
		}
		int h1 = LCA ( id1 , i ) ;
		int h2 = LCA ( id2 , i ) ;
		int val1 = dist[ id1 ] + dist[ i ] - 2 * dist[ h1 ] ;
		int val2 = dist[ id2 ] + dist[ i ] - 2 * dist[ h2 ] ;
		if ( val1 < val2 ) {
			if ( val2 > diam ) {
				diam = val2 ;
				id1 = i ;
			}
		}
		else {
			if ( val1 > diam ) {
				diam = val1 ;
				id2 = i ;
			}
		}
		ans[ i ] = diam ;
	}
}

void solve ( ) {
	int i ;
	for ( i = 2 ; i <= n ; i ++ ) {
		printf ( "%d\n" , ans[ i ] ) ;
	}
}

int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
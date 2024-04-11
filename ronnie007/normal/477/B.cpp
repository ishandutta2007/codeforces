#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
using namespace std ;


int n , k ;
int comp[ 1000007 ] ;

int ans[ 10007 ][ 7 ] ;
int x ;

void input ( ) ;
void solve ( ) ;

int gcd ( int p1 , int p2 ) {
	if ( p1 < p2 ) swap ( p1 , p2 ) ;
	if ( p2 == 0 ) return p1 ;
	return ( gcd ( p2 , ( p1%p2 ) ) ) ;
}

int main ( )  {
    //ios::sync_with_stdio ( false ) ;
    //cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%d%d" , &n , &k ) ;
}

void solve ( )  {
	int i ;
	int j ;
	/**
	for ( i = 2 ; i <= 1000000 ; i ++ ) {
		if ( comp[ i ] == 1 ) continue ;
		for ( j = 2 * i ; j <= 1000000 ; j += i ) {
			comp[ j ] = 1 ; 
		}
	}
	**/
	x = 1 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		ans[ i ][ 1 ] = x ;
		x ++ ;
		ans[ i ][ 2 ] = x ;
		x ++ ;
		ans[ i ][ 3 ] = x ;
		x ++ ;
		while ( 1 ) {
			if ( gcd ( x , ans[ i ][ 1 ] ) == 1 &&
                 gcd ( x , ans[ i ][ 2 ] ) == 1 &&
                 gcd ( x , ans[ i ][ 3 ] ) == 1 ) break ;
			x ++ ;
		}
		ans[ i ][ 4 ] = x ;
		x += 2 ;
	}
	printf ( "%d\n" , ans[ n ][ 4 ] * k ) ;
	for ( i = 1 ; i <= n ; i ++ ) {
		printf ( "%d %d %d %d\n" , ans[ i ][ 1 ] * k , ans[ i ][ 2 ] * k , ans[ i ][ 3 ] * k , ans[ i ][ 4 ] * k ) ;
	}
}
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std ;

#define MAXN 507

int n , k ;
int ans = 0 ;
int a[ MAXN ][ MAXN ] ;

void input ( ) {
	scanf ( "%d%d" , &n , &k ) ;
}

void solve ( ) {
	int i , j ;
	int tp = 1 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = 1 ; j < k ; j ++ ) {
			a[ i ][ j ] = tp ;
			tp ++ ;
		}
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = k ; j <= n ; j ++ ) {
			a[ i ][ j ] = tp ;
			tp ++ ;
			if ( j == k ) { ans += a[ i ][ j ] ; }
		}
	}
	printf ( "%d\n" , ans ) ;
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = 1 ; j <= n ; j ++ ) {
			printf ( "%d" , a[ i ][ j ] ) ;
			if ( j == n ) { printf ( "\n" ) ; }
			else { printf ( " " ) ; }
		}
	}
}


int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
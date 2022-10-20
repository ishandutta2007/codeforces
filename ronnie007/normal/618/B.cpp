#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
using namespace std ;

#define MAXN 57

int n ;
int a[ MAXN ][ MAXN ] ;

int ans[ MAXN ] ;

int used[ MAXN ] ;

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i , j ;
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = 1 ; j <= n ; j ++ ) {
			scanf ( "%d" , &a[ i ][ j ] ) ;
		}
	}
}

void solve ( ) {
	int i , j , t ;
	int id = 1 ;
	while ( id != n + 1 ) {
		for ( i = 1 ; i <= n ; i ++ ) {
			if ( used[ i ] == 1 ) { continue ; }
			for ( j = 1 ; j <= n ; j ++ ) {
				if ( i == j ) { continue ; }
				if ( used[ j ] == 1 ) { continue ; }
				if ( a[ i ][ j ] != id ) { break ; }
			}
			if ( j > n ) { ans[ i ] = id ; used[ i ] = 1 ; break ; }
		}
		id ++ ;
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		printf ( "%d" , ans[ i ] ) ;
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
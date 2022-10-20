#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std ;

int a[ 1007 ] ;

void input ( ) {
	int n , x ;
	scanf ( "%d" , &n ) ;
	while ( n != 0 ) {
		n -- ;
		scanf ( "%d" , &x ) ;
		a[ x ] = 1 ;
	}
}

void solve ( ) {
	int i ;
	for ( i = 1 ; i <= 1000 ; i ++ ) {
		if ( a[ i ] == 1 && a[ i + 1 ] == 1 && a[ i + 2 ] == 1 ) {
			printf ( "YES\n" ) ;
			return ;
		}
	}
	printf ( "NO\n" ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
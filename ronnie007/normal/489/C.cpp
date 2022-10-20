#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
using namespace std ;

int n , k ;
int a[ 107 ] ;
int b[ 107 ] ;

void input ( ) ;
void solve ( ) ;



int main ( )  {
    ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}

void input ( ) {
	scanf ( "%d%d" , &n , &k ) ;
}


void solve ( ) {
	int i ;
	a[ 0 ] = 1 ;
	b[ 0 ] = 1 ;
	for ( i = 1 ; i < n ; i ++ ) {
		a[ i ] = b[ i ] = 0 ;
    }
	if ( n == 1 && k == 0 ) {
		printf ( "0 0\n" ) ;
		return ;
    }
	if ( k == 0 ) {
		printf ( "-1 -1\n" ) ;
		return ;
    }

	int lft = k - 1 ;
	while ( lft != 0  ) {
		lft -- ;
		for ( i = n - 1 ; i >= 0; i -- ) {
			if ( a[ i ] < 9 ) { a[ i ] ++ ; break ; }
        }
		if ( i == -1 ) { printf ( "-1 -1\n" ) ; return ; }

		for ( i = 0 ; i < n ; i ++ ) {
			if ( b[ i ] < 9 ) { b[ i ] ++ ; break ; }
        }
		if ( i == n ) { printf ( "-1 -1\n" ) ; return ; }
    }
	for ( i = 0 ; i < n ; i ++ ) { printf ( "%d" , a[ i ] ) ; } 
	printf ( " " ) ;
	for ( i = 0 ; i < n ; i ++ ) { printf ( "%d" , b[ i ] ) ; } 
	printf ( "\n" ) ;
}
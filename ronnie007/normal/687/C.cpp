#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std ;

#define MAXN 507

int n , k ;
int a[ MAXN ] ;
bool dp[ MAXN ][ MAXN ] ;

void input ( ) {
	scanf ( "%d%d" , &n , &k ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
}

void solve ( ) {
	dp[ 0 ][ 0 ] = true ; 
	int i , j , t ;
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = k ; j >= 0 ; j -- ) {
			for ( t = k ; t >= 0 ; t -- ) {
				if ( dp[ j ][ t ] == false ) { continue ; }
				if ( j + a[ i ] <= k ) { dp[ j + a[ i ] ][ t ] = true ; }
				if ( t + a[ i ] <= k ) { dp[ j ][ t + a[ i ] ] = true ; }
			}
		}
	}
	vector < int > v ;
	for ( i = 0 ; i <= k ; i ++ ) {
		if ( dp[ i ][ k - i ] == true ) { v.push_back ( i ) ; }
	}
	int sz = v.size ( ) ;
	printf ( "%d\n" , sz ) ;
	for ( i = 0 ; i < sz ; i ++ ) {
		printf ( "%d" , v[ i ] ) ;
		if ( i == sz - 1 ) { printf ( "\n" ) ; }
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
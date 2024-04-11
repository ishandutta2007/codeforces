#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
using namespace std ;

#define MAXN 107

int n ;
int a[ MAXN ] ;

long long dp[ MAXN ] ;

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
}

void solve ( ) {
	dp[ 0 ] = 1 ;
	int i , j ;
	for ( i = 0 ; i < n ; i ++ ) {
		if ( dp[ i ] == 0 ) { continue ; }
		int br = 0 ; 
		for ( j = i + 1 ; j <= n ; j ++ ) {
			br += a[ j ] ;
			if ( br == 1 ) {
				dp[ j ] += dp[ i ] ;
			}
		}
	}
	printf ( "%I64d\n" , dp[ n ] ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
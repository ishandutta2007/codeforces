#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
#include<set>
#include<stack>
using namespace std ;

int ans = 0 ;

int sg[ 662 ] ;

void init ( ) {
	int i , j ;
	int pos = 1 ;
	for ( i = 1 ; i <= 10 ; i ++ ) {
		for ( j = 1 ; j <= ( i + 1 ) ; j ++ ) {
			sg[ pos ] = i ;			
			pos ++ ;
		}
	}
}

void input ( ) {
	int n ;
	scanf ( "%d" , &n ) ;
	int i ;
	ans = 0 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		int x ;
		scanf ( "%d" , &x ) ;
		ans = ( ans ^ sg[ x ] ) ;
	}
}

void solve ( ) {
	if ( ans != 0 ) { printf ( "NO\n" ) ; }
	else { printf ( "YES\n" ) ; }
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	init ( ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
#include<set>
using namespace std ;

#define MAXN 100007

int n , q ;
pair < int , int > a[ MAXN ] ;

int ans[ MAXN ] ; 

int val ;

void input ( ) {
	scanf ( "%d%d" , &n , &q ) ;
	int i ;
	val = n ; 
	for ( i = 1 ; i <= q ; i ++ ) {
		scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
		if ( val > ( a[ i ].second - a[ i ].first + 1 ) ) {
			val = ( a[ i ].second - a[ i ].first + 1 ) ;
		}
	}
}

void solve ( ) {
	printf ( "%d\n" , val ) ;
	int i ;
	int u = 0 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		printf ( "%d" , u ) ;
		u ++ ;
		if ( u == val ) { u = 0 ; }
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
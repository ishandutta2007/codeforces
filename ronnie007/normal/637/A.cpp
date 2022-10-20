#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std ;

#define MAXN 1007

int n ;
int a[ MAXN ] ;
int br[ MAXN * MAXN ] ;

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
}

void solve ( ) {
	int mx = 0 ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		br[ a[ i ] ] ++ ;
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( mx < br[ a[ i ] ] ) { mx = br[ a[ i ] ] ; }
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		br[ a[ i ] ] = 0 ;
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		br[ a[ i ] ] ++ ;
		if ( br[ a[ i ] ] == mx ) { printf ( "%d\n" , a[ i ] ) ; return ; }
	}
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#include<map>
#include<set>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;
int w[ MAXN ] ;
int u[ MAXN ] ;


void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
	sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
	int i ;
	w[ 1 ] = 0 ;
	for ( i = 2 ; i <= n ; i ++ ) {
		if ( a[ i ] > a[ i - 1 ] ) { w[ i ] = 1 ; }
		if ( w[ i - 1 ] == 1 ) { w[ i ] = 1 ; }
	}
	u[ n ] = 0 ;
	int ans = 0 ;	
	for ( i = n - 1 ; i >= 1 ; i -- ) {
		if ( a[ i ] < a[ i + 1 ] ) { u[ i ] = 1 ; }
		if ( u[ i + 1 ] == 1 ) { u[ i ] = 1 ; }
		if ( w[ i ] == 1 && u[ i ] == 1 ) { ans ++ ; }
	}
	printf ( "%d\n" , ans ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
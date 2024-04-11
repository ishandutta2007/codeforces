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
int u[ MAXN ] ;

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
}

void solve ( ) {
	int x = n ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		u[ a[ i ] ] = 1 ;
		while ( u[ x ] == 1 ) { printf ( "%d " , x ) ; x -- ; }
		printf ( "\n" ) ;
	}
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
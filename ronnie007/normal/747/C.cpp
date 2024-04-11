#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<map>
using namespace std ;

int n , q ;
int a[ 107 ] ;

void input ( ) {
	scanf ( "%d%d" , &n , &q ) ;
}

void solve ( ) {
	int i ;
	int x , y , z ;
	while ( q != 0 ) {
		q -- ;
		scanf ( "%d%d%d" , &x , &y , &z ) ;
		int br = 0 ;
		for ( i = 1 ; i <= n ; i ++ ) {
			if ( a[ i ] < x ) { br ++ ; }
		}
		if ( br < y ) { printf ( "-1\n" ) ; continue ; }
		int ans = 0 ;
		br = y ;
		for ( i = 1 ; i <= n ; i ++ ) {
			if ( br == 0 ) { break ; }
			if ( a[ i ] < x ) {
				br -- ;
				a[ i ] = x + z - 1 ;
				ans += i ;
			}
		}
		printf ( "%d\n" , ans ) ;
	}
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
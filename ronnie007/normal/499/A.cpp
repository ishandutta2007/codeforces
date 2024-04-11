#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#include<map>
using namespace std ;

int n , x ;


void input ( ) {
	scanf ( "%d%d" , &n , &x ) ;
}

void solve ( ) {
	int pos = 1 ;
	int ans = 0 ;
	int i ;
	int l , r ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d%d" , &l , &r ) ;
		while ( pos < l ) {
			if ( ( pos + x ) <= l ) { pos += x ; }
			else { pos ++ ; ans ++ ; }
		}
		ans += ( r - l + 1 ) ;
		pos = r + 1 ;
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
#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#include<map>
#include<set>
using namespace std ;

int n , k ;

void input ( ) {
	scanf ( "%d%d" , &n , &k ) ;
}

void solve ( ) {
	int ans = 0 ;
	int i ;
	k = 240 - k ;
	for ( i = 1 ; i <= n ; i ++ ) {
		int val = 5 * i ;
		if ( k - val >= 0 ) { ans ++ ; k -= val ; }
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
#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#include<map>
using namespace std ;

long long x , y ;

void input ( ) {
	cin >> x >> y ;
}

void solve ( ) {
	long long ans = 0 ;
	while ( x != y ) {
		if ( x < y ) { swap ( x , y ) ; }
		long long u = ( x - y ) / y ;
		if ( ( ( x - y ) % y ) != 0 ) { u ++ ; }
		x -= u * y ;
		ans += u ;
	}
	ans ++ ;
	cout << ans << "\n" ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
using namespace std ;

int n ;
string a ;

long long ans = 0 ;

void input ( ) {
	cin >> a ;
	n = a.size ( ) ;
}

void solve ( ) {
	int i ;
	for ( i = 0 ; i < n ; i ++ ) {
		if ( a[ i ] == '0' || a[ i ] == '4' || a[ i ] == '8' ) { ans ++ ; }
	}
	for ( i = 0 ; i + 1 < n ; i ++ ) {
		int u = 10 * ( a[ i ] - '0' ) + ( a[ i + 1 ] - '0' ) ;
		if ( u % 4 == 0 ) { ans += i + 1 ; }
	}
	cout << ans << "\n" ; 
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
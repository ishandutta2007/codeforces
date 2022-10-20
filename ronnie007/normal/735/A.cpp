#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#include<map>
using namespace std ;

int n , k ;
string a ;

void input ( ) {
	cin >> n >> k ;
	cin >> a ;
}

void solve ( ) {
	int i ;
	int x , y ;
	for ( i = 0 ; i < n ; i ++ ) {
		if ( a[ i ] == 'G' ) { x = i ; }
		if ( a[ i ] == 'T' ) { y = i ; }
	}
	if ( x > y ) { swap ( x , y ) ; }
	while ( x < y ) {
		if ( a[ x ] == '#' ) { cout << "NO\n" ; return ; }
		x += k ;
	}
	if ( x != y ) { cout << "NO\n" ; return ; }
	cout << "YES\n" ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
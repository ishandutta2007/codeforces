#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
using namespace std ;

int n ;
string a ;

int dx[ 4 ] = { 1 , -1 , 3 , -3 } ;

void input ( ) {
	cin >> n ;
	cin >> a ;
}

void solve ( ) {
	int i , j ;
	for ( i = 0 ; i < 4 ; i ++ ) {
		for ( j = 0 ; j < n ; j ++ ) {
			int val = ( a[ j ] - '0' ) ;
			if ( val == 0 ) { val = 11 ; }
			if ( val == 4 && dx[ i ] == -1 ) { break ; }
			if ( val == 7 && dx[ i ] == -1 ) { break ; }

			if ( val == 3 && dx[ i ] == 1 ) { break ; }
			if ( val == 6 && dx[ i ] == 1 ) { break ; }
			if ( val == 9 && dx[ i ] == 1 ) { break ; }
			val += dx[ i ] ;
			if ( val <= 0 || val > 11 ) { break ; }
			if ( val == 10 ) { break ; }
		}
		if ( j == n ) { printf ( "NO\n" ) ; return ; }
	}
	printf ( "YES\n" ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
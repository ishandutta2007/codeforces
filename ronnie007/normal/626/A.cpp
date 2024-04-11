#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std ;

int n ;
string a ;

void input ( ) {
	cin >> n ;
	cin >> a ;
}

void solve ( ) {
	int i , j , t ;
	int dx = 0 ;
	int dy = 0 ;
	int ans = 0 ;
	for ( i = 0 ; i < n ; i ++ ) {
		dx = dy = 0 ; 
		for ( j = i ; j < n ; j ++ ) {
			if ( a[ j ] == 'R' ) { dx ++ ; }
			if ( a[ j ] == 'L' ) { dx -- ; }
			if ( a[ j ] == 'U' ) { dy ++ ; }
			if ( a[ j ] == 'D' ) { dy -- ; }
			if ( dx == 0 && dy == 0 ) { ans ++ ; }
		}
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
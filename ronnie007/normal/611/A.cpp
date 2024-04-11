#include<iostream>
#include<stdio.h>
#include<string>
using namespace std ;

int n ;
string a ;

void input ( ) {
	cin >> n ;
	cin >> a ;
	cin >> a ;
}

void solve ( ) {
	int x , y ;
	x = 1 ;
	y = 1 ;
	int d = 5 ;
	int ans = 0 ;
	while ( 1 ) {
		if ( a == "week" && d == n ) { ans ++ ; }
		if ( a == "month" && x == n ) { ans ++ ; }
		if ( x == 31 && y == 12 ) { break ; }
		x ++ ;
		if ( x == 30 && y == 2 ) { x = 1 ; y ++ ; }
		if ( x == 31 ) {
			if ( y == 4 || y == 6 || y == 9 || y == 11 ) { y ++ ; x = 1 ; }
		}
		if ( x == 32 ) {
			if ( y == 1 || y == 3 || y == 5 || y == 7 || y == 8 || y == 10 ) { y ++ ; x = 1 ; }
		}
		d ++ ;
		if ( d == 8 ) { d = 1 ; }
	}
	cout << ans << "\n" ;
}

int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
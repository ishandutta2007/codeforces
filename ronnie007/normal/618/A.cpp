#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
using namespace std ;

int n ;
stack < int > s ;

void input ( ) {
	scanf ( "%d" , &n ) ;
}

void solve ( ) {
	int i ;
	int val = 1 ; 
	for ( i = 1 ; i <= n ; i ++ ) {
		s.push ( 1 ) ;
		while ( s.empty ( ) == false ) {
			int x = s.top ( ) ;
			s.pop ( ) ;
			if ( s.empty ( ) == true ) { s.push ( x ) ; break ; }
			int y = s.top ( ) ;
			s.pop ( ) ;
			if ( x == y ) { s.push ( x + 1 ) ; }
			else { s.push ( y ) ; s.push ( x ) ; break ; }
		}
	}
	vector < int > v ;
	while ( s.empty ( ) == false ) {
		v.push_back ( s.top ( ) ) ;
		s.pop ( ) ;
	}
	int sz = v.size ( ) ;
	for ( i = sz - 1 ; i >= 0 ; i -- ) {
		printf ( "%d" , v[ i ] ) ;
		if ( i == 0 ) { printf ( "\n" ) ; }
		else { printf ( " " ) ; }
	}
}


int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
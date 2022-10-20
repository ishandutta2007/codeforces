#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std ;

int n , a , b ;

void input ( ) {
	scanf ( "%d%d%d" , &n , &a , &b ) ;
}

void solve ( ) {
	while ( b != 0 ) {
		if ( b < 0 ) { a -- ; }
		else { a ++ ; }
		if ( a == 0 ) { a = n ; }
		if ( a == ( n + 1 ) ) { a = 1 ; }
		if ( b < 0 ) { b ++ ; }
		else { b -- ; }
	}
	printf ( "%d\n" , a ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#include<map>
#include<set>
using namespace std ;

int n ;

bool f ( int x ) {
	int i ;
	for ( i = 2 ; i * i <= x ; i ++ ) {
		if ( ( x % i ) == 0 ) { return false ; }
	}
	return true ;
}

void input ( ) {
	scanf ( "%d" , &n ) ;
}

void solve ( ) {
	int i ;
	for ( i = 1 ; i <= 1000 ; i ++ ) {
		int x = i * n + 1 ;
		if ( f ( x ) == false ) {
			printf ( "%d\n" , i ) ;
			return ;
		}
	}
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
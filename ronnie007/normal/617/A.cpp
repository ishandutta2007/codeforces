#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std ;

int n ;

void input ( ) {
	scanf ( "%d" , &n ) ;
}

void solve ( ) {
	int ans = 0 ;
	while ( n > 0 ) {
		n -= 5 ;
		ans ++ ;
	}
	printf ( "%d\n" , ans ) ;
}


int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
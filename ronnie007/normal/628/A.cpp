#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std ;

int n , b , p ;

void input ( ) {
	scanf ( "%d%d%d" , &n , &b , &p ) ;
}

void solve ( ) {
	int ans = 0 ;
	int i ;
	int g = n * p ;
	while ( n > 1 ) {
		i = 1 ;
		while ( i <= n ) { i *= 2 ; } 
		i /= 2 ;
		n = i / 2 + ( n - i ) ;
		ans += i * b + ( i / 2 ) ;
	}
	printf ( "%d %d\n" , ans , g ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
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

void input ( ) {
	scanf ( "%d" , &n ) ;
}

void solve ( ) {
	int a , b ;
	int i ;
	int x , y ;
	for ( i = 1 ; i * i <= n ; i ++ ) {
		if ( ( n % i ) == 0 ) {
			x = i ;
			y = ( n / i ) ;
		}
	}
	printf ( "%d %d\n" , x , y ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
#include<iostream>
#include<stdio.h>
using namespace std ;

long long x , y ;

void input ( ) {
	cin >> x >> y ;
}

void solve ( ) {
	long long u = 1 ;
	long long t ;
	long long ans = 0 ;
	while ( 1 ) {
		for ( t = 1 ; t < u / 2 ; t *= 2 ) {
			long long p = ( u - 1 ) - t ;
		
			if ( p >= x && p <= y ) { ans ++ ; }
		}
		if ( u > y ) { break ; }
		u *= 2 ;
	}
	cout << ans << "\n" ;
}

int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
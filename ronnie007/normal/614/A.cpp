#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std ;

long long l , r , k ; 

long long x ;

void input ( ) {
	cin >> l >> r >> k ;
}

void solve ( ) {
	vector < long long > v ;
	x = 1 ;
	while ( 1 ) {
		if ( x >= l ) { v.push_back ( x ) ; }
		if ( x > r / k ) { break ; }
		x *= k ;
	}
	int sz = v.size ( ) ;
	if ( sz == 0 ) { cout << "-1\n" ; return ; }
	int i ;
	for ( i = 0 ; i < sz ; i ++ ) {
		cout << v[ i ] ;
		if ( i == sz - 1 ) { cout << "\n" ; }
		else { cout << " " ; }
	}
}


int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
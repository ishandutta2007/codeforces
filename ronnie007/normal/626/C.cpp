#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std ;

int n , m ;

bool f ( int x ) {
	int u1 = ( x / 2 ) ;
	int u2 = ( x / 3 ) ;
	int u3 = ( x / 6 ) ;
	int lft1 = ( n - ( u1 - u3 ) ) ;
	if ( lft1 < 0 ) { lft1 = 0 ; }
	int lft2 = ( m - ( u2 - u3 ) ) ;
	if ( lft2 < 0 ) { lft2 = 0 ; }
	if ( lft1 + lft2 <= u3 ) { return true ; }
	return false ; 
}

void input ( ) {
	cin >> n >> m ;
}

void solve ( ) {
	int i ;
	int l ;
	int r = ( 1000 * ( n + m ) ) ;
	int mid ;
	while ( r - l > 3 ) {
		mid = ( l + r ) / 2 ;
		if ( f ( mid ) == true ) { r = mid ; }
		else { l = mid ; }
	}
	while ( f ( l ) == false ) { l ++ ; }
	cout << l << "\n" ;
}


int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
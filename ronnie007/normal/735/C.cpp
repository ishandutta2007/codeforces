#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<map>
using namespace std ;

long long n ;

long long fib[ 107 ] ;

bool f ( long long x ) {
	long long sm = n - 1 ;
	int i ;
	for ( i = 1 ; i <= x ; i ++ ) {
		sm -= fib[ i ] ;
		if ( sm < 0 ) { return false ; }
	}
	return true ;
}

void input ( ) {
	cin >> n ;
}

void solve ( ) {
	int i ;
	fib[ 1 ] = fib[ 2 ] = 1 ;
	for ( i = 3 ; i <= 88 ; i ++ ) {
		fib[ i ] = ( fib[ i - 1 ] + fib[ i - 2 ] ) ;
	}
	long long l , r , mid ;
	l = 1 ;
	r = 3 ;
	for ( i = 1 ; i <= 5 ; i ++ ) { r *= 10 ; }
	while ( r - l > 3 ) {
		mid = ( l + r ) / 2 ;
		if ( f ( mid ) == true ) { l = mid ; }
		else { r = mid ; }
	}
	while ( f ( r ) == false ) { r -- ; }
	cout << r << "\n" ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
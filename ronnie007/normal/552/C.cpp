#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
using namespace std ;

int p , n ;

void input ( ) ;
void solve ( ) ;

int main ( )  {
    ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}

void input ( ) {
	scanf ( "%d%d" , &p , &n ) ;
}

void solve ( ) {
	vector < int > v ;
	v.clear ( ) ;
	while ( n != 0 ) {
		v.push_back ( n % p ) ;
		n /= p ;
    }

	int i ;
	int sz = v.size ( ) ;
	int carry = 0 ;
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( carry == 1 ) { v[ i ] += carry ; carry = 0 ; }
		carry += ( v[ i ] / p ) ;
		v[ i ] %= p ;
		if ( v[ i ] <= 1 ) { continue ; }
		if ( v[ i ] + 1 == p ) {
			carry ++ ;
        }
		else { printf ( "NO\n" ) ; return ; }
    }
	printf ( "YES\n" ) ;
}
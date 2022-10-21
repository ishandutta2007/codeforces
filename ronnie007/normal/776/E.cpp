#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
#include<set>
#include<stack>
using namespace std ;

#define MOD 1000000007

long long n , k ;

map < long long , long long > ZX ;

long long gcd ( long long x , long long y ) {
	if ( x < y ) { swap ( x , y ) ; }
	if ( y == 0 ) { return x ; }
	return ( gcd ( y , ( x % y ) ) ) ;
}

long long f ( long long x ) {
	int i ;
	long long ret = 0 ;
	if ( x == 1 ) { return 1 ; }
	for ( i = 1 ; i < x ; i ++ ) {
		if ( gcd ( i , ( x - i ) ) == 1 ) { ret ++ ; }
	}
	return ret ;
}
long long g ( long long x ) {
	long long ret = 0 ;
	long long i ;
	for ( i = 1 ; i <= x ; i ++ ) {
		if ( ( x % i ) == 0 ) { ret += f ( ( x / i ) ) ; }
	}
	return ret ;
}

long long gg ( long long x ) {
	long long i ;
	long long ret = ( x - 1 ) ;
	if ( ZX.find ( x ) != ZX.end ( ) ) { return ZX[ x ] ; }
	if ( x == 1 ) { return 1 ; }
	for ( i = 2 ; i * i <= x ; i ++ ) {
		if ( ( x % i ) != 0 ) { continue ; }
		ret -= gg ( ( x / i ) ) ;
		if ( i * i != x ) { ret -= gg ( i ) ; }
	}
	ZX[ x ] = ret ;
	return ret ;
}

void input ( ) {
	cin >> n >> k ;
}

void solve ( ) {
	int i ;
	/**
	for ( i = 1 ; i <= 50 ; i ++ ) {
		printf ( "g( %d ) = %d\n" , i , g ( i ) ) ;
	}
	for ( i = 1 ; i <= 50 ; i ++ ) {
		printf ( "f( %d ) = %d\n" , i , f ( i ) ) ;
		if ( f ( i ) != gg ( i ) ) { printf ( "KUREC --- %d\n" , gg ( i ) ) ; }
	}
	**/
	long long u = n ;
	u = gg ( u ) ;
	k -- ;
	while ( k > 0 ) {
		k -= 2 ;
		if ( k < 0 ) { break ; }
		u = gg ( u ) ;
		if ( u == 1 ) { break ; }
	}
	u %= MOD ;
	cout << u << "\n" ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
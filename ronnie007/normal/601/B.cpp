#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
#include<set>
#include<stack>
using namespace std ;

#define MAXN 100007	

int n , q ;
int a[ MAXN ] ;
int b[ MAXN ] ;

int l[ MAXN ] ;
int r[ MAXN ] ;

long long f ( int st , int en ) {
	int i ;
	long long ret = 0 ;
	for ( i = st ; i < en ; i ++ ) {
		long long h1 = i - max ( l[ i ] + 1 , st ) + 1 ;
		long long h2 = min ( r[ i ] - 1 , en - 1 ) - i + 1 ;
		ret += h1 * h2 * b[ i ] ;
	}
	return ret ;
}

void input ( ) ;
void solve ( ) ;

int main ( )  {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%d%d" , &n , &q ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
}

void solve ( ) {
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		b[ i ] = abs ( a[ i + 1 ] - a[ i ] ) ;
	}
	stack < int > s ;
	for ( i = 1 ; i < n ; i ++ ) {
		while ( s.empty ( ) == false && b[ s.top ( ) ] <= b[ i ] ) {
			s.pop ( ) ;
		}
		if ( s.empty ( ) == false ) { l[ i ] = s.top ( ) ; }
		else { l[ i ] = 0 ; }
		s.push ( i ) ;
	}
	while ( s.empty ( ) == false ) { s.pop ( ) ; }
	
	for ( i = n - 1 ; i >= 1 ; i -- ) {
		while ( s.empty ( ) == false && b[ s.top ( ) ] < b[ i ] ) {
			s.pop ( ) ;
		}
		if ( s.empty ( ) == false ) { r[ i ] = s.top ( ) ; }
		else { r[ i ] = n ; }
		s.push ( i ) ;
	}
	while ( s.empty ( ) == false ) { s.pop ( ) ; }
	int st , en ;
	while ( q != 0 ) {
		q -- ;
		scanf ( "%d%d" , &st , &en ) ;
		printf ( "%I64d\n" , f ( st , en ) ) ;
	}
}
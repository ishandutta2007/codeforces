#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

#define MAXN 500007

int n ;
int a[ MAXN ] ;
int ans[ MAXN ] ;
vector < int > v ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ; 
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
}

void solve ( ) {
	int i ;
	int p , q ;
	p = q = 0 ;
	a[ 0 ] = a[ 1 ] ;
	a[ n + 1 ] = a[ n ] ;
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( a[ i ] == a[ i - 1 ] || a[ i ] == a[ i + 1 ] ) { v.push_back ( i ) ; }
	}
	int sz = v.size ( ) ;
	int ret = 0 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		while ( p < sz - 1 && v[ p ] <= i ) { p ++ ; }
		if ( v[ p ] > i && p != 0 ) { p -- ; }
		while ( q < sz - 1 && v[ q ] < i ) { q ++ ; }
		int mn = min ( abs ( i - v[ p ] ) , abs ( i - v[ q ] ) ) ;
		ret = max ( ret , mn ) ;
		if ( mn == abs ( i - v[ p ] ) ) {
			if ( a[ v[ p ] ] == 1 ) { ans[ i ] = 1 ; }
			else { ans[ i ] = 0 ; }
		}
		else {
			if ( a[ v[ q ] ] == 1 ) { ans[ i ] = 1 ; }
			else { ans[ i ] = 0 ; }
		}
	}
	printf ( "%d\n" , ret ) ;
	for ( i = 1 ; i <= n ; i ++ ) {
		printf ( "%d" , ans[ i ] ) ;
		if ( i == n ) { printf ( "\n" ) ; }
		else { printf ( " " ) ; }
	}
}
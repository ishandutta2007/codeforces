#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std ;

#define MAXN 2007

int n ;
int a[ MAXN ] ;

double dp[ 3 * MAXN ] ;

int br[ 3 * MAXN ] ;

int id[ 3 * MAXN ] ;

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
	sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
	int i , j ;
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = 1 ; j < i ; j ++ ) {
			br[ ( a[ i ] - a[ j ] ) ] ++ ;
		}
	}
	int g = ( n * ( n - 1 ) ) / 2 ; 
	for ( i = 1 ; i <= 5000 ; i ++ ) {
		for ( j = 1 ; j < 5000 ; j ++ ) {
			if ( j >= i ) { break ; }
			double cur = br[ j ] * br[ ( i - j ) ] ;
			cur /= g ;
			cur /= g ;
			dp[ i ] += cur ;
		}
	}
	j = 1 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		while ( j < a[ i ] ) {
			id[ j ] = i - 1 ;
			j ++ ;
		}
	}
	while ( j < 5000 ) {
		id[ j ] = i - 1 ;
		j ++ ;
	}
	double ans = 0.00000 ;
	for ( i = 1 ; i <= 5000 ; i ++ ) {
		for ( j = n ; j >= 2 ; j -- ) {
			int h = ( a[ j ] - i - 1 ) ;
			if ( h <= 0 ) { break ; }
			double cur = id[ h ] ;
			cur /= g ;
			ans += ( dp[ i ] * cur ) ;
		}
	}
	printf ( "%.12lf\n" , ans ) ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
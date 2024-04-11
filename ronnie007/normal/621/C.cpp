#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std ;

#define MAXN 100007

int n , p ;
pair < int , int > a[ MAXN ] ;

void input ( ) {
	scanf ( "%d%d" , &n , &p ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
	}
	a[ n + 1 ] = a[ 1 ] ;
}

void solve ( ) {
	int i ;
	double val1 , val2 ;
	double ans = 0.000000 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		val1 = ( ( a[ i ].second / p ) - ( ( a[ i ].first - 1 ) / p ) ) ;
		val1 = val1 / ( a[ i ].second - a[ i ].first + 1 ) ;
		val2 = ( ( a[ i + 1 ].second / p ) - ( ( a[ i + 1 ].first - 1 ) / p ) ) ;
		val2 = val2 / ( a[ i + 1 ].second - a[ i + 1 ].first + 1 ) ;
		double cur = ( 1 - ( 1 - val1 ) * ( 1 - val2 ) ) * 2000.00 ;
		ans += cur ;
	}
	printf ( "%.12lf\n" , ans ) ;
}


int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
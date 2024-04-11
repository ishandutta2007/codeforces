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

#define inf 2000000007

#define eps 0.00000000001

#define MAXN 200007

int n ;
int a[ MAXN ] ;
double b[ MAXN ] ;

double f ( double x ) {
	double cur = 0.00 ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		b[ i ] = ( double ( a[ i ] ) ) - x ;
	}
	double retmin = 0.00 ;
	double retmax = 0.00 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		cur += b[ i ] ;
		if ( cur < 0.00 ) { cur = 0.00 ; }
		retmax = max ( retmax , cur ) ;
	}
	cur = 0.00000000000 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		cur += b[ i ] ;
		if ( cur > 0.00 ) { cur = 0.00 ; }
		retmin = min ( retmin , cur ) ;
	}
	retmin = -retmin ;
	return max ( retmin , retmax ) ;
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

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	int sm = 0 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
		sm += a[ i ] ; 
	}
}

void solve ( ) {
	double l , r , mid1 , mid2 ;
	l = 0.0000000000 ;
	r = 1.0000000000 ;
	int i ;
	for ( i = 1 ; i <= 4 ; i ++ ) {
		r *= 10.00000000000 ;
	}
	r *= 2 ;
	double best = f ( 0.000 ) ;
	l = -r ;
	while ( r - l > eps ) {
		mid1 = ( 2 * l + r ) / 3 ;
		mid2 = ( l + 2 * r ) / 3 ;
		if ( f ( mid1 ) < f ( mid2 ) ) { r = mid2 ; }
		else { l = mid1 ; }
	}
	l = ( l + r ) / 2 ;
	printf ( "%.12lf\n" , f ( l )  ) ;
}
#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

#define eps 0.001
#define inf 1000000007
int a , b ;

double f ( int x , long long sr ) {
	if ( b > a ) { return -1 ; }
	int l = 1 ;
	int r = 1 ;
	int mid ;
	int i ;
	for ( i = 1 ; i <= 9 ; i ++ ) { r *= 10 ; }
	while ( r - l > 3 ) {
		mid = ( l + r ) / 2 ;
		double val = 2 * mid ;
		if ( val * sr > double ( x ) ) { 
			r = mid ; 
		}
		else { l = mid ; }
	}
	
	while ( r >= l ) {
		double val = 2 * r ;
		if ( double ( x ) - val * sr < eps && double ( x ) - val * sr > -eps ) {
			return ( x / val ) ;
		}
		if ( val * sr < double ( x ) ) {
			return ( x / val ) ;
		}
		r -- ;
	}
	return inf ;
}

void input ( ) ;
void solve ( ) ;


int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ; 
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%d%d" , &a , &b ) ;
}

void solve ( ) {
	double ans = min ( f ( a + b , b ) , f ( a - b , b ) ) ;
	if ( ans == inf ) { ans = -1 ; }
	printf ( "%.12lf\n" , ans ) ;
}
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

double s , x1 , x2 ;
double t1 , t2 ;
double p , d ;

void input ( ) {
	cin >> s >> x1 >> x2 ;
	cin >> t1 >> t2 ;
	cin >> p >> d ;
	t1 = ( 1 / t1 ) ;
	t2 = ( 1 / t2 ) ;
}

void solve ( ) {
	if ( t2 > t1 ) { cout << ( ( max ( x2 - x1 , ( x1 - x2 ) ) ) / t2 ) << "\n" ; }
	else {
		double u ;
		int dir ;
		u = 0.000000 ;
		if ( x1 < x2 ) { dir = 1 ; }
		else { dir = -1 ; }
		if ( dir == d ) {
			if ( d == 1 && p > x1 ) {
				u += ( ( s - p ) / t1 ) ;
				p = s ;
				d = 0 - d ;
			}
			else if ( d == -1 && p < x1 ) {
				u += ( p / t1 ) ;
				p = 0 ;
				d = 0 - d ;
			}
		}
		if ( dir != d ) {
			if ( d == 1 ) { u += ( ( s - p ) / t1 ) ; }
			else { u += ( p / t1 ) ; }
			if ( d == 1 ) { p = s ; }
			else { p = 0 ; }
			d = 0 - d ;
		}
		double k = x1 + dir * t2 * u ;
		u += ( max ( p - k , k - p ) / ( t1 - t2 ) ) ;
		double pt = x1 + dir * t2 * u ;
		double cur = u + ( ( max ( pt - x2 , ( x2 - pt ) ) ) / t1 ) ;
		cur = min ( cur , ( ( max ( x2 - x1 , ( x1 - x2 ) ) ) / t2 ) ) ;
		cout << cur << "\n" ;
	}
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
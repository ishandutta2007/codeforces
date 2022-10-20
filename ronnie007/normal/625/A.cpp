#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std ;

long long n , a , b , c ;


void input ( ) {
	cin >> n >> a >> b >> c ;
}

void solve ( ) {
	long long ans = n / a ;
	long long l = 0 ;
	long long r = n / ( b - c )  ;
	long long mid ;
	while ( r - l > 3 ) {
		mid = ( l + r ) / 2 ;
		if ( n - ( mid * ( b - c ) ) >= b ) { l = mid ; }
		else { r = mid ; }
	}
	while ( n - ( r * ( b - c ) ) < b && r >= 0 ) { r -- ; }
	if ( r < 0 ) { r = 0 ; }
	long long cur = r ;
	n -= r * ( b - c ) ;
	while ( n >= b ) { cur ++ ; n -= b ; n += c ; }
	cur += ( n / a ) ;
	if ( ans < cur ) { ans = cur ; }
	cout << ans << "\n" ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
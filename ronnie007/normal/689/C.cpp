#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
using namespace std ;

long long m ;

long long f ( long long x ) {
	long long k ;
	long long ans = 0 ;
	for ( k = 2 ; k <= 1000000 ; k ++ ) {
		ans += ( x / ( k * k * k ) ) ;
	}
	return ans ;
}

void input ( ) {
	cin >> m ;
}

void solve ( ) {
	long long l , r , mid ;
	l = 1 ;
	r = 1 ;
	int i ;
	for ( i = 1 ; i <= 17 ; i ++ ) { r *= 10 ; }
	while ( r - l > 3 ) {
		mid = ( l + r ) / 2 ;
		long long val = f ( mid ) ;
		if ( val < m ) { l = mid ; }
		else { r = mid ; }
	}
	while ( r != 0 && f ( r ) >= m ) { r -- ; }
	r ++ ;
	if ( r > 0 && f ( r ) == m ) { cout << r << "\n" ; }
	else { cout << "-1\n" ; }
}


int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
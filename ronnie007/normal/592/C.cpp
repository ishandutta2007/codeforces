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

long long t , a , b ;

long long gcd ( long long x , long long y ) {
	if ( x < y ) { swap ( x , y ) ; }
	if ( y == 0 ) { return x ; }
	return ( gcd ( y , ( x % y ) ) ) ;
}

long long lcm ( long long x , long long y ) {
	long long u = gcd ( x , y ) ;
	// u * lcm == x * y 
	// u * t < x * y ?
	double h1 = u ;
	h1 /= y ;
	double h2 = x ;
	h2 /= t ;
	if ( h1 < h2 ) { return ( t + 1 ) ; }
	else {
		long long ret = y / u ;
		ret *= x ;
		return ret ;
	}
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
	cin >> t >> a >> b ;
}

void solve ( ) {
	if ( a < b ) { swap ( a , b ) ; }
	long long h = lcm ( a , b ) ;
	if ( t < b ) { cout << "1/1\n" ; return ; } 
	//cout << h << "\n" ;
	//if ( h > t ) { cout << "0/1\n" ;  return ; }
	long long val1 = ( ( max ( t - b , 0LL ) ) / h ) ;
	long long ans = ( ( val1 + 1 ) * b - 1 ) ;
	//cout << ans << "\n" ;
	val1 *= h ;
	if ( val1 + h <= t ) {
		long long lft = ( t - ( val1 + h ) + 1 ) ;
		ans += lft ;
	}
	long long u = gcd ( ans , t ) ;
	ans /= u ;
	t /= u ;
	cout << ans << "/" << t << "\n" ;
}
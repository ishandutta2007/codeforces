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

long long n ;
long long a , b ;
long long c , d ;

long long p = 2000000 ;

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
	cin >> n >> b >> d >> a >> c ;
}

void solve ( ) {
	int i ;
	long long mx = -1 ;
	long long cur = 0 ;
	for ( i = 0 ; i <= p ; i ++ ) {
		if ( i * a > n ) { break ; }
		cur = 0 ;
		cur += i * b ;
		long long lft = n - i * a ;
		lft /= c ;
		cur += lft * d ;
		if ( mx < cur ) { mx = cur ; }
    }
	swap ( a , c ) ;
	swap ( b , d ) ;
	for ( i = 0 ; i <= p ; i ++ ) {
		if ( i * a > n ) { break ; }
		cur = 0 ;
		cur += i * b ;
		long long lft = n - i * a ;
		lft /= c ;
		cur += lft * d ;
		if ( mx < cur ) { mx = cur ; }
    }
	cout << mx << "\n" ;
}
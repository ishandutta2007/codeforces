#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
using namespace std ;


long long a , b , c ;
vector < long long > v ;



void input ( ) ;
void solve ( ) ;

long long s ( long long x ) {
	long long ret = 0 ;
	while ( x != 0 ) { ret += x % 10 ; x /= 10 ; }
	return ret ;
}

int main ( )  {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%I64d%I64d%I64d" , &a , &b , &c ) ;
}

void solve ( )  {
	long long lim = 1 ;
	int i , j ;
	for ( i = 0 ; i < 9 ; i ++ ) {
		lim = lim * 10 ;
	}
	long long cur = 1 ;
	for ( i = 0 ; i <= 100 ; i ++ ) {
		cur = 1 ;
		for ( j = 0 ; j < a ; j ++ ) {
			cur = cur * i ;
		}
		cur *= b ;
		cur += c ;
        //	printf ( "%d %lld %lld\n" , i , cur , lim ) ;
        //		cout << cur << "\n" ;
		if ( cur >= lim ) continue ;
		if ( cur <= 0 ) continue ;
		long long h = s ( cur ) ;

		if ( i == h ) {
			v.push_back ( cur ) ;
		}
	}
	int sz = v.size ( ) ;
	printf ( "%d\n" , v.size ( ) ) ;
	for ( i = 0 ; i < sz ; i ++ ) {
		printf ( "%I64d" , v[ i ] ) ;
		if ( i != sz - 1 ) printf ( " " ) ;
		else printf ( "\n" ) ;
	}
}
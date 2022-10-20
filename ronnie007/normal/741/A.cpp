#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#include<map>
using namespace std ;

#define MAXN 107

int n ;
int a[ MAXN ] ;
int used[ MAXN ] ;
vector < long long > v ;

long long nod ( long long x , long long y ) {
	if ( x < y ) { swap ( x , y ) ; }
	if ( y == 0 ) { return x ; }
	return nod ( y , ( x % y ) ) ;
}

long long nok ( long long x , long long y ) {
	long long u = nod ( x , y ) ;
	long long ret = ( x / u ) * y ;
	return ret ;
}

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
}

void solve ( ) {
	int i ;
	int x ;
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( used[ i ] == 1 ) { continue ; }
		x = i ;
		int len = 0 ;
		while ( 1 ) {
			used[ x ] = 1 ;		
			x = a[ x ] ;
			len ++ ;
			if ( used[ x ] == 1 ) { break ; }			
		}
		if ( x != i ) { printf ( "-1\n" ) ; return ; }
		if ( ( len % 2 ) == 0 ) { len /= 2 ; }
		v.push_back ( len ) ;
	}
	int sz = v.size ( ) ;
	long long ret = v[ 0 ] ;
	for ( i = 1 ; i < sz ; i ++ ) {
		ret = nok ( ret , v[ i ] ) ;
	}
	printf ( "%I64d\n" , ret ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
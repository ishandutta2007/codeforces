#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std ;

typedef vector < vector < long long > > TYPE ;

#define MOD 1000000007
#define MAXN 50007

int n , b , k , x ;
int a[ MAXN ] ;
int br[ MAXN ] ;

TYPE v ;

TYPE mul ( TYPE u , TYPE w ) {
	TYPE ret ;
	int i , j , t ;
	long long s = 0 ;
	ret.resize ( x ) ;
	for ( i = 0 ; i < x ; i ++ ) {
		ret[ i ].resize ( x ) ;
	}
	for ( i = 0 ; i < x ; i ++ ) {
		for ( j = 0 ; j < x ; j ++ ) {
			s = 0 ;
			for ( t = 0 ; t < x ; t ++ ) {
				s = ( ( s + ( ( u[ i ][ t ] * w[ t ][ j ] ) % MOD ) ) % MOD ) ;
			}
			ret[ i ][ j ] = s ;
		}
	}
	return ret ;
}


TYPE FPOW ( long long exp ) {
	TYPE r ;
	int i , j ;
	r.resize ( x ) ;
	for ( i = 0 ; i < x ; i ++ ) {
		for ( j = 0 ; j < x ; j ++ ) {
			if ( i == j ) { r[ i ].push_back ( 1 ) ; }
			else { r[ i ].push_back ( 0 ) ; }
		}
	}
	while ( exp != 0 ) {
		if ( exp % 2 == 0 ) {
			v = mul ( v , v ) ;
			exp /= 2 ;
		}
		else {
			r = mul ( r , v ) ;
			exp -- ;
		}
	}
	return r ;
}


void input ( ) {
	scanf ( "%d%d%d%d" , &n , &b , &k , &x ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
}

void solve ( ) {
	int i , j ;
	v.resize ( x ) ;
	for ( i = 0 ; i < x ; i ++ ) {
		v[ i ].resize ( x ) ;
	}
	
	for ( i = 1 ; i <= n ; i ++ ) {
		br[ ( a[ i ] % x ) ] ++ ;
	}
	for ( i = 0 ; i < x ; i ++ ) {
		for ( j = 0 ; j < x ; j ++ ) {
			int id = ( 10 * i + j ) % x ;
			v[ id ][ i ] += br[ j ] ;
		}
	}
	v = FPOW ( b ) ;
	long long ans = 0 ;
	printf ( "%I64d\n" , v[ k ][ 0 ] ) ;
}

int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
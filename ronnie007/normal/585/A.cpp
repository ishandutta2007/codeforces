#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

#define MAXN 4007

int n ;
struct tuhla {
	long long x ;
	long long y ;
	long long cur ;
};

struct tuhla a[ MAXN ] ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ; 
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d%d%d" , &a[ i ].x , &a[ i ].y , &a[ i ].cur ) ;
	}
}

void solve ( ) {
	vector < int > ans ;
	int i , j ;
	long long p , q ;
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = 1 ; j <= n ; j ++ ) {
			if ( a[ j ].cur >= 0 ) { break ; }
		}
		if ( j > n ) { break ; }
		int id = j ;
		ans.push_back ( id ) ;
		a[ id ].cur = -1 ;
		p = a[ j ].x ;
		q = 0 ;
		for ( j = id + 1 ; j <= n ; j ++ ) {
			if ( a[ j ].cur < 0 ) { continue ; }
			a[ j ].cur -= ( p + q ) ;
			p -- ;
			if ( p < 0 ) { p = 0 ; }
			if ( a[ j ].cur < 0 ) { q += a[ j ].y ; }
		}
	}
	int sz = ans.size ( ) ;
	printf ( "%d\n" , sz ) ;
	for ( i = 0 ; i < sz ; i ++ ) {
		printf ( "%d" , ans[ i ] ) ;
		if ( i == sz - 1 ) { printf ( "\n" ) ; }
		else { printf ( " " ) ; }
	}
}
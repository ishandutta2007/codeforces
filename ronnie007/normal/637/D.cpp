#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std ;

#define MAXN 200007

int n , m , s , d ;
int a[ MAXN ] ; 

bool dp[ MAXN ] ;

int lst[ MAXN ] ;


struct tuhla {
	int id ;
	int len ;
};

struct tuhla pr[ MAXN ] ;

void input ( ) {
	scanf ( "%d%d%d%d" , &n , &m , &s , &d ) ;
	int i ;
	a[ 1 ] = -1 ; 
	for ( i = 2 ; i <= n + 1 ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
	sort ( a + 1 , a + n + 2 ) ;
}

void solve ( ) {
	if ( d == 1 ) { printf ( "IMPOSSIBLE\n" ) ; return ; }
	int i ;
	dp[ n + 1 ] = true ;
	lst[ n + 1 ] = n + 1 ; 
	for ( i = n ; i >= 1 ; i -- ) {
		int dist = ( a[ i + 1 ] - a[ i ] - 2 ) ;
		if ( dist < s ) { dp[ i ] = false ; lst[ i ] = lst[ i + 1 ] ; continue ; }
		int pt = a[ i + 1 ] - 1 + d ;
		if ( a[ lst[ i + 1 ] ] >= pt ) { dp[ i ] = false ; lst[ i ] = lst[ i + 1 ] ; continue ; }
		dp[ i ] = true ;
		lst[ i ] = i ;
		pr[ lst[ i + 1 ] ].id = i ;
		pr[ lst[ i + 1 ] ].len = a[ lst[ i + 1 ] ] + 1 - ( a[ i + 1 ] - 1 ) ;
	}
	if ( dp[ 1 ] == false ) { printf ( "IMPOSSIBLE\n" ) ; return ; }
	vector < struct tuhla > v ;
	struct tuhla u ;
	if ( a[ n + 1 ] != ( m - 1 ) ) {
		u.id = 0 ;
		u.len = ( m - ( a[ n + 1 ] + 1 ) ) ;
		v.push_back ( u ) ;
	}
	int x = n + 1 ;
	while ( 1 ) {
		u.id = 1 ;
		u.len = pr[ x ].len ;
		v.push_back ( u ) ;
		x = pr[ x ].id ;
		if ( ( a[ x + 1 ] - 1 - ( a[ x ] + 1 ) ) != 0 ) { 
			u.id = 0 ;
			u.len = ( a[ x + 1 ] - 1 - ( a[ x ] + 1 ) ) ;
			v.push_back ( u ) ; 
		}
		if ( x == 1 ) { break ; }
	}
	int sz = v.size ( ) ;
	for ( i = sz - 1 ; i >= 0 ; i -- ) {
		if ( v[ i ].id == 0 ) { printf ( "RUN " ) ; }
		else { printf ( "JUMP " ) ; }
		printf ( "%d\n" , v[ i ].len ) ;
	}
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
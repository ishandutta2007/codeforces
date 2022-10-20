#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
#include<set>
#include<stack>
using namespace std ;

#define MAXN 100007

struct tuhla {
	int first , second ;
	int id ;
};

int n ;
tuhla a[ MAXN ] ;

int ans[ MAXN ] ;

bool cmp ( tuhla p1 , tuhla p2 ) {
	return ( p1.first < p2.first ) ;
}

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
		a[ i ].id = i ;
	}
	sort ( a + 1 , a + n + 1 , cmp ) ;
}

void solve ( ) {
	int i ;
	stack < int > s ;
	for ( i = n ; i >= 1 ; i -- ) {
		ans[ a[ i ].id ] = 1 ;
		while ( s.empty ( ) == false && a[ s.top ( ) ].first < a[ i ].first + a[ i ].second ) {
			ans[ a[ i ].id ] += ans[ a[ s.top ( ) ].id ] ;
			s.pop ( ) ;
		}
		s.push ( i ) ;
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		printf ( "%d" , ans[ i ] ) ;
		if ( i == n ) { printf ( "\n" ) ; }
		else { printf ( " " ) ; }
	}
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
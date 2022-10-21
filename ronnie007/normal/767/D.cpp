#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std ;

#define MAXN 10000007

int n , m , k ; 

int a[ MAXN ] ;
vector < int > b[ MAXN ] ;

void input ( ) {
	scanf ( "%d%d%d" , &n , &m , &k ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		int x ;
		scanf ( "%d" , &x ) ;
		a[ x ] ++ ;
	}
	for ( i = 1 ; i <= m ; i ++ ) {
		int x ;
		scanf ( "%d" , &x ) ;
		b[ x ].push_back ( i ) ;
	}
}

void solve ( ) {
	int i , j ;
	int cur = 0 ;
	stack < int > s ;
	int w = 0 ;
	for ( i = 0 ; i <= 10000000 ; i ++ ) {
		cur += a[ i ] ;
		long long mx = 1LL * k * ( i + 1 ) ;
		while ( mx < ( cur + w ) ) {
			if ( w == 0 ) { printf ( "-1\n" ) ; return ; }
			w -- ;
			s.pop ( ) ;
		}
		int sz = b[ i ].size ( ) ;
		for ( j = 0 ; j < sz ; j ++ ) {
			if ( mx <= ( cur + w ) ) { break ; }
			w ++ ;
			s.push ( b[ i ][ j ] ) ;
		}
	}
	printf ( "%d\n" , w ) ;
	while ( s.empty ( ) == false ) {
		printf ( "%d " , s.top ( ) ) ;
		s.pop ( ) ;
	}
	printf ( "\n" ) ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
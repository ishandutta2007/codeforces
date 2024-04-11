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

#define MAXN 2007

int n , k ;
vector < int > v[ MAXN ] ;

void input ( ) {
	scanf ( "%d%d" , &n , &k ) ;
	int i , j ;
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = i + 1 ; j <= n ; j ++ ) {
			int x ;
			scanf ( "%d" , &x ) ;
			if ( x != -1 ) {
				v[ i ].push_back ( x ) ;
				v[ j ].push_back ( x ) ;
			}
		}
	}
}

void solve ( ) {
	int i , j , t ;
	if ( k != 2 ) {
		long long sm = 0 ;
		for ( i = 1 ; i <= n ; i ++ ) {
			int sz = v[ i ].size ( ) ;
			for ( j = 0 ; j < sz ; j ++ ) {
				sm += v[ i ][ j ] ;
			}
		}
		cout << ( sm / n ) << "\n" ;
		return ;
	}
	long long sm = 0 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		int sz = v[ i ].size ( ) ;
		for ( j = 0 ; j < sz ; j ++ ) {
			for ( t = j + 1 ; t < sz ; t ++ ) {
				sm += v[ i ][ j ] + v[ i ][ t ] ;
			}
		}
	}
	long long aux = ( n * ( n - 1 ) / 2 ) ;
	cout << ( sm / aux ) << "\n" ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
#include<set>
using namespace std ;

#define MAXN 100007

int n ;
long long a[ MAXN ] ;

long long pref[ MAXN ] ;
long long suff[ MAXN ] ;

vector < pair < int , int > > v ;

pair < int , int > emp ;

long long pw2[ MAXN ] ;

void add ( long long val ) {
	int i ;
	int pos = 1 ;
	for ( i = 40 ; i >= 0 ; i -- ) {
		long long u = pw2[ i ] ;
		if ( ( val & u ) == 0 ) {
			if ( v[ pos ].first == 0 ) {
				v.push_back ( emp ) ;
				v[ pos ].first = v.size ( ) - 1 ;
			}
			pos = v[ pos ].first ;
		}
		else {	
			if ( v[ pos ].second == 0 ) {
				v.push_back ( emp ) ;
				v[ pos ].second = v.size ( ) - 1 ;
			}
			pos = v[ pos ].second ;		
		}
	}
}

long long query ( long long val ) {
	int i ;
	int pos = 1 ;
	long long ret = 0 ;
	for ( i = 40 ; i >= 0 ; i -- ) {
		long long u = pw2[ i ] ;
		if ( ( val & u ) == 0 ) {
			if ( v[ pos ].second != 0 ) {
				ret += u ;
				pos = v[ pos ].second ;
			}
			else {
				pos = v[ pos ].first ;
			}
		}
		else {
			if ( v[ pos ].first != 0 ) {
				ret += u ;
				pos = v[ pos ].first ;
			}
			else {
				pos = v[ pos ].second ;
			}
		}
	}
	return ret ;
}

void input ( ) {
	cin >> n ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		cin >> a[ i ] ;
	}
}

void solve ( ) {
	v.resize ( 2 ) ;
	int i ;
	pw2[ 0 ] = 1 ;
	for ( i = 1 ; i <= 40 ; i ++ ) {
		pw2[ i ] = ( 2 * pw2[ i - 1 ] ) ;
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		pref[ i ] = ( pref[ i - 1 ] ^ a[ i ] ) ;
	}
	for ( i = n ; i >= 1 ; i -- ) {
		suff[ i ] = ( suff[ i + 1 ] ^ a[ i ] ) ;
	}
	add ( 0 ) ;
	long long ans = 0 ;
	for ( i = 1 ; i <= n + 1 ; i ++ ) {
		ans = max ( ans , query ( suff[ i ] ) ) ;
		add ( pref[ i ] ) ;
	}
	cout << ans << "\n" ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
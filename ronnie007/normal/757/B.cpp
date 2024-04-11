#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#include<iomanip>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;

vector < int > v[ MAXN ] ;

int br[ MAXN ] ;

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
}

void solve ( ) {
	int i , j ;
	for ( i = 2 ; i <= 100000 ; i ++ ) {
		if ( v[ i ].size ( ) != 0 ) { continue ; }
		for ( j = i ; j <= 100000 ; j += i ) {
			v[ j ].push_back ( i ) ;
		}
	}
	int ans = 1 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		int sz = v[ a[ i ] ].size ( ) ;
		for ( j = 0 ; j < sz ; j ++ ) {
			br[ v[ a[ i ] ][ j ] ] ++ ;
			if ( ans < br[ v[ a[ i ] ][ j ] ] ) {
				ans = br[ v[ a[ i ] ][ j ] ] ;
			}
		}
	}
	printf ( "%d\n" , ans ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
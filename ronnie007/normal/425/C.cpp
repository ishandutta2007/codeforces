#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<map>
using namespace std ;

#define MAXN 100007

int n , m , s , e ;
int a[ MAXN ] ;
int b[ MAXN ] ;

vector < int > v[ MAXN ] ;

int where[ MAXN ][ 300 ] ;

int find ( int id , int val ) {
	int l , r , mid ;
	l = 0 ;
	r = v[ id ].size ( ) - 1 ;
	if ( r < 0 ) { return -1 ; }
	if ( v[ id ][ r ] <= val ) { return -1 ; }
	while ( r - l > 3 ) {
		mid = ( l + r ) / 2 ;
		if ( v[ id ][ mid ] <= val ) { l = mid ; }
		else { r = mid ; }
	}
	while ( v[ id ][ l ] <= val ) { l ++ ; }
	return v[ id ][ l ] ;
}

void input ( ) {
	scanf ( "%d%d%d%d" , &n , &m , &s , &e ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
	for ( i = 1 ; i <= m ; i ++ ) {
		scanf ( "%d" , &b[ i ] ) ;
		v[ b[ i ] ].push_back ( i ) ;
	}
}

void solve ( ) {
	int i , j ;
	int ans = 0 ;
	int lst ;
	for ( j = 1 ; j <= 300 ; j ++ ) {
		if ( j == 1 ) { lst = 0 ; }
		else { lst = m + 27 ; }
		for ( i = 1 ; i <= n ; i ++ ) {
			int u = find ( a[ i ] , lst ) ;
			if ( u != -1 ) {
				if ( j * e + i + u <= s ) {
					ans = j ;
					where[ i ][ j ] = u ;
				}
				else { where[ i ][ j ] = -1 ; }
			}
			else { where[ i ][ j ] = -1 ; }
			if ( where[ i ][ j - 1 ] > 0 && lst > where[ i ][ j - 1 ] ) { lst = where[ i ][ j - 1 ] ; }
		}
		if ( ans != j ) { break ; }
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
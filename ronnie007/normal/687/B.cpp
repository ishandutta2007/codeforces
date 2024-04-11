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

#define MAXN 1000007

int n , k ;

int br[ MAXN ] ;
int cur[ MAXN ] ;
vector < int > divs[ MAXN ] ;
void input ( ) {
	scanf ( "%d%d" , &n , &k ) ;
	int i , j ;
	int x ; 
	for ( i = 2 ; i <= 1000000 ; i ++ ) {
		if ( divs[ i ].size ( ) != 0 ) { continue ; }
		for ( j = i ; j <= 1000000 ; j += i ) {
			int p = j ;
			while ( ( p % i ) == 0 ) {
				p /= i ;
				divs[ j ].push_back ( i ) ;
			}
		}
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &x ) ;
		int sz = divs[ x ].size ( ) ;
		for ( j = 0 ; j < sz ; j ++ ) {
			cur[ divs[ x ][ j ] ] ++ ;
			if ( br[ divs[ x ][ j ] ] < cur[ divs[ x ][ j ] ] ) {
				br[ divs[ x ][ j ] ] = cur[ divs[ x ][ j ] ] ;
			}
		}
		for ( j = 0 ; j < sz ; j ++ ) {
			cur[ divs[ x ][ j ] ] -- ;
		}
	}
}

void solve ( ) {
	int i ;
	for ( i = 2 ; i <= 1000000 ; i ++ ) {
		while ( br[ i ] != 0 && ( k % i ) == 0 ) { k /= i ; br[ i ] -- ; }
	}
	if ( k == 1 ) { printf ( "Yes\n" ) ; }
	else { printf ( "No\n" ) ; }
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
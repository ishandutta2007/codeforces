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

#define MAXN 200007

int n , k ;
int a[ MAXN ] ;

int f[ MAXN ] ;

vector < int > v ;

void input ( ) {
	scanf ( "%d%d" , &n , &k ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
}

void solve ( ) {
	int i , j ;
	int tot = 0 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( a[ i ] < 0 ) { f[ i ] = 1 ; tot ++ ; }
	}
	if ( tot > k ) { printf ( "-1\n" ) ; return ; }
	f[ 0 ] = f[ n + 1 ] = 1 ;
	int br = 0 ;
	int u = 1 ;
	while ( u <= n && f[ u ] == 0 ) { u ++ ; }
	if ( u > n ) { printf ( "0\n" ) ; return ; }
	for ( i = u ; i <= n ; i ++ ) {
		if ( f[ i ] == 0 ) { br ++ ; }
		else {
			if ( br != 0 ) {
				v.push_back ( br ) ;
				br = 0 ;
			}
		}
	}
	sort ( v.begin ( ) , v.end ( ) ) ;
	int ans = 2 * v.size ( ) + 1 ;
	if ( br != 0 ) { ans ++ ; }
	int sz = v.size ( ) ;
	int cur = tot ;
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( cur + v[ i ] > k ) { break ; }
		cur += v[ i ] ;
		ans -= 2 ;
	}
	int ret = ans ;
	if ( br != 0 ) {
		cur = tot + br ;
		ans = 2 * v.size ( ) + 1 ;
		for ( i = 0 ; i < sz ; i ++ ) {
			if ( cur + v[ i ] > k ) { break ; }
			cur += v[ i ] ;
			ans -= 2 ;
		}
		if ( cur <= k ) {
			ret = min ( ret , ans ) ;
		}
	}

	printf ( "%d\n" , ret ) ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
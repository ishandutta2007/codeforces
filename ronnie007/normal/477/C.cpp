#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
using namespace std ;

#define inf 1000000007
#define MAXN 2007

int n , sz ;
string a ;
string b ;

int dp[ MAXN ][ MAXN ] ;
int cost[ MAXN ][ MAXN ] ;

int f ( int st ) {
	int l = 1 ;
	int r = st ;
	int mid ;
	while ( r - l > 3 ) {
		mid = ( l + r ) / 2 ;
		if ( cost[ mid ][ st ] != -1 ) { l = mid ; }
		else { r = mid ; }
	}
	while ( r > l && cost[ r ][ st ] == -1 ) { r -- ; }
	return r ;
}

void input ( ) ;
void solve ( ) ;

int main ( )  {
    ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}

void input ( ) {
	cin >> a ;
	a = ( '#' + a ) ;
	n = a.size ( ) - 1 ;
	cin >> b ;
	sz = b.size ( ) ;
}

void solve ( ) {
	int i , j ;
	for ( i = 0 ; i <= n ; i ++ ) {
		for ( j = 0 ; j <= n ; j ++ ) {
			dp[ i ][ j ] = -inf ;
		}
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		int cur = 0 ;
		int br = 0 ;
		for ( j = i ; j <= n ; j ++ ) {
			if ( cur != sz && a[ j ] != b[ cur ] ) { br ++ ; }
			if ( cur != sz && a[ j ] == b[ cur ] ) { cur ++ ; }
			if ( cur == sz ) { cost[ i ][ j ] = br ; }
			else { cost[ i ][ j ] = -1 ; }
		}
	}
	dp[ 0 ][ 0 ] = 0 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = 0 ; j <= i ; j ++ ) {
			if ( a[ i ] == b[ sz - 1 ] ) {
				int id = f ( i ) ;
				if ( cost[ id ][ i ] <= j ) {
					if ( cost[ id ][ i ] >= 0 && dp[ id - 1 ][ j - cost[ id ][ i ] ] >= 0 ) {
						dp[ i ][ j ] = max ( dp[ i ][ j ] , dp[ id - 1 ][ j - cost[ id ][ i ] ] + 1 ) ;
					}
				}
			}
			dp[ i ][ j ] = max ( dp[ i ][ j ] , dp[ i - 1 ][ j ] ) ;
			if ( j != 0 && dp[ i - 1 ][ j - 1 ] >= 0 ) {
				dp[ i ][ j ] = max ( dp[ i ][ j ] , dp[ i - 1 ][ j - 1 ] ) ;
			}
		}
	}
	for ( i = 0 ; i <= n ; i ++ ) {
		printf ( "%d" , dp[ n ][ i ] ) ;
		if ( i == n ) { printf ( "\n" ) ; }
		else { printf ( " " ) ; }
	}
}
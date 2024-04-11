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

#define MAXN 100007

int n , m ; 
int d[ MAXN ] ;
int h[ MAXN ] ;

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
	scanf ( "%d%d" , &n , &m ) ;
	int i ;
	for ( i = 0 ; i < m ; i ++ ) {
		scanf ( "%d%d" , &d[ i ] , &h[ i ] ) ;
    }
}

void solve ( ) {
	int i ;
	int ans = 0 ;
	for ( i = 1 ; i < m ; i ++ ) {
		if ( abs ( h[ i ] - h[ i - 1 ] ) > d[ i ] - d[ i - 1 ] ) { 
			printf ( "IMPOSSIBLE\n" ) ;
			return ;
		}
		int cur = ( d[ i ] - d[ i - 1 ] ) - ( abs ( h[ i ] - h[ i - 1 ] ) ) ;
		cur /= 2 ;
		if ( ans < max ( h[ i - 1 ] , h[ i ] ) + cur ) { ans = max ( h[ i ] , h[ i - 1 ] ) + cur ; }
    }
	if ( ans < h[ m - 1 ] + ( n - d[ m - 1 ] ) ) { ans = h[ m - 1 ] + ( n - d[ m - 1 ] ) ; }
	if ( ans < h[ 0 ] + ( d[ 0 ] - 1 ) ) { ans = h[ 0 ] + ( d[ 0 ] - 1 ) ; }
	printf ( "%d\n" , ans ) ;
}
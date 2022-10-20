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

#define MAXN 200007
#define inf 1000000007

int n , k ;
int a[ MAXN ] ;
bool g[ MAXN ] ;

void input ( ) {
	scanf ( "%d%d" , &n , &k ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
}

void solve ( ) {
	int ans = 0 ;
	if ( a[ k ] != 0 ) { ans ++ ; a[ k ] = 0 ; }
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( i == k ) { continue ; }
		if ( a[ i ] == 0 ) { a[ i ] = inf ; }
	}
	sort ( a + 1 , a + n + 1 ) ;
	stack < int > s ;
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( a[ i ] >= n ) { continue ; }
		g[ a[ i ] ] = true ;
	}
	for ( i = n - 1 ; i >= 0 ; i -- ) {
		if ( g[ i ] == false ) { s.push ( i ) ; }
	}
	for ( i = n ; i >= 1 ; i -- ) {
		if ( s.empty ( ) == true || a[ i ] < s.top ( ) ) { break ; }
		s.pop ( ) ;
		ans ++ ;
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
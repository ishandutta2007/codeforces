#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
#include<set>
#include<stack>
using namespace std ;

#define MAXN 100007

int n , d ;
pair < int , int > a[ MAXN ] ;

long long pref[ MAXN ] ;

int get ( int st , int val ) {
	int l = st ;
	int r = n ;
	int mid ;
	while ( r - l > 3 ) {
		mid = ( l + r ) / 2 ;
		if ( a[ mid ].first < val ) { l = mid ; }
		else { r = mid ; }
	}
	while ( r >= l && a[ r ].first >= val ) { r -- ; }
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


void input ( )  {
	scanf ( "%d%d" , &n , &d ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
	}
	sort ( a + 1 , a + n + 1 ) ;
	for ( i = 1 ; i <= n ; i ++ ) {
		pref[ i ] = pref[ i - 1 ] + a[ i ].second ;
	}
}

void solve ( ) {
	int i ;
	long long ans = 0 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		int id = get ( i , a[ i ].first + d ) ;
		long long cur = pref[ id ] - pref[ i - 1 ] ;
		if ( ans < cur ) { ans = cur ; }
	}
	printf ( "%I64d\n" , ans ) ;
}
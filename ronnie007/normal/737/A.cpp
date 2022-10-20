#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#include<map>
using namespace std ;

#define MAXN 200007

int n , k ;
long long s , t ;
pair < long long , long long > u[ MAXN ] ;

long long a[ MAXN ] ;

bool f ( long long val ) {
	int i ;
	long long cur = 0 ;
	for ( i = 0 ; i <= k ; i ++ ) {
		long long dist = a[ i + 1 ] - a[ i ] ;
		if ( val < dist ) { return false ; }
		long long h = ( val - dist ) ;
		if ( h >= dist ) {
			cur += dist ;
		}
		else {
			cur += h ;
			cur += 2 * ( dist - h ) ;
		}
		if ( cur > t ) { return false ; }
	}
	return true ;
}

void input ( ) {
	scanf ( "%d%d" , &n , &k ) ;
	scanf ( "%I64d%I64d" , &s , &t ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%I64d%I64d" , &u[ i ].first , &u[ i ].second ) ;
	}
	for ( i = 1 ; i <= k ; i ++ ) {
		scanf ( "%I64d" , &a[ i ] ) ;
	}
	sort ( a + 1 , a + k + 1 ) ;
	a[ 0 ] = 0 ;
	a[ k + 1 ] = s ; 
}

void solve ( ) {
	if ( t < s ) { printf ( "-1\n" ) ; return ; }
	long long l , r , mid ;
	l = r = 1 ;
	int i ;
	for ( i = 1 ; i <= 12 ; i ++ ) { r *= 10 ; }
	while ( ( r - l ) > 3 ) {
		mid = ( l + r ) / 2 ;
		if ( f ( mid ) == true ) { r = mid ; }
		else { l = mid ; }
	}
	while ( f ( l ) == false ) { l ++ ; }
	long long ans = -1 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( u[ i ].second < l ) { continue ; }
		if ( ans == -1 || ans > u[ i ].first ) { ans = u[ i ].first ; }
	}
	printf ( "%I64d\n" , ans ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
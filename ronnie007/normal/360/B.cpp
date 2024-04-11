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

#define MAXN 2007

int n , k ;
long long a[ MAXN ] ;
long long dp[ MAXN ] ;

bool f ( long long x ) {
	int i , j ;
	for ( i = 1 ; i <= n ; i ++ ) { dp[ i ] = i ; }
	dp[ 0 ] = 0 ;
	dp[ 1 ] = 0 ;
	for ( i = 0 ; i <= n ; i ++ ) {
		for ( j = i + 1 ; j <= n ; j ++ ) {
			long long val = abs ( a[ j ] - a[ i ] ) ;
			if ( i == 0 ) { val = 0 ; }
			if ( val <= ( j - i ) * x ) {
				dp[ j ] = min ( dp[ j ] , dp[ i ] + ( j - i - 1 ) ) ;
			}
		}
	}
	for ( i = 0 ; i <= n ; i ++ ) {
		long long cur = dp[ i ] + ( n - i ) ;
		if ( cur <= k ) { return true ; }
	}
	return false ;
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
	scanf ( "%d%d" , &n , &k ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%I64d" , &a[ i ] ) ;
	}
}

void solve ( ) {
	long long l , r , mid ;
	l = 0 ; r = 0 ;
	for ( int i = 2 ; i <= n ; i ++ ) { r = max ( r , abs ( a[ i ] - a[ i - 1 ] ) ) ; }
	while ( r - l > 3 ) {
		mid = ( l + r ) / 2 ;
		if ( f ( mid ) == true ) { r = mid ; }
		else { l = mid ; }
	}
	while ( f ( l ) == false ) { l ++ ; }
	printf ( "%I64d\n" , l ) ;
}
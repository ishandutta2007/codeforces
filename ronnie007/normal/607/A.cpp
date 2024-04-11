#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

#define MAXN 100007
#define inf 1000000007

int n ;
pair < int , int > a[ MAXN ] ;

int dp[ MAXN ] ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ; 
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
	}
	sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
	int ans = 2 ;
	int i ;
	a[ 0 ].first = -inf ;
	dp[ 0 ] = 0 ;
	dp[ 1 ] = 1 ;
	for ( i = 2 ; i <= n ; i ++ ) {
		int l , r , mid ;
		int x = ( a[ i ].first - a[ i ].second ) ;
		l = 0 ;
		r = i - 1 ;
		while ( r - l > 3 ) {
			mid = ( l + r ) / 2 ;
			if ( a[ mid ].first < x ) { l = mid ; }
			else { r = mid ; }
		}
		while ( a[ r ].first >= x ) { r -- ; }
		dp[ i ] = dp[ r ] + 1  ;
		ans = max ( ans , dp[ i ] + 1 ) ;
	}
	printf ( "%d\n" , ( n + 1 ) - ans ) ;
}
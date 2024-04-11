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
#define MAXN 100007

int n ;

pair < int , int > a[ MAXN ] ;

int dp[ MAXN ][ 2 ] ;

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
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
    }
	a[ n + 1 ].first = 2 * inf ;
}

void solve ( ) {
	int i , j ;
	dp[ 1 ][ 0 ] = 1 ;
	if ( a[ 1 ].first + a[ 1 ].second < a[ 2 ].first ) { dp[ 1 ][ 1 ] = 1 ; }
	for ( i = 2 ; i <= n ; i ++ ) {
		dp[ i ][ 0 ] = dp[ i - 1 ][ 0 ] ;
		if ( a[ i ].first - a[ i ].second > a[ i - 1 ].first ) {
			dp[ i ][ 0 ] = max ( dp[ i ][ 0 ] , dp[ i - 1 ][ 0 ] + 1 ) ;
        }
		if ( a[ i ].first - a[ i ].second > a[ i - 1 ].first + a[ i - 1 ].second ) {
			dp[ i ][ 0 ] = max ( dp[ i ][ 0 ] , dp[ i - 1 ][ 1 ] + 1 ) ; 
        }
		if ( a[ i - 1 ].first + a[ i - 1 ].second < a[ i ].first ) {
			dp[ i ][ 0 ] = max ( dp[ i ][ 0 ] , dp[ i - 1 ][ 1 ] ) ;
        }

		if ( a[ i ].first + a[ i ].second < a[ i + 1 ].first ) {
			dp[ i ][ 1 ] = dp[ i - 1 ][ 0 ] + 1 ;
			if ( a[ i - 1 ].first + a[ i - 1 ].second < a[ i ].first ) { 
				dp[ i ][ 1 ] = max ( dp[ i ][ 1 ] , dp[ i - 1 ][ 1 ] + 1 ) ;
            }
        }
		//printf ( "dp[ %d ][ 0 ] = %d , dp[ %d ][ 1 ] = %d\n" , i , dp[ i ][ 0 ] , i , dp[ i ][ 1 ] ) ;
    }
	printf ( "%d\n" , max ( dp[ n ][ 0 ] , dp[ n ][ 1 ] ) ) ;
}
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

#define MAXN 107

int n , t ;
int a[ 2 * MAXN * MAXN ] ;
map < int , int > ZX ;
vector < int > vals ;
int br[ MAXN ] ;
int BEST[ MAXN ] ;
int END[ MAXN ] ;
int tp ;

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
	scanf ( "%d%d" , &n , &t ) ;
	int i ;
	for ( i = 0 ; i < n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
		vals.push_back ( a[ i ] ) ;
	}
	sort ( vals.begin ( ) , vals.end ( ) ) ;
	tp = 1 ;
	for ( i = 0 ; i < n ; i ++ ) {
		if ( i != 0 && vals[ i ] == vals[ i - 1 ] ) { continue ; }
		ZX[ vals[ i ] ] = tp ;
		tp ++ ;
	}
	tp -- ;
	for ( i = 0 ; i < n ; i ++ ) {
		a[ i ] = ZX[ a[ i ] ] ;
		br[ a[ i ] ] ++ ;
	}
}

void solve ( ) {
	int i , j ;
	for ( i = n ; i < 2 * n * n ; i ++ ) { a[ i ] = a[ i - n ] ; }
	int ans = 0 ;
	if ( t <= 2 * n ) {
		for ( i = 0 ; i < n * t ; i ++ ) {
			int cur = 0 ;
			for ( j = 0 ; j <= a[ i ] ; j ++ ) {
				cur = max ( cur , BEST[ j ] + 1 ) ;
			}
			BEST[ a[ i ] ] = cur ;
			if ( ans < cur ) { ans = cur ; }
		}
		printf ( "%d\n" , ans ) ;
		return ;
	}
	for ( i = 0 ; i < n * n ; i ++ ) {
		int cur = 0 ;
		for ( j = 0 ; j <= a[ i ] ; j ++ ) {
			cur = max ( cur , BEST[ j ] + 1 ) ;
		}
		BEST[ a[ i ] ] = cur ;
	}
	for ( i = n * n - 1 ; i >= 0 ; i -- ) {
		int cur = 0 ;
		for ( j = tp ; j >= a[ i ] ; j -- ) {
			cur = max ( cur , END[ j ] + 1 )  ;
		}
		END[ a[ i ] ] = cur ;
	}
	for ( i = 1 ; i <= tp ; i ++ ) {
		int cur = BEST[ i ] + END[ i ] + br[ i ] * ( t - 2 * n ) ;
		if ( ans < cur ) { ans = cur ; }
	}
	printf ( "%d\n" , ans ) ;
}
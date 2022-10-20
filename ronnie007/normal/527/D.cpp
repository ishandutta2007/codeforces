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

int n ;
pair < int , int > a[ MAXN ] ;

bool cmp ( pair < int , int > p1 , pair < int , int > p2 ) {
	return ( p1.second < p2.second ) ;
}

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		int u ;
		scanf ( "%d%d" , &a[ i ].first , &u ) ;
		a[ i ].second = a[ i ].first ;
		a[ i ].first -= u ;
		a[ i ].second += u ; 
	}
	sort ( a + 1 , a + n + 1 , cmp ) ;
}

void solve ( ) {
	int i ;
	int lst = a[ 1 ].second ;
	int ans = 1 ;
	for ( i = 2 ; i <= n ; i ++ ) {
		if ( lst <= a[ i ].first ) { lst = a[ i ].second ; ans ++ ; }
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
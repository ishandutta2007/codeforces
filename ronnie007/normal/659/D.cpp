#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std ;

#define MAXN 1007

#define eps 0.1

int n ;
pair < double , double > a[ MAXN ] ;


double det ( pair < double , double > p1 , pair < double , double > p2 , pair < double , double > p3 ) {
	double k = p1.first * p2.second + p1.second * p3.first + p2.first * p3.second ;
	k -= p3.first * p2.second + p3.second * p1.first + p2.first * p1.second ;
	return k ;
}

void input ( ) {
	cin >> n ;
	int i ;
	for ( i = 1 ; i <= n + 1 ; i ++ ) {
		cin >> a[ i ].first >> a[ i ].second ;
	}
}

void solve ( ) {
	int i ;
	int ans = 0 ;
	for ( i = 3 ; i <= n + 1 ; i ++ ) {
		if ( det ( a[ i - 2 ] , a[ i - 1 ] , a[ i ] ) > 0 ) { ans ++ ; }
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
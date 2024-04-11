#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
#include<set>
using namespace std ;

#define MAXN 100007

int n , p , q ;
int a[ MAXN ] ;

void input ( ) {
	scanf ( "%d%d%d" , &n , &p , &q ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
		a[ i ] = -a[ i ] ;
	}
}

void solve ( ) {
	double sm1 , sm2 ;
	sm1 = sm2 = 0.0000 ;
	if ( p > q ) { swap ( p , q ) ; }
	sort ( a + 1 , a + n + 1 ) ;
	int i ;
	for ( i = 1 ; i <= p ; i ++ ) {
		sm1 += ( -a[ i ] ) ;
	}
	for ( i = p + 1 ; i <= p + q ; i ++ ) {
		sm2 += ( -a[ i ] ) ;
	}
	double ans = ( sm1 / p ) + ( sm2 / q ) ;
	printf ( "%.12lf\n" , ans ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
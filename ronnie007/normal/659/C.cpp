#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
using namespace std ;

#define MAXN 100007

int n , m ; 
int a[ MAXN ] ; 

void input ( ) {
	scanf ( "%d%d" , &n , &m ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
	sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
	vector < int > v ;
	int i ;
	i = 0 ;
	int id = 1 ; 
	while ( 1 ) {
		i ++ ;
		if ( a[ id ] == i ) { id ++ ; continue ; }
		if ( m >= i ) { m -= i ; v.push_back ( i ) ; }
		else { break ; }
	}
	int sz = v.size ( ) ;
	printf ( "%d\n" , sz ) ;
	for ( i = 0 ; i < sz ; i ++ ) {
		printf ( "%d" , v[ i ] ) ;
		if ( i == sz - 1 ) { printf ( "\n" ) ; }
		else { printf ( " " ) ; }
	}
}


int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
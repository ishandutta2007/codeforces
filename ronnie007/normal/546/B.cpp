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
using namespace std ;

#define MAXN 3007

int n ;
int a[ MAXN ] ;

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
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 0 ; i < n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
    }
	sort ( a , a + n ) ;
}

void solve ( )  {
	int i ;
	int ans = 0 ;
	for ( i = 1 ; i < n ; i ++ ) {
		if ( a[ i ] <= a[ i - 1 ] ) { ans += ( a[ i - 1 ] - a[ i ] + 1 ) ; a[ i ] = a[ i - 1 ] + 1 ; }
    }
	printf ( "%d\n" , ans ) ;
}
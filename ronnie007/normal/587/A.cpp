#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

#define MAXN 2000007

int n ;
int a[ MAXN ] ;

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
	int x ;
	for ( i = 1 ; i <= n ; i ++ ) { 
		scanf ( "%d" , &x ) ;
		a[ x ] ++ ;
	}
}

void solve ( ) {
	int i ;
	int ans = 0 ;
	for ( i = 0 ; i <= 2000000 ; i ++ ) {
		int u = a[ i ] / 2 ;
		a[ i + 1 ] += u ;
		if ( a[ i ] % 2 == 1 ) { ans ++ ; }
	}
	printf ( "%d\n" , ans ) ;
}
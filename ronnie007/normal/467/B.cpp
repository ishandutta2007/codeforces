#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
using namespace std ;

int n , m , k ;
int a[ 1007 ] ; 

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
	scanf ( "%d%d%d" , &n , &m , &k ) ;
	int i ;
	for ( i = 0 ; i <= m ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
}

void solve ( )  {
	int i , j , t ;
	int br = 0 ; 
	int ret = 0 ; 
	int b1 = 0 ;
	int b2 = 0 ; 
	for ( i = 0 ; i < m ; i ++ ) {
		br = 0 ;
		for ( j = 0 ; j < n ; j ++ ) {
			b1 = ( a[ i ] & (1<<j)) ;
			b2 = ( a[ m ] & (1<<j)) ;
			if ( b1 != b2 ) br ++ ;
		}
		if ( br <= k ) ret ++ ; 
	}
	printf ( "%d\n" , ret ) ;
}
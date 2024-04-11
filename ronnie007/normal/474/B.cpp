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

int n ;
int a[ 200007 ] ;
int s[ 2000007 ] ; 

void input ( ) ;
void solve ( ) ;




int main ( )  {
    //ios::sync_with_stdio ( false ) ;
    //cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
}

void solve ( )  {
	int br = 0 ; 
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {	
		while ( a[ i ] != 0 ) {
			br ++ ;
			s[ br ] = i ; 
			a[ i ] -- ; 
		}
	}
	int q ;
	int x ;
	scanf ( "%d" , &q ) ;
	while ( q != 0 ) {
		scanf ( "%d" , &x ) ;
		printf ( "%d\n" , s[ x ] ) ;
		q -- ;
	}
}
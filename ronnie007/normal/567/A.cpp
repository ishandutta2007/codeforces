#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

#define MAXN 100007

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


void input ( )  {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( )  {
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( i == 1 ) {
			printf ( "%d %d\n" , a[ i + 1 ] - a[ i ] , a[ n ] - a[ i ] ) ;
        }
		else if ( i == n ) { 
			printf ( "%d %d\n" , a[ n ] - a[ n - 1 ] , a[ n ] - a[ 1 ] ) ;
        }
		else {
			printf ( "%d %d\n" , min ( a[ i + 1 ] - a[ i ] , a[ i ] - a[ i - 1 ] ) , max ( a[ i ] - a[ 1 ] , a[ n ] - a[ i ] ) ) ;
        }
    }
}
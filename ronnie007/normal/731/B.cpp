#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;

void input ( ) {
	scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
    	if ( ( a[ i ] % 2 ) == 1 ) {
        	if ( i != n && ( a[ i + 1 ] != 0 ) ) { a[ i ] -- ; a[ i + 1 ] -- ; }
        }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
    	if ( ( a[ i ] % 2 ) != 0 ) { printf ( "NO\n" ) ; return ; }
    }
    printf ( "YES\n" ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
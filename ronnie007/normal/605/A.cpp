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
int dp[ MAXN ] ;
int used[ MAXN ] ;

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
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
}

void solve ( ) {
	int i ;
	int ans = 0 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		used[ a[ i ] ] = 1 ;
		if ( used[ a[ i ] - 1 ] == 1 ) {
			dp[ a[ i ] ] = dp[ a[ i ] - 1 ] + 1 ;
		}
		else { dp[ a[ i ] ] = 1 ; }
		ans = max ( ans , dp[ a[ i ] ] ) ;
	}
	printf ( "%d\n" , n - ans ) ;
}
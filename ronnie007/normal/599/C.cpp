#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;
int b[ MAXN ] ;

map < int , int > ZX ;

void input ( ) ;
void solve ( ) ;

int main ( )  {
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
		b[ i ] = a[ i ] ;
	}
	sort ( b + 1 , b + n + 1 ) ;
}

void solve ( ) {
	int br = 0 ;
	int i ;
	int ans = 0 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( ZX[ a[ i ] ] == 0 ) { br ++ ; }
		ZX[ a[ i ] ] ++ ;
		if ( ZX[ b[ i ] ] == 1 ) { br -- ; }
		ZX[ b[ i ] ] -- ;
		if ( br == 0 ) { ans ++ ; }
	}
	printf ( "%d\n" , ans ) ;
}
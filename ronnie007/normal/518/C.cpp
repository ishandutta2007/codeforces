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

int n , m , k ;
int a[ MAXN ] ;
int pos[ MAXN ] ;


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
	scanf ( "%d%d%d" , &n , &m , &k ) ;
	int i ;
	for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , &a[ i ] ) ; pos[ a[ i ] ] = i ; }
}

void solve ( ) {
	int x ;
	int y ;
	int num1 , num2 ;
	long long ans = 0 ;
	while ( m != 0 ) {
		scanf ( "%d" , &x ) ;
		m -- ;
		ans += ( pos[ x ] / k + 1 ) ;
		if ( pos[ x ] == 0 ) { continue ; }
		num1 = x ;
		num2 = a[ pos[ x ] - 1 ] ;
		x = pos[ x ] ;
		y = x - 1 ; 
		swap ( pos[ num1 ] , pos[ num2 ] ) ;
		swap ( a[ x ] , a[ y ] ) ;
    }
	printf ( "%I64d\n" , ans ) ;
}
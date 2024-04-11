#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

#define MAXN 507

int n , sz ;
int a[ MAXN * MAXN ] ;
map < int , int > ZX ;

int f ( int x , int y ) {
	if ( x < y ) { swap ( x , y ) ; }
	if ( y == 0 ) { return x ; }
	return f ( y , x % y ) ;
}

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
	sz = n * n ;
	int i ;
	for ( i = 1 ; i <= sz ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
		ZX[ a[ i ] ] ++ ;
	}
	sort ( a + 1 , a + sz + 1 ) ;
}

void solve ( ) {
	int i ;
	vector < int > v ;
	while ( n != 0 ) {
		for ( i = sz ; i >= 1 ; i -- ) {
			int val = ZX[ a[ i ] ] ;
			if ( val == 0 ) { continue ; }
			break ;
		}
		int u = a[ i ] ;
		ZX[ u ] -- ;
		int p = v.size ( ) ;
		for ( i = 0 ; i < p ; i ++ ) {
			int val = f ( u , v[ i ] ) ;
			ZX[ val ] -= 2 ;
		}
		v.push_back ( u ) ;
		n -- ;
		if ( n == 0 ) { break ; }
	}
	int p = v.size ( ) ;
	for ( i = 0 ; i < p ; i ++ ) {
		printf ( "%d" , v[ i ] ) ;
		if ( i == p - 1 ) { printf ( "\n" ) ; }
		else { printf ( " " ) ; }
	}
}
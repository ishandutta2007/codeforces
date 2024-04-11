#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
using namespace std ;

int n , m ;

int x , y ;

int perm[ 17 ] ;

int ans = 0 ;

void f ( ) {
	int u1 , u2 ;
	u1 = u2 = 0 ;
	int i ;
	/**for ( i = 0 ; i < 7 ; i ++ ) {
		printf ( "%d " , perm[ i ] ) ;
	}**/
	//printf ( "\n" ) ;
	for ( i = 0 ; i < x ; i ++ ) {
		u1 = u1 * 7 + perm[ i ] ;
	}
	for ( i = x ; i < x + y ; i ++ ) {
		u2 = u2 * 7 + perm[ i ] ;
	}
	//printf ( "%d %d\n" , u1 , u2 ) ;
	if ( u1 >= n || u2 >= m ) { return ; }
	ans ++ ;
}

void input ( ) {
	scanf ( "%d%d" , &n , &m ) ;
}

void solve ( ) {
	int k = n - 1 ;
	x = 0 ;
	while ( k != 0 ) {
		k /= 7 ;
		x ++ ;
	}
	k = m - 1 ;
	y = 0 ;
	while ( k != 0 ) {
		k /= 7 ;
		y ++ ;
	}
	if ( x == 0 ) { x = 1 ; }
	if ( y == 0 ) { y = 1 ; }
	if ( x + y > 7 ) { printf ( "0\n" ) ; return ; }
	int i ;
	for ( i = 0 ; i < 7 ; i ++ ) { perm[ i ] = i ; }
	while ( 1 ) {
		f ( ) ;
		if ( next_permutation ( perm , perm + 7 ) == false ) { break ; }
	}
	int lft = 7 - ( x + y ) ;
	while ( lft != 0 ) { ans /= lft ; lft -- ; }
	printf ( "%d\n" , ans ) ;
}


int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
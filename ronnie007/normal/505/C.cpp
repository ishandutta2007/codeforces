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

#define OFFSET 250

int n , d ;

int a[ 30007 ] ;
int dp[ 30007 ][ 600 ] ;


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
	scanf ( "%d%d" , &n , &d ) ;
	int i ;
	int x ;
	for ( i = 0 ; i < n ; i ++ ) {
		scanf ( "%d" , &x ) ;
		a[ x ] ++ ;
    }
}

void solve ( ) {
	int i , j ;
	int ans = 0 ;
	int e ; 
	for ( i = 0 ; i <= 30000 ; i ++ ) {
		for ( j = 0 ; j <= 507 ; j ++ ) {
			dp[ i ][ j ] = -1 ;
        }
    }
	dp[ d ][ OFFSET ] = a[ d ]  ;
	for ( i = d ; i <= 30000 ; i ++ ) {
		for ( j = -250 ; j <= 250 ; j ++ ) {
			if ( dp[ i ][ j + OFFSET ] == -1 ) { continue ; }
			if ( ans < dp[ i ][ j + OFFSET ] ) { ans = dp[ i ][ j + OFFSET ] ; }
			for ( e = j - 1 ; e <= j + 1 ; e ++ ) {
				if ( d + e >= 1 && i + d + e <= 30000 ) {
					int nx = i + d + e ;
					int ny = e ;
					if ( dp[ nx ][ ny + OFFSET ] == -1 || dp[ nx ][ ny + OFFSET ] < dp[ i ][ j + OFFSET ] + a[ nx ] ) {
						dp[ nx ][ ny + OFFSET ] = dp[ i ][ j + OFFSET ] + a[ nx ] ; 
                    }
	            }
			}
        }
    }
	printf ( "%d\n" , ans ) ;
}
#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<set>
using namespace std ;

int n , m , k ;
int a[ 27 ] ;
int c[ 27 ][ 27 ] ;
int used[ 27 ] ;
long long dp[ 300007 ][ 23 ] ;

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
	scanf ( "%d%d%d" , &n , &m , &k ) ;
	int i ;
	for ( i = 0 ; i < n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
	int x , y , z ; 
	for ( i = 0 ; i < k ; i ++ ) {
		scanf ( "%d%d%d" , &x , &y , &z ) ;
		x -- ; y -- ; 
		c[ x ][ y ] = z ;
	}
}
 
void solve ( ) {
	dp[ 0 ][ 0 ] = 0 ;
	int i , j , t ;
	int lim = (1<<n) ;
	long long ans = 0 ;
	vector < int > pos1 , pos2 ; 
	int sz1 , sz2 ; 
	for ( i = 0 ; i < lim ; i ++ ) {
		pos1.clear ( ) ;
		pos2.clear ( ) ;
		if ( i == 0 ) { pos1.push_back ( n + 1 ) ; }
		for ( j = 0 ; j < n ; j ++ ) {
			if ( ( i & ( ( 1 << j ) ) ) == 0 ) { pos2.push_back ( j ) ; }
			else { pos1.push_back ( j ) ; }
		}
		sz1 = pos1.size ( ) ;
		sz2 = pos2.size ( ) ;

		for ( j = 0 ; j < sz1 ; j ++ ) {
		//printf ( "dp[ %d ][ %d ] = %d\n" , i , j , dp[ i ][ j ] ) ;
			if ( i != 0 && sz1 == m ) {
				if ( ans < dp[ i ][ pos1[ j ] ] ) { ans = dp[ i ][ pos1[ j ] ] ; }
				continue ;
			}
			for ( t = 0 ; t < sz2 ; t ++ ) {
				int nw = i + ( 1 << ( pos2[ t ] ) ) ;
				if ( dp[ nw ][ pos2[ t ] ] < dp[ i ][ pos1[ j ] ] + a[ pos2[ t ] ] + c[ pos1[ j ] ][ pos2[ t ] ] ) {
					dp[ nw ][ pos2[ t ] ] = dp[ i ][ pos1[ j ] ] + a[ pos2[ t ] ] + c[ pos1[ j ] ][ pos2[ t ] ] ;
				}
			}
		}
	}
	printf ( "%I64d\n" , ans ) ;
}
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#include<iomanip>
using namespace std ;


int n , m , q ;
int dist[ 67 ][ 67 ][ 67 ] ;
long long dp[ 67 ][ 67 ][ 1007 ] ;

void input ( ) {
	scanf ( "%d%d%d" , &n , &m , &q ) ;
	int i , j , t , z ;
	for ( i = 1 ; i <= m ; i ++ ) {
		for ( j = 1 ; j <= n ; j ++ ) {
			for ( t = 1 ; t <= n ; t ++ ) {
				scanf ( "%d" , &dist[ i ][ j ][ t ] ) ;
			}
		}
		for ( j = 1 ; j <= n ; j ++ ) {
			for ( t = 1 ; t <= n ; t ++ ) {
				for ( z = 1 ; z <= n ; z ++ ) {
					if ( dist[ i ][ t ][ z ] > dist[ i ][ t ][ j ] + dist[ i ][ j ][ z ] ) {
						dist[ i ][ t ][ z ] = dist[ i ][ t ][ j ] + dist[ i ][ j ][ z ] ;
					}
				}
			}
		}
	}
	for ( i = 1 ; i <= m ; i ++ ) {
		for ( j = 1 ; j <= n ; j ++ ) {
			for ( t = 1 ; t <= n ; t ++ ) {
				if ( i == 1 ) {
					dp[ 0 ][ j ][ t ] = dist[ i ][ j ][ t ] ;
				}
				else {
					dp[ 0 ][ j ][ t ] = min ( dp[ 0 ][ j ][ t ] , 1LL * dist[ i ][ j ][ t ] ) ;
				}			
			}
		}
	}
}

void solve ( ) {
	int i , j , t , z ;
	for ( t = 1 ; t <= n ; t ++ ) {
		for ( i = 1 ; i <= n ; i ++ ) {
			for ( j = 1 ; j <= n ; j ++ ) {
				dp[ t ][ i ][ j ] = -1 ;
			}
		}
		for ( z	= 1 ; z <= n ; z ++ ) {
			for ( i = 1 ; i <= n ; i ++ ) {
				for ( j = 1 ; j <= n ; j ++ ) {
					//if ( z == i || z == j || i == j ) { continue ; }
					if ( dp[ t ][ i ][ j ] == -1 || dp[ t ][ i ][ j ] > dp[ t - 1 ][ i ][ z ] + dp[ 0 ][ z ][ j ] ) {
						dp[ t ][ i ][ j ] = dp[ t - 1 ][ i ][ z ] + dp[ 0 ][ z ][ j ] ;
					}
				}
			}
		}
	}
	for ( t = 1 ; t <= n ; t ++ ) {
		for ( i = 1 ; i <= n ; i ++ ) {
			for ( j = 1 ; j <= n ; j ++ ) {
				if ( dp[ t ][ i ][ j ] > dp[ t - 1 ][ i ][ j ] ) {
					dp[ t ][ i ][ j ] = dp[ t - 1 ][ i ][ j ] ;
				}
			}
		}
	}
	int w , x , y ;
	while ( q != 0 ) {
		q -- ;
		scanf ( "%d%d%d" , &x , &y , &w ) ;
		if ( w > n ) { w = n ; }
		printf ( "%I64d\n" , dp[ w ][ x ][ y ] ) ;
	}
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
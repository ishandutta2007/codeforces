#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std ;

#define MAXN 507
int n ;
int a[ MAXN ] ;

vector < int > v[ MAXN ][ MAXN ] ;

bool vis[ MAXN ][ MAXN ] ;

bool g[ MAXN ][ MAXN ][ 10 ] ;

void calc ( int id ) {
	int i , j , t , z ;
	for ( i = 0 ; i <= 300 ; i ++ ) {
		for ( j = 0 ; j <= 300 ; j ++ ) {
			for ( t = 0 ; t <= 8 ; t ++ ) {
				g[ i ][ j ][ t ] = false ;
			}
		}
	}
	for ( i = 0 ; i <= 300 ; i ++ ) {
		for ( j = 0 ; j <= 300 ; j ++ ) {
			int sz = v[ i ][ j ].size ( ) ;
			for ( t = 0 ; t < sz ; t ++ ) {
				int x , y ;
				x = i ;
				y = j ;
				int br = a[ id ] ;
				while ( br > 0 ) {
					br -- ;
					vis[ x ][ y ] = true ;
					if ( v[ i ][ j ][ t ] == 1 ) {
						y ++ ;
					}
					else if ( v[ i ][ j ][ t ] == 2 ) {
						x ++ ;
						y ++ ;
					}
					else if ( v[ i ][ j ][ t ] == 3 ) {
						x ++ ;
					}
					else if ( v[ i ][ j ][ t ] == 4 ) {
						x ++ ;
						y -- ;
					}
					else if ( v[ i ][ j ][ t ] == 5 ) {
						y -- ;
					}
					else if ( v[ i ][ j ][ t ] == 6 ) {
						x -- ;
						y -- ;
					}
					else if ( v[ i ][ j ][ t ] == 7 ) {
						x -- ;
					}
					else if ( v[ i ][ j ][ t ] == 8 ) {
						x -- ;
						y ++ ;
					}
					vis[ x ][ y ] = true ;
				}
				int lf = v[ i ][ j ][ t ] - 1 ;
				if ( lf == 0 ) { lf = 8 ; }
				int rg = v[ i ][ j ][ t ] + 1 ;
				if ( rg == 9 ) { rg = 1 ; }
				g[ x ][ y ][ lf ] = g[ x ][ y ][ rg ] = true ;
			}
		}
	}
	for ( i = 0 ; i <= 300 ; i ++ ) {
		for ( j = 0 ; j <= 300 ; j ++ ) {
			v[ i ][ j ].clear ( ) ;
			for ( t = 1 ; t <= 8 ; t ++ ) {
				if ( g[ i ][ j ][ t ] == true ) {
					v[ i ][ j ].push_back ( t ) ;
				}
			}
		}
	}
}

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
	a[ 1 ] -- ;
}

void solve ( ) {
	v[ 150 ][ 150 ].push_back ( 1 ) ;
	vis[ 150 ][ 150 ] = true ;
	int i , j ;	
	for ( i = 1 ; i <= n ; i ++ ) {
		calc ( i ) ;
	}

	int br = 0 ;
	for ( i = 0 ; i <= 300 ; i ++ ) {
		for ( j = 0 ; j <= 300 ; j ++ ) {
			if ( vis[ i ][ j ] == true ) {
				br ++ ;
			}
		}
	}
	printf ( "%d\n" , br ) ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
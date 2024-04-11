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
using namespace std ;

int n , m ;
vector < int > v[ 3007 ] ;
long long used[ 3007 ] ;

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
	scanf ( "%d%d" , &n , &m ) ;
	int i ;
	int x , y ;
	for ( i = 0 ; i < m ; i ++ ) {
		scanf ( "%d%d" , &x , &y ) ;
		v[ x ].push_back ( y ) ;
    }
}
 
void solve ( )  {
	long long ans = 0 ;
	int i , j , t ;
	int sz ;
	int u ;
	int h ;
	for ( i = 1 ; i <= n ; i ++ ) {
		sz = v[ i ].size ( ) ;
		for ( j = 0 ; j < sz ; j ++ ) {
			u = v[ v[ i ][ j ] ].size ( ) ;
			for ( t = 0 ; t < u ; t ++ ) {
				int h = v[ v[ i ][ j ] ][ t ] ;
				used[ h ] ++ ;
            }
        }
		for ( j = 1 ; j <= n ; j ++ ) {
			//printf ( "i = %d , used[ %d ] = %d\n" , i , j , used[ j ] ) ;
			if ( i == j ) { used[ j ] = 0 ; continue ; }
			ans += ( used[ j ] * ( used[ j ] - 1 ) ) / 2 ;
			used[ j ] = 0 ;
        }
    }
	printf ( "%I64d\n" , ans ) ;
}
#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
using namespace std ;

#define MAXN 100107

int n , m ;
int a[ MAXN ] ;
int f[ MAXN ][ 35 ] ;
int br[ MAXN ][ 35 ] ;
int e[ 37 ] ;
int le[ MAXN ] ;
int ri[ MAXN ] ;
int qu[ MAXN ] ;

void input ( ) ;
void solve ( ) ;


int main ( )  {
    //ios::sync_with_stdio ( false ) ;
    //cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%d%d" , &n , &m ) ;
	int i ;
	int j ;
	int l , r , q ;
	for ( i = 0 ; i < m ; i ++ ) {
		scanf ( "%d%d%d" , &l , &r , &q ) ;
		le[ i ] = l ;
		ri[ i ] = r ;
		qu[ i ] = q ;
		for ( j = 0 ; j <= 30 ; j ++ ) {
			int u = ((1<<j)) ; 
			if ( ((q&u)) != 0 ) {
				f[ l ][ j ] ++ ;
				f[ r + 1 ][ j ] -- ;
            }
        }
    }
}

void solve ( )  {
	int i , j ;
	int u ;
	for ( i = 1 ; i <= n ; i ++ ) {
		a[ i ] = 0 ; 
		for ( j = 0 ; j <= 30 ; j ++ ) {
			e[ j ] += f[ i ][ j ] ; 
        }
		for ( j = 0 ; j <= 30 ; j ++ ) {
			if ( e[ j ] != 0 ) {
				u = ((1<<j)) ;
				a[ i ] += u ; 
            }
        }
		//printf ( "%d\n" , a[ i ] ) ; 
    }
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = 0 ; j <= 30 ; j ++ ) {
			u = ((1<<j)) ;
			if ( ((a[ i ]&u)) != 0 ) br[ i ][ j ] = br[ i - 1 ][ j ] + 1 ; 
			else br[ i ][ j ] = br[ i - 1 ][ j ] ; 
        }
    }
	int ret = 0 ; 
	for ( i = 0 ; i < m ; i ++ ) {
		ret = 0 ;
		for ( j = 0 ; j <= 30 ; j ++ ) {
			u = ((1<<j)) ;
			if ( br[ ri[ i ] ][ j ] - br[ le[ i ] - 1 ][ j ] == ri[ i ] - le[ i ] + 1 ) {
				ret |= u ;
			}
        }
		if ( ret != qu[ i ] ) break ;
    }
	if ( i != m ) printf ( "NO\n" ) ;
	else {
		printf ( "YES\n" ) ;
		for ( i = 1 ; i <= n ; i ++ ) {
			printf ( "%d" , a[ i ] ) ;
			if ( i == n ) printf ( "\n" ) ;
			else printf ( " " ) ;
        }
    }
}
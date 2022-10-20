#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
using namespace std ;

#define MAXN 57
#define inf 1000000007

int q ;
int dp[ MAXN ][ MAXN ][ MAXN ] ;

void input ( ) {
	cin >> q ;
}

void solve ( ) {
	int i , j , t , z , p ;
    for ( i = 0 ; i <= 50 ; i ++ ) {
    	for ( j = 0 ; j <= 50 ; j ++ ) {
        	for ( t = 1 ; t <= 50 ; t ++ ) {
            	dp[ i ][ j ][ t ] = inf ;
            }
        }
    }
    for ( t = 1 ; t <= 50 ; t ++ ) {
    	for ( i = 1 ; i <= t ; i ++ ) {
        	if ( ( t % i ) == 0 ) {
            	dp[ i ][ ( t / i ) ][ t ] = 0 ;
            }
        }
        for ( i = 1 ; i <= 30 ; i ++ ) {
        	for ( j = 1 ; j <= 30 ; j ++ ) {
            	if ( ( i * j ) <= t ) { continue ; }
                for ( z = 1 ; z < i ; z ++ ) {
               		for ( p = 0 ; p <= t ; p ++ ) {
	                    if ( dp[ i ][ j ][ t ] > dp[ z ][ j ][ p ] + dp[ ( i - z ) ][ j ][ ( t - p ) ] + j * j ) { dp[ i ][ j ][ t ] = dp[ z ][ j ][ p ] + dp[ ( i - z ) ][ j ][ ( t - p ) ] + j * j ; }
					}                        
                }
                for ( z = 1 ; z < j ; z ++ ) {
               		for ( p = 0 ; p <= t ; p ++ ) {
	                    if ( dp[ i ][ j ][ t ] > dp[ i ][ z ][ p ] + dp[ i ][ ( j - z ) ][ ( t - p ) ] + i * i ) { dp[ i ][ j ][ t ] = dp[ i ][ z ][ p ] + dp[ i ][ ( j - z ) ][ ( t - p ) ] + i * i ; }
					}                 
                }
            }
        }
    }
    while ( q != 0 ) {
    	q -- ;
    	cin >> i >> j >> t ;
        cout << dp[ i ][ j ][ t ] << "\n" ;
    }
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
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

#define MAXN 1007

int n , m ;
int a[ MAXN ][ MAXN ] ;
int b[ MAXN ][ MAXN ] ;

bool used[ 2 * MAXN * MAXN ] ;

bool f ( int val ) {
	int i , j , t ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	for ( j = 1 ; j <= m ; j ++ ) {
        	if ( a[ i ][ j ] >= val ) { b[ i ][ j ] = 1 ; }
            else { b[ i ][ j ] = 0 ; }
        }
    }
    for ( i = 0 ; i <= m * ( m + 1 ) ; i ++ ) {
    	used[ i ] = false ;
    }
    vector < int > v ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	v.clear ( ) ;
    	for ( j = 1 ; j <= m ; j ++ ) {
        	if ( b[ i ][ j ] == true ) { v.push_back ( j ) ; }
        }
        int sz = v.size ( ) ;
        for ( j = 0 ; j < sz ; j ++ ) {
        	for ( t = j + 1 ; t < sz ; t ++ ) {
            	int x = m * ( v[ j ] - 1 ) + ( v[ t ] - 1 ) ;
                if ( used[ x ] == true ) { return true ; }
                used[ x ] = true ;
            }
        }
    }
    return false ;
}

void input ( ) {
	scanf ( "%d%d" , &n , &m ) ;
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	for ( j = 1 ; j <= m ; j ++ ) {
        	scanf ( "%d" , &a[ i ][ j ] ) ;
        }
    }
}

void solve ( ) {
	int l , r , mid ;
    l = 0 ;
    r = 1000000007 ;
    while ( r - l > 3 ) {
    	mid = ( l + r ) / 2 ;
    	if ( f ( mid ) == true ) { l = mid ; }
        else { r = mid ; }
    }
    while ( f ( r ) == false ) { r -- ; }
    printf ( "%d\n" , r ) ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
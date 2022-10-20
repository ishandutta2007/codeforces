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

#define MAXN 100007

int n , m ;
int a[ MAXN ] ;
int br[ MAXN ] ;
int cur[ MAXN ] ;
bool u[ MAXN ] ;

bool f ( int x ) {
	stack < int > s ;
    int i ;
    for ( i = 1 ; i <= m ; i ++ ) { cur[ i ] = 0 ; u[ i ] = false ; }
    for ( i = x ; i >= 1 ; i -- ) {
    	if ( a[ i ] != 0 && u[ a[ i ] ] == false ) {
        	s.push ( a[ i ] ) ;
            u[ a[ i ] ] = true ;
        }
        else {
        	if ( s.size ( ) != 0 ) {
            	int g = s.top ( ) ;
                cur[ g ] ++ ;
                if ( cur[ g ] >= br[ g ] ) { s.pop ( ) ; }
            }
        }
    }
    for ( i = 1 ; i <= m ; i ++ ) {
    	if ( u[ i ] == false ) { return false ; }
    }
    return ( s.size ( ) == 0 ) ;
}


void input ( ) {
	scanf ( "%d%d" , &n , &m ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d" , &a[ i ] ) ;
    }
    for ( i = 1 ; i <= m ; i ++ ) {
    	scanf ( "%d" , &br[ i ] ) ;
    }
}

void solve ( ) {
	int l , r ;
    int mid ;
    l = 1 ;
    r = n ;
    if ( f ( r ) == false ) {
    	printf ( "-1\n" ) ;
        return ;
    }
    while ( r - l > 3 ) {
    	mid = ( l + r ) / 2 ;
        if ( f ( mid ) == true ) { r = mid ; }
        else { l = mid ; }
    }
    while ( f ( l ) == false ) { l ++ ; }
    printf ( "%d\n" , l ) ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
using namespace std ;

#define MAXN 200007

int n , m ; 
int a[ MAXN ] ;


void input ( ) {
	scanf ( "%d%d" , &n , &m ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d" , &a[ i ] ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
	int l , r , mid ;
	int x ;    
    while ( m != 0 ) {
    	m -- ;
    	scanf ( "%d" , &x ) ;
        if ( x < a[ 1 ] ) { printf ( "0\n" ) ; continue ; }
        if ( x >= a[ n ] ) { printf ( "%d\n" , n ) ; continue ; }
        l = 1 ;
        r = n ;
        while ( r - l > 3 ) {
        	mid = ( l + r ) / 2 ;
            if ( a[ mid ] <= x ) { l = mid ; }
            else { r = mid ; }
        }
        while ( a[ r ] > x ) { r -- ; }
        printf ( "%d\n" , r ) ;
    }
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
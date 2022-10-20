#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
using namespace std ;

#define MAXN 5007

int n , t ;
pair < double , int > a[ MAXN ] ;

double dp[ MAXN ][ MAXN ] ;

void input ( ) {
	scanf ( "%d%d" , &n , &t ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%lf%d" , &a[ i ].first , &a[ i ].second ) ;
        a[ i ].first /= 100 ;
    }
}

void solve ( ) {
	int i , j ;
    double cur ;
    dp[ 0 ][ 0 ] = 1.00000 ;
    cur = dp[ 0 ][ 0 ] ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	double aux = 1.00000000 ;
        for ( j = 1 ; j <= a[ i ].second - 1 ; j ++ ) { aux *= ( 1 - a[ i ].first ) ; }
        cur = dp[ i - 1 ][ 0 ] ;
    	for ( j = 1 ; j <= t ; j ++ ) {
        	if ( a[ i ].second != 1 ) { dp[ i ][ j ] = cur * a[ i ].first ; }
            if ( j >= a[ i ].second ) { dp[ i ][ j ] += aux * dp[ i - 1 ][ j - a[ i ].second ] ; }
        	if ( j < a[ i ].second - 1 ) {
            	cur *= ( 1 - a[ i ].first ) ;
                cur += dp[ i - 1 ][ j ] ;
            }
            else {
                cur *= ( 1 - a[ i ].first ) ;
            	cur -= aux * dp[ i - 1 ][ j - a[ i ].second + 1 ] ;                  
                cur += dp[ i - 1 ][ j ] ;
            }
        }
    }
    double ans = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	for ( j = 1 ; j <= t ; j ++ ) {
        	ans += dp[ i ][ j ] ;
        }
    }
    printf ( "%.12lf\n" , ans ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
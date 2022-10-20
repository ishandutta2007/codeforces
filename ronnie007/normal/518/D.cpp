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

int n , t ;
double p ;
double dp[ 2 ][ 2007 ] ;

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
	cin >> n >> p >> t ;
}
 
void solve ( )  {
	int i , j ;
	int prev = 0 ;
	int cur = 1 ;
	double ans = 0.00 ;
	dp[ prev ][ 0 ] = 1 ;
	double sm = 0 ; 
	for ( i = 1 ; i <= t ; i ++ ) {
		sm = 0.00 ;
		for ( j = 0 ; j < n ; j ++ ) {
			dp[ cur ][ j ] = dp[ prev ][ j ] * ( 1 - p ) ;
			if ( j != 0 ) { dp[ cur ][ j ] += dp[ prev ][ j - 1 ] * p ; }
			sm += dp[ cur ][ j ] ;
			//printf ( "dp[ %d ][ %d ] = %lf\n" , i , j , dp[ cur ][ j ] ) ;
        }
		dp[ cur ][ n ] = ( 1 - sm ) ;
		cur ^= 1 ;
		prev ^= 1 ;
    }
	for ( i = 0 ; i <= n ; i ++ ) {
		ans += i * dp[ prev ][ i ] ; 
    }
	printf ( "%.12lf\n" , ans ) ;
}
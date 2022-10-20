#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<string.h>
#include<set>
using namespace std;


long long n , m , k , p ;
long long a[ 1007 ][ 1007 ] ;

priority_queue < int > q1 , q2 ;

long long pr1[ 1000007 ] ;
long long pr2[ 1000007 ] ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    //freopen ( "input.txt" , "r" , stdin ) ;
    //freopen ( "output.txt" , "w" , stdout ) ;
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
    input ( ) ;
	solve ( ) ;
    return 0 ;
}


void input ( ) {
	scanf ( "%I64d%I64d%I64d%I64d" , &n , &m , &k , &p ) ;
	int i , j ;
	int u = 0 ;
	for ( i = 0 ; i < n ; i ++ ) {
		u = 0 ;
		for ( j = 0 ; j < m ; j ++ ) {
			scanf ( "%I64d" , &a[ i ][ j ] ) ;
			u += a[ i ][ j ] ;
		}
		q1.push ( u ) ;
	}

	for ( i = 0 ; i < m ; i ++ ) {
		u = 0 ;
		for ( j = 0 ; j < n ; j ++ ) {
			u += a[ j ][ i ] ;
		}
		q2.push ( u ) ;
	}

}


void solve ( )  {
	int i ;

	int u ;
	for ( i = 0 ; i < k ; i ++ ) {
		u = q1.top ( ) ;
		q1.pop ( ) ;
		pr1[ i + 1 ] = pr1[ i ] + u ;
		q1.push ( u - (m * p) ) ;


		u = q2.top ( ) ;
		q2.pop ( ) ;
		pr2[ i + 1 ] = pr2[ i ] + u ;
		q2.push ( u - (n * p) ) ;
	}
	long long ans = 0 ;
	ans = pr1[ k ] ;
	for ( i = 0 ; i <= k ; i ++ ) {
		ans = max ( ans , pr1[ i ] + pr2[ k - i ] - p * ( i * ( k - i ) ) ) ;
	}
	printf ( "%I64d\n" , ans ) ;
}
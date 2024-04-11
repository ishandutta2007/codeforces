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

#define eps 0.0000001
#define LIMIT 10000
int n , q ;


double sr ;
double dp[ LIMIT + 7 ][ 1007 ] ;
bool f ( long long u ) {
	return ( dp[ u ][ n ] > sr ) ;
}

void input ( ) {
	cin >> n >> q ;
	dp[ 1 ][ 1 ] = 1.0000000 ;
	int i , j ;
	for ( i = 1 ; i <= LIMIT ; i ++ ) {			
		for ( j = 1 ; j <= n ; j ++ ) {
			if ( j != n ) {
				double p = ( n - j ) ;
				p /= n ;
				dp[ i + 1 ][ j + 1 ] += p * dp[ i ][ j ] ;
			}
			double p = j ;
			p /= n ;
			dp[ i + 1 ][ j ] += p * dp[ i ][ j ] ;
		}
	}
}

void solve ( ) {
	int x ;
	while ( q != 0 ) {
		q -- ;
		cin >> x ;
		sr = x ;
		sr -= eps ;
		sr /= 2000.0000 ;
		long long l , r , mid ;
		l = n ;
		r = LIMIT ;
		while ( r - l > 3 ) {
			mid = ( l + r ) / 2 ;
			if ( f ( mid ) == true ) { r = mid ; }
			else { l = mid ; }
		}
		while ( f ( l ) == false ) { l ++ ; }
		cout << l << "\n" ;
	}
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
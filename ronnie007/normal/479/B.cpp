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


int n , k ;
int a[ 107 ] ;
vector < pair < int , int > > v ;

void input ( ) ;
void solve ( ) ;


int main ( )  {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%d%d" , &n , &k ) ;
	int i ;
	for ( i = 0 ; i < n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( )  {
	int i , j ;
	int mx ;
	int mn ;
	int p , q ; 
	for ( j = 0 ; j < k ; j ++ ) {
		mx = a[ 0 ] ;
		mn = a[ 0 ] ; 
		p = 0 ;
		q = 0 ;
		for ( i = 1 ; i < n ; i ++ ) {
			if ( mx < a[ i ] ) { mx = a[ i ] ; p = i ; } 
			if ( mn > a[ i ] ) { mn = a[ i ] ; q = i ; }
        }
		if ( mx == mn ) break ;
		a[ p ] -- ;
		a[ q ] ++ ;
		v.push_back ( make_pair ( p , q ) ) ;
    }
	sort ( a , a + n ) ;
	int sz = v.size ( ) ;
	printf ( "%d %d\n" , a[ n - 1 ] - a[ 0 ] , sz ) ;
	for ( i = 0 ; i < sz ; i ++ ) {
		printf ( "%d %d\n" , v[ i ].first + 1 , v[ i ].second + 1 ) ;
    }
}
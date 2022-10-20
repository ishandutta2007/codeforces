#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std ;

#define MAXN 200007

int n , t , k ;
int a[ MAXN ] ;

vector < pair < int , int > > v ;

int fst[ MAXN ] ;

void input ( ) {
	scanf ( "%d%d%d" , &n , &t , &k ) ;
	int i ;
	for ( i = 1 ; i <= t ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
}

void solve ( ) {
	a[ 0 ] = 1 ;
	int i ;
	int tot = 0 ;
	for ( i = 1 ; i <= t ; i ++ ) {
		tot += max ( 0 , a[ i - 1 ] - a[ i ] ) ;
	}
	tot += a[ t ] ;
	if ( tot > k ) { printf ( "-1\n" ) ; return ; }
	int add = ( k - tot ) ;
	//printf ( "%d %d\n" , tot , add ) ;
	int curid = 2 ;
	fst[ 0 ] = 1 ;
	for ( i = 1 ; i <= t ; i ++ ) {
		fst[ i ] = curid ;
		if ( add >= ( a[ i - 1 ] - 1 ) - ( max ( 0 , a[ i - 1 ] - a[ i ] ) ) ) {
			add -= ( a[ i - 1 ] - 1 ) - ( max ( 0 , a[ i - 1 ] - a[ i ] ) ) ;
			int lft = a[ i ] ;
			while ( 1 ) {
				lft -- ;
				v.push_back ( make_pair ( fst[ i - 1 ] , curid ) ) ;
				curid ++ ;
				if ( lft <= 0 ) { break ; }
			}
		}
		else {
			int en = fst[ i ] - add - ( max ( 0 , a[ i - 1 ] - a[ i ] ) ) ;
			add = 0 ;
			int pos = fst[ i - 1 ] ;
			int lft = a[ i ] ;
			while ( 1 ) {
				lft -- ;
				v.push_back ( make_pair ( pos , curid ) ) ;
				curid ++ ;
				pos ++ ;
				if ( pos == en ) { pos -- ; }
				if ( lft <= 0 ) { break ; }
			}
		}
	}
	if ( add > 0 ) { printf ( "-1\n" ) ; return ; }
	printf ( "%d\n" , n ) ;
	for ( i = 0 ; i < ( n - 1 ) ; i ++ ) {
		printf ( "%d %d\n" , v[ i ].first , v[ i ].second ) ;
	}
}

int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
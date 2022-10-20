#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

int n ;
pair < int , int > a[ 5007 ] ; 

void input ( ) ;
void solve ( ) ;


int main ( ) {
    //ios::sync_with_stdio ( false ) ;
    //cin.tie ( NULL ) ; 
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 0 ; i < n ; i ++ ) {
		scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
    }
	sort ( a , a + n ) ;
}

void solve ( )  {
	int i ;
	int mn = 0 ;
	int cur = a[ 0 ].first ;
	if ( cur > a[ 0 ].second ) cur = a[ 0 ].second ;
	for ( i = 1 ; i < n ; i ++ ) {
		if ( a[ i ].second >= cur ) cur = a[ i ].second ;
		else cur = a[ i ].first ;
    }
	printf ( "%d\n" , cur ) ;
}
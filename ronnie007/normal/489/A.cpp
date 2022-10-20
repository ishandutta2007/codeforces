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
int a[ 3007 ] ;

vector < pair < int , int > > v ;

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
		scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( )  {
	int i , j ;
	int mn = -1 ;
	int ind ;
	for ( i = 0 ; i < n ; i ++ ) {
		mn = 1337 ;
		ind = -1 ;
		for ( j = i ; j < n ; j ++ ) {
			if ( ind == -1 || mn > a[ j ] ) { mn = a[ j ] ; ind = j ; }
        }
		v.push_back ( make_pair ( i , ind ) ) ;
		swap ( a[ i ] , a[ ind ] ) ;
    }
	printf ( "%d\n" , n ) ;
	for ( i = 0 ; i < n ; i ++ ) {
		printf ( "%d %d\n" , v[ i ].first , v[ i ].second ) ;
    }
}
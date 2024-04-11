#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
using namespace std ;

int n , k , r ;
int a[ 307 ] ;
int u[ 1007 ] ; 

void input ( ) ;
void solve ( ) ;


int main ( )  {
    ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}

void input ( ) {
	scanf ( "%d%d%d" , &n , &k , &r ) ;
	int i ;
	for ( i = 0 ; i < n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
		a[ i ] += 400 ;
	}
}

void solve ( ) {
	int i , j ;
	int br = 0 ; 
	int ans = 0 ; 
	for ( i = 0 ; i < n ; i ++ ) {
		br = 0 ;
		for ( j = 0 ; j <= a[ i ] ; j ++ ) {
			if ( u[ j ] == 1 && j + k >= a[ i ] ) { br ++ ; } 
        }
		if ( br >= r ) { continue ; } 
		for ( j = a[ i ] - 1 ; j >= 0 ; j -- ) {
			if ( br >= r ) { break ; } 
			if ( u[ j ] == 0 && j + k >= a[ i ] ) { u[ j ] = 1 ; br ++ ; } 
        }
		if ( br < r ) { printf ( "-1\n" ) ; return ; } 
    }
	for ( i = 0 ; i <= 1000 ; i ++ ) {
		ans += u[ i ] ;
    }
	printf ( "%d\n" , ans ) ;
}
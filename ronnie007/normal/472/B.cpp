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
int f[ 2007 ] ; 
int mx = 0 ; 



void input ( ) ;
void solve ( ) ;




int main ( )  {
    //ios::sync_with_stdio ( false ) ;
    //cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%d%d" , &n , &k ) ;
	int i ;
	int x ;
	for ( i = 0 ; i < n ; i ++ ) {
		scanf ( "%d" , &x ) ;
		f[ x ] ++ ; 
		if ( mx < x ) mx = x ; 
	}
}

void solve ( )  {
	int i ;
	int br = n , t ;
	int ans = 0 ; 
	for ( i = 2 ; i <= mx ; i ++ ) {
		t = br / k ;
		if ( br % k != 0 ) t ++ ;
		ans += t * 2 - 1  ;
		br -= f[ i ] ; 
	}
	ans += mx - 1 ;
	printf ( "%d\n" , ans ) ;
}
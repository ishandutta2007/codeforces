#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
#include<set>
#include<stack>
using namespace std ;

int n , m ;

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
	scanf ( "%d%d" , &n , &m ) ;
}

void solve ( ) {
	int cur = 0 ;
	int ans = 1 ;
	int sr ;
	if ( m > 1 ) {
		sr = m - 1 ; 
		if ( cur < sr ) { cur = sr ; ans = m - 1 ; }
    }
	if ( m < n ) {
		sr = n - m ;
		if ( cur < sr ) { cur = sr ; ans = m + 1 ; }
    }
	printf ( "%d\n" , ans ) ;
}
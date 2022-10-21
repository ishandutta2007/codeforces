#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<map>
using namespace std ;

int k , a , b ;

void input ( ) {
	scanf ( "%d%d%d" , &k , &a , &b ) ;
}

void solve ( ) {
	int mx = ( a / k ) + ( b / k ) ;
	int u1 , u2 ;
	int l1 , l2 ;
	u1 = ( a / k ) ;
	u2 = ( b / k ) ;
	l1 = ( a % k ) ;
	l2 = ( b % k ) ;
	if ( 1LL * u1 * ( k - 1 ) < l2 ) { printf ( "-1\n" ) ; return ; }
	if ( 1LL * u2 * ( k - 1 ) < l1 ) { printf ( "-1\n" ) ; return ; }
	printf ( "%d\n" , mx ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
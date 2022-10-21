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

#define MAXN 200007

#define inf 1000000007

int n ;
pair < int , int > a[ MAXN ] ;

int mnst = -inf ;
int mxst = inf ;

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
	}
}

void solve ( ) {
	int u = 0 ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( a[ i ].second == 1 ) {
			if ( mnst < 1900 - u ) { mnst = 1900 - u ; }
		}
		else {
			if ( mxst > 1899 - u ) { mxst = 1899 - u ; }
		}
		u += a[ i ].first ;
	}
	if ( mxst < mnst ) { printf ( "Impossible\n" ) ; return ; }
	if ( mxst == inf ) { printf ( "Infinity\n" ) ; return ; }
	printf ( "%d\n" , mxst + u ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
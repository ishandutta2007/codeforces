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

#define MAXN 100007

int n , m ;
int f[ MAXN ] ;
int ret[ MAXN ] ;
int pos[ MAXN ] ;
int br[ MAXN ] ;
bool fl = false ;

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
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &f[ i ] ) ;
		pos[ f[ i ] ] = i ;
		br[ f[ i ] ] ++ ;
	}
}

void solve ( ) {
	int i ;
	bool fl = false ;
	int x ;
	for ( i = 1 ; i <= m ; i ++ ) {
		scanf ( "%d" , &x ) ;
		if ( br[ x ] > 1 ) { fl = true ; }
		if ( br[ x ] == 0 ) { printf ( "Impossible\n" ) ; return ; }
		ret[ i ] = pos[ x ] ;
	}
	if ( fl == true ) { printf ( "Ambiguity\n" ) ; return ; }
	printf ( "Possible\n" ) ;
	for ( i = 1 ; i <= m ; i ++ ) {
		printf ( "%d" , ret[ i ] ) ;
		if ( i == m ) { printf ( "\n" ) ; }
		else { printf ( " " ) ; }
	}
}
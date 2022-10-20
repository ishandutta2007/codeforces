#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

int n , m , k ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ; 
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%d%d%d" , &n , &m , &k ) ;
}

void solve ( )  {
	int i ;
	int sm = 0 ;
	for ( i = 1 ; i <= k ; i ++ ) {
		sm += i * n ;
    }
	if ( sm < m ) { printf ( "0\n" ) ; }
	else { printf ( "%d\n" , sm - m ) ; }
}
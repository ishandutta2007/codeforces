#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;


int a , b , c , d ;


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
	scanf ( "%d%d%d%d" , &a , &b , &c , &d ) ;
}

void solve ( )  {
	if ( a > b ) { printf ( "First\n" ) ; }
	else { printf ( "Second\n" ) ; }
}
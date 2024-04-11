#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#include<map>
#include<set>
using namespace std ;

int x , y , z ;


void input ( ) {
	scanf ( "%d%d%d" , &x , &y , &z ) ;
}

void solve ( ) {
	int mn = x ;
	if ( mn > ( y / 2 ) ) { mn = ( y / 2 ) ; }
	if ( mn > ( z / 4 ) ) { mn = ( z / 4 ) ; }
	printf ( "%d\n" , ( mn * 7 ) ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
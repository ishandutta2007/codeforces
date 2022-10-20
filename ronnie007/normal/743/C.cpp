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

int n ;

void input ( ) {
	scanf ( "%d" , &n ) ;
}

void solve ( ) {
	if ( n == 1 ) { printf ( "-1\n" ) ; return ; }
	printf ( "%d %d %d\n" , n , n + 1 , ( n * ( n + 1 ) ) ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;


int n , a , b ;
int ans = 0 ; 


void input ( ) ;
void solve ( ) ;


int main ( ) {
    //	ios::sync_with_stdio ( false ) ;
    //	cin.tie ( NULL ) ; 
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%d" , &n ) ; 
}

void solve ( )  {
	int i ;
	for ( i = 0 ; i < n ; i ++ ) {
		scanf ( "%d%d" , &a , &b ) ;
		if ( a + 2 <= b ) ans ++ ; 
    }
	printf ( "%d\n" , ans ) ;
}
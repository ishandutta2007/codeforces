#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

int n ;
int ans = 0 ; 

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
	int i ;
	scanf ( "%d" , &n ) ;
	int a , b , c , d ; 
	for ( i = 0  ; i < n ; i ++ ) {
		scanf ( "%d%d%d%d" , &a , &b , &c , &d ) ;
		ans += ( c - a + 1 ) * ( d - b + 1 ) ;
    }
}

void solve ( )  {
	printf ( "%d\n" , ans ) ;
}
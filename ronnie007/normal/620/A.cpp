#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#include<map>
using namespace std ;

int x , y , z , t ;

void input ( ) {
	scanf ( "%d%d" , &x , &y ) ;
    scanf ( "%d%d" , &z , &t ) ;
}

void solve ( ) {
	int ans = max ( abs ( x - z ) , abs ( y - t ) ) ;
    printf ( "%d\n" , ans ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

int a , b , c ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ; 
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( ) {
	scanf ( "%d%d%d" , &a , &b , &c ) ;
}

void solve ( ) {
	int u = min ( a + b , c ) ;
	int ret1 = min ( a , c + b ) ;
	int ret2 = min ( b , c + a ) ;
	printf ( "%d\n" , ret1 + ret2 + u ) ;
}
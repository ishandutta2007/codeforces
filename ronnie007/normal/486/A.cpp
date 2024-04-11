#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

long long n ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    //ios::sync_with_stdio ( false ) ;
    //cin.tie ( NULL ) ; 
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%I64d" , &n ) ;
}

void solve ( )  {
	if ( n % 2 == 0 ) printf ( "%I64d\n" , n / 2 ) ;
	else printf ( "%I64d\n" , ( n / 2 - n ) ) ;
}
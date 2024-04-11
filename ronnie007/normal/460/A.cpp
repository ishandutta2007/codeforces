#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

int n , m ;

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
  	scanf ( "%d%d" , &n , &m ) ;
}

void solve ( )  {
  	int br = n ;
	int ind = 0 ;
  	while ( 1 ) {
        //	printf ( "%d %d\n" , ind , br ) ;
		if ( br == 0 ) break ;
    	br -- ;
		ind ++ ;
		if ( ind % m == 0 ) br ++ ;
  	}
	printf ( "%d\n" , ind ) ;
}
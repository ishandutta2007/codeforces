#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

#define MAXN 1000000

int n ;
int comp[ 1000007 ] ; 

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
	int i , j ;
	
	for ( i = 2 ; i <= MAXN ; i ++ ) {
		if ( comp[ i ] == 1 ) continue ;
		for ( j = 2 * i ; j <= MAXN ; j += i ) {
			comp[ j ] = 1 ; 
		}
	}
	scanf ( "%d" , &n ) ;
}

void solve ( )  {
	int i , j ;
	for ( i = 2 ; i <= n / 2 ; i ++ ) {
		j = n - i ;
		if ( comp[ i ] == 1 && comp[ j ] == 1 ) break ;
	}
	printf ( "%d %d\n" , i , j ) ;
}
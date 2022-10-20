#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
#include<set>
#include<stack>
using namespace std ;

int n ;
long long k ;

long long fib[ 57 ] ;

void input ( ) ;
void solve ( ) ;

int main ( )  {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%d%I64d" , &n , &k ) ;
}

void solve ( ) {
	int i ;
	fib[ 0 ] = fib[ 1 ] = 1 ;
	for ( i = 2 ; i <= n ; i ++ ) { fib[ i ] = fib[ i - 1 ] + fib[ i - 2 ] ; }
	int lft = n ;
	int u = 1 ;
	while ( lft != 0 ) {
		if ( k > fib[ lft - 1 ] ) { k -= fib[ lft - 1 ] ; printf ( "%d %d " , u + 1 , u ) ; u += 2 ; lft -= 2 ; }
		else {
			lft -- ; 
			printf ( "%d " , u ) ;
			u ++ ;
        }
    }
	printf ( "\n" ) ;
}
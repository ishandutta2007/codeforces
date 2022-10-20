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
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ; 
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( ) {
	scanf ( "%d" , &n ) ;
}

void solve ( ) {
	if ( n == 0 ) { printf ( "1\n" ) ; return ; }
	long long i , j ;
	j = n ;
	long long ans = 1 ;
	for ( i = 1 ; i < n ; i ++ ) {
		while ( i * i + j * j > n * n ) { j -- ; }
		ans ++ ;
		while ( ( i + 1 ) * ( i + 1 ) + ( j - 1 ) * ( j - 1 ) > n * n && j > 0 ) {
			j -- ;
			ans ++ ;
		}
	}
	printf ( "%I64d\n" , 4 * ans ) ;
}
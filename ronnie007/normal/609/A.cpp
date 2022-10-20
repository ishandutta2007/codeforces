#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
using namespace std ;

#define MAXN 107

int n , k ;
int a[ MAXN ] ;

void input ( ) {
	scanf ( "%d%d" , &n , &k ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d" , &a[ i ] ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
	int i ;
    int sm = 0 ;
    int br = 0 ;
    for ( i = n ; i >= 1 ; i -- ) {
    	sm += a[ i ] ;
        br ++ ;
        if ( sm >= k ) { break ; }
    }
    printf ( "%d\n" , br ) ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
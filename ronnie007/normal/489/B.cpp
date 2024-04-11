#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
using namespace std ;

int n , m ;
int a[ 107 ] ;
int b[ 107 ] ;


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
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 0 ; i < n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
    }
	sort ( a , a + n ) ;
	scanf ( "%d" , &m ) ;
	for ( i = 0 ; i < m ; i ++ ) {
		scanf ( "%d" , &b[ i ] ) ;
    }
	sort ( b , b + m ) ;
}

void solve ( )  {
	int i , j ;
	int ret = 0 ;
	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = 0 ; j < m ; j ++ ) {
			if ( b[ j ] != -1337 && abs ( a[ i ] - b[ j ] ) <= 1 ) {
				b[ j ] = -1337 ;
				ret ++ ;
				break ;
            }
			if ( b[ j ] > a[ i ] + 1 ) break ;
        }
    }
	printf ( "%d\n" , ret ) ;
}
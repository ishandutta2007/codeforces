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

#define MAXN 200007 
#define lim 2000000


int n ;
int a[ MAXN ] ;
int lst[ lim + 7 ] ;
int used[ lim + 7 ] ;


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
		used[ a[ i ] ] = 1 ; 
    }
	sort ( a , a + n ) ;
}

void solve ( )  {
	int i , j ;
	for ( i = 1 ; i <= lim ; i ++ ) {
		if ( used[ i ] == 1 ) lst[ i ] = i ;
		else lst[ i ] = lst[ i - 1 ] ;
    }
	int ans = -1 ;
	for ( i = 0 ; i < n ; i ++ ) {
		if ( i != 0 && a[ i ] == a[ i - 1 ] ) continue ;
		for ( j = 2 * a[ i ] ; j <= lim ; j += a[ i ] ) {
			int x = lst[ j - 1 ] ;
			if ( x % a[ i ] > ans ) ans = x % a[ i ] ;
        }
    }
	printf ( "%d\n" , ans ) ;
}
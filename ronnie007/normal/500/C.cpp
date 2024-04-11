/**
	WARNING: The code below will make you cry.
	A safety pig is provided below for your benefit.
                         _
 _._ _..._ .-',     _.._(`))
'-. `     '  /-._.-'    ',/
   )         \            '.
  / _    _    |             \
 |  a    a    /              |
 \   .-.                     ;  
  '-('' ).-'       ,'       ;
     '-;           |      .'
        \           \    /
        | 7  .__  _.-\   \
        | |  |  ``/  /`  /
       /,_|  |   /,_/   /
          /,_/      '`-'

**/

#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
using namespace std ;

int n , m ;
int w[ 507 ] ;
int used[ 507 ] ;
int a[ 1007 ] ;

void input ( ) ;
void solve ( ) ;


int main ( )  {
    ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}

void input ( ) {
	scanf ( "%d%d" , &n , &m ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &w[ i ] ) ;
    }
	for ( i = 0 ; i < m ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
	int ans = 0 ;
	int i , j ;
	for ( i = 0 ; i < m ; i ++ ) {
		for ( j = 0 ; j <= n ; j ++ ) { used[ j ] = 0 ; } 

		for ( j = i - 1 ; j >= 0 ; j -- ) {
			if ( a[ j ] == a[ i ] ) break ;
			used[ a[ j ] ] = 1 ; 
        }
		for ( j = 1 ; j <= n ; j ++ ) {
			if ( used[ j ] == 1 ) ans += w[ j ] ;
        }
    }
	printf ( "%d\n" , ans ) ;
}
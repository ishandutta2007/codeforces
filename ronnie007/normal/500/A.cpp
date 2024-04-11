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
using namespace std ;

int n , t ;
int a[ 50007 ] ;

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
	scanf ( "%d%d" , &n , &t ) ;
	int i ;
	for ( i = 1 ; i <= n - 1 ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( )  {
	int x ;
	x = 1 ;
	while ( x < t ) {
		x = x + a[ x ] ;
    }
	if ( x == t ) { printf ( "YES\n" ) ; }
	else { printf ( "NO\n" ) ; }
}
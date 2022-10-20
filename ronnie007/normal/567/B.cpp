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

#define MAXN 107 

int n ;
bool t[ MAXN ] ;
int x[ MAXN ] ;

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
	char c ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "\n%c %d" , &c , &x[ i ] ) ;
		if ( c == '+' ) { t[ i ] = true ; }
		else { t[ i ] = false ; }
    }
}

void solve ( ) {
	int st = 0 ;
	int br = 0 ;
	int i , j ; 
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( t[ i ] == false ) {
			for ( j = i - 1 ; j >= 1 ; j -- ) {
				if ( x[ i ] == x[ j ] ) { break ; }
            }
			if ( j == 0 ) { st ++ ; }
        }
    }
	br = st ;
	int mx = 0 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		mx = max ( mx , br ) ;
		if ( t[ i ] == false ) { br -- ; }
		else { br ++ ; }
		mx = max ( mx , br ) ;
    }
	printf ( "%d\n" , mx ) ;
}
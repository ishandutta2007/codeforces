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


int n , l ;
int x , y ;

int a[ 100007 ] ;

map < int , int > m ; 

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
	scanf ( "%d%d" , &n , &l ) ;
	scanf ( "%d%d" , &x , &y ) ;
	int i ;
	for ( i = 0 ; i < n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
		m[ a[ i ] ] = 1 ; 
    }
}

void solve ( )  {
	int i ;
	int u ;
	bool fl1 = false ;
	bool fl2 = false ;
	for ( i = 0 ; i < n ; i ++ ) {
		u = a[ i ] - x ; 
		if ( u >= 0 && m[ u ] == 1 ) fl1 = true ;
		u = a[ i ] - y ;
		if ( u >= 0 && m[ u ] == 1 ) fl2 = true ;
    }
	if ( fl1 == true && fl2 == true ) {
		printf ( "0\n" ) ;
		return ;
    }
	if ( fl1 == true ) {
		printf ( "1\n%d\n" , y ) ;
		return ;
    }
	if ( fl2 == true ) {
		printf ( "1\n%d\n" , x ) ;
		return ;
    }
	for ( i = 0 ; i < n ; i ++ ) {
		u = a[ i ] - x ;
		if ( u >= 0 ) {
			int need = u + y ;
			if ( m[ need ] == 1 ) {
				printf ( "1\n" ) ;
				printf ( "%d\n" , u ) ;
				return ;
            }
			need = u - y ;
			if ( m[ need ] == 1 ) {
				printf ( "1\n" ) ;
				printf ( "%d\n" , u ) ;
				return ;
            }
        }
		u = a[ i ] + x ;
		if ( u <= l ) {
			int need = u + y ;
			if ( m[ need ] == 1 ) {
				printf ( "1\n" ) ;
				printf ( "%d\n" , u ) ;
				return ;
            }
			need = u - y ;
			if ( m[ need ] == 1 ) {
				printf ( "1\n" ) ;
				printf ( "%d\n" , u ) ;
				return ;
            }
        }
    }

	for ( i = 0 ; i < n ; i ++ ) {
		u = a[ i ] - y ;
		if ( u >= 0 ) {
			int need = u + x ;
			if ( m[ need ] == 1 ) {
				printf ( "1\n" ) ;
				printf ( "%d\n" , u ) ;
				return ;
            }
			need = u - x ;
			if ( m[ need ] == 1 ) {
				printf ( "1\n" ) ;
				printf ( "%d\n" , u ) ;
				return ;
            }
        }
		u = a[ i ] + y ;
		if ( u <= l ) {
			int need = u + x ;
			if ( m[ need ] == 1 ) {
				printf ( "1\n" ) ;
				printf ( "%d\n" , u ) ;
				return ;
            }
			need = u - x ;
			if ( m[ need ] == 1 ) {
				printf ( "1\n" ) ;
				printf ( "%d\n" , u ) ;
				return ;
            }
        }
    }
	printf ( "2\n" ) ;
	printf ( "%d %d\n" , x , y ) ;
}
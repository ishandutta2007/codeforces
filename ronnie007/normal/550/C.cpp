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

int n ;
string a ;

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
	cin >> a ;
	n = a.size ( ) ;
}

void solve ( ) {
	int i , j , t ;
	for ( i = 0 ; i < n ; i ++ ) {
		int u = ( a[ i ] - '0' ) ;
		if ( u % 8 == 0 ) {
			printf ( "YES\n" ) ;
			printf ( "%d\n" , u ) ;
			return ;
		}
    }
	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = i + 1 ; j < n ; j ++ ) {
			int u = 10 * ( a[ i ] - '0' ) + ( a[ j ] - '0' ) ;
			if ( u % 8 == 0 ) {
				printf ( "YES\n" ) ;
				printf ( "%d\n" , u ) ;
				return ;
            }
        }
    }
	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = i + 1 ; j < n ; j ++ ) {
			for ( t = j + 1 ; t < n ; t ++ ) {
				int u = 100 * ( a[ i ] - '0' ) + 10 * ( a[ j ] - '0' ) + ( a[ t ] - '0' ) ; 
				if ( u % 8 == 0 ) {
					printf ( "YES\n" ) ;
					printf ( "%d\n" , u ) ;
					return ;
                }
            }
        }
    }
	printf ( "NO\n" ) ;
}
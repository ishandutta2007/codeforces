#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

int n ;
string a[ 17 ] ;

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
	n = 8 ;
	int i ;
	for ( i = 0 ; i < n ; i ++ ) {
		cin >> a[ i ] ; 
	}
}

void solve ( ) {
	int i , j , t ;
	int ans1 = 1000000 ;
	int ans2 = 1000000 ;
	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = 0 ; j < n ; j ++ ) {
			if ( a[ i ][ j ] == '.' ) { continue ; }
			if ( a[ i ][ j ] == 'W' ) {
				for ( t = i - 1 ; t >= 0 ; t -- ) {
					if ( a[ t ][ j ] != '.' ) { break ; }
				}
				if ( t == -1 ) { ans1 = min ( ans1 , i ) ; }
			}
			else {
				for ( t = i + 1 ; t < n ; t ++ ) {
					if ( a[ t ][ j ] != '.' ) { break ; }
				}
				if ( t == n ) { ans2 = min ( ans2 , n - i - 1 ) ; }				
			}
		}
	}
	if ( ans1 <= ans2 ) { printf ( "A\n" ) ; }
	else { printf ( "B\n" ) ; }
}
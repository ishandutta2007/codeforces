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
string a ;

int br[ 17 ] ;
int specbr[ 17 ][ 17 ] ;

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
	cin >> n ;
	cin >> a ;
}

void solve ( )  {
	int i , j , t ;
	int x ;
	int y ;
	for ( i = 0 ; i < n ; i ++ ) {
		x = ( a[ i ] - '0' ) ;
		for ( t = x ; t >= 2 ; t -- ) {
			y = t ;
			for ( j = 2 ; j <= 9 ; j ++ ) {
				specbr[ t ][ j ] = 0 ;
				while ( y % j == 0 ) {
					y /= j ;
					br[ j ] ++ ;
					specbr[ t ][ j ] ++ ;
				}
            }
        }
    }
	string ret ;
	ret.clear ( ) ;
	for ( i = 9 ; i >= 2 ; i -- ) {
		if ( br[ i ] == 0 ) { continue ; }
		x = br[ i ] ; 
		for ( j = i ; j >= 2 ; j -- ) {
			if ( br[ j ] == 0 ) { continue ; }
			for ( t = 2 ; t <= i ; t ++ ) {
				br[ j ] -= specbr[ t ][ j ] * x ;
            }
        }
		while ( x != 0 ) { 
			x -- ;
			ret += ( i + '0' ) ;
        }
    }
	cout << ret << "\n" ;
}
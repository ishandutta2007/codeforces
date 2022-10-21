#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#include<iomanip>
using namespace std ;

int n ;
string a[ 5 ] ;

int dx[ 8 ] = { -1 , -1 , 0 , 1 , 1 , 1 , 0 , -1 } ;
int dy[ 8 ] = { 0 , 1 , 1 , 1 , 0 , -1 , -1 , -1 } ;

void input ( ) {
	n = 4 ;
	int i ;
	for ( i = 0 ; i < n ; i ++ ) {
		cin >> a[ i ] ;
	}
}

void solve ( ) {
	int i , j , t , z ;
	for ( i = 0 ; i < 4 ; i ++ ) {
		for ( j = 0 ; j < 4 ; j ++ ) {
			int br1 , br2 , br3 ;
			for ( t = 0 ; t < 8 ; t ++ ) {
				br1 = br2 = br3 = 0 ;
				for ( z = 0 ; z < 3 ; z ++ ) {
					int nx = i + z * dx[ t ] ;
					int ny = j + z * dy[ t ] ;
					if ( nx < 0 || nx >= 4 ) { break ; }
					if ( ny < 0 || ny >= 4 ) { break ; }
					if ( a[ nx ][ ny ] == 'x' ) { br1 ++ ; }
					if ( a[ nx ][ ny ] == 'o' ) { br2 ++ ; }
					if ( a[ nx ][ ny ] == '.' ) { br3 ++ ; }
				}
				if ( z >= 3 ) {
					if ( br1 == 2 && br2 == 0 && br3 == 1 ) {
						cout << "YES\n" ;
						return ;
					}
				}
			}
		}
	}
	cout << "NO\n" ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
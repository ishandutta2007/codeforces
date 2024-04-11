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

#define MAXN 507

int n , m ;
string a[ MAXN ] ;

int dx[ 4 ] = { 1 , -1 , 0 , 0 } ;
int dy[ 4 ] = { 0 , 0 , 1 , -1 } ;

void input ( ) {
	cin >> n >> m ;
	int i ;
	for ( i = 0 ; i < n ; i ++ ) {
		cin >> a[ i ] ;
	}
}

void solve ( ) {
	int i , j , t ;
	int br = 0 ;
	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = 0 ; j < m ; j ++ ) {
			if ( a[ i ][ j ] == 'X' ) { continue ; }
			br = 0 ;
			for ( t = 0 ; t < 4 ; t ++ ) {
				int nx = i + dx[ t ] ;
				int ny = j + dy[ t ] ;
				if ( nx < 0 || nx >= n ) { continue ; }
				if ( ny < 0 || ny >= m ) { continue ; }
				if ( a[ nx ][ ny ] == 'X' ) { br ++ ; }
			}
			if ( br > 1 ) { cout << "NO\n" ; return ; }
		}
	}
	cout << "YES\n" ; 
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
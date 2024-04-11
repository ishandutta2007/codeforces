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

#define MAXN 400007

int n ;
string a ;

bool dp[ MAXN ] ;
int prv[ MAXN ] ;

bool g[ MAXN ] ;

void input ( ) {
	cin >> a ;
	n = a.size ( ) ;
}

void solve ( ) {
	dp[ 0 ] = true ;
	int i , j , t , z ;
	for ( i = 0 ; i < n ; i ++ ) {
		if ( dp[ i ] == false ) { continue ; }
		for ( j = 1 ; j <= 8 ; j ++ ) {
			for ( t = 1 ; t <= 3 ; t ++ ) {
				if ( i + j + t + 1 > n ) { continue ; }
				for ( z = 0 ; z < j ; z ++ ) {
					if ( a[ i + z ] == '.' ) { break ; }
				}
				if ( z < j ) { continue ; }
				if ( a[ i + j ] != '.' ) { continue ; }
				for ( z = 0 ; z < t ; z ++ ) {
					if ( a[ i + j + 1 + z ] == '.' ) { break ; }
				}
				if ( z < t ) { continue ; }
				if ( dp[ i + j + t + 1 ] == false ) {
					dp[ i + j + t + 1 ] = true ;
					prv[ i + j + t + 1 ] = i ;
				}
			}
		}
	}
	if ( dp[ n ] == false ) {
		cout << "NO\n" ;
		return ;
	}
	cout << "YES\n" ;
	vector < int > v ;
	int x = n ;
	int br = 0 ;
	g[ n ] = true ;
	while ( x != 0 ) {
		br ++ ;
		g[ prv[ x ] ] = true ;
		x = prv[ x ] ;
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		cout << a[ i - 1 ] ;
		if ( g[ i ] == true ) { cout << "\n" ; }
	}
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
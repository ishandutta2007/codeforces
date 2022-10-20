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
string a[ 107 ] ;
int g[ 107 ][ 107 ] ;
int br[ 107 ] ;
string ret ;


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
	int i ;
	for ( i = 0 ; i < n ; i ++ ) {
		cin >> a[ i ] ;
    }
}

void solve ( )  {
	int i , j , t ;
	int sz ;
	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = i - 1 ; j >= 0 ; j -- ) {
			sz = min ( a[ i ].size ( ) , a[ j ].size ( ) ) ;
			for ( t = 0 ; t < sz ; t ++ ) {
				if ( a[ i ][ t ] != a[ j ][ t ] ) { break ; } 
            }
			if ( t == sz && a[ i ].size ( ) < a[ j ].size ( ) ) { cout << "Impossible\n" ; return ; } 
			if ( t == sz ) { continue ; } 
			g[ a[ j ][ t ] - 'a' ][ a[ i ][ t ] - 'a' ] = 1 ;
        }
    }
	for ( i = 0 ; i < 26 ; i ++ ) {
		for ( j = i + 1 ; j < 26 ; j ++ ) {
			if ( g[ i ][ j ] == 1 && g[ j ][ i ] == 1 ) { break ; } 
        }
		if ( j != 26 ) { cout << "Impossible\n" ; return ; } 
		if ( g[ i ][ i ] == 1 ) { cout << "Impossible\n" ; return ; } 
    }
	for ( i = 0 ; i < 26 ; i ++ ) {
		br[ i ] = 0 ;
		for ( j = 0 ; j < 26 ; j ++ ) {
			br[ i ] += g[ j ][ i ] ;
        }
    }
	ret.clear ( ) ;
	int h = 0 ;
	while ( 1 ) {
		h ++ ;
		for ( i = 0 ; i < 26 ; i ++ ) { 
			if ( br[ i ] == 0 ) { break ; } 
        }
		if ( h >= 30 ) { cout << "Impossible\n" ; return ; }
		if ( i == 26 ) { break ; }
		ret += ( i + 'a' ) ;
		br[ i ] = -27 ;
		for ( j = 0 ; j < 26 ; j ++ ) {
			if ( g[ i ][ j ] == 1 ) { br[ j ] -- ; } 
        }
    }
	if ( ret.size ( ) != 26 ) { cout << "Impossible\n" ; return ; } 
	cout << ret << "\n" ;
}
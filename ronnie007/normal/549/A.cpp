#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

#define MAXN 57

int n , m ;
string a[ MAXN ] ;
int br[ MAXN ] ;

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
	cin >> n >> m ;
	int i ;
	for ( i = 0 ; i < n ; i ++ ) {
		cin >> a[ i ] ; 
    }
}

void solve ( )  {
	int i , j , t ;
	int ans = 0 ;
	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = 0 ; j < m ; j ++ ) {
			if ( i == n - 1 || j == m - 1 ) { continue ; }
			for ( t = 0 ; t <= 30 ; t ++ ) {
				br[ t ] = 0 ; 
			}
			br[ ( a[ i ][ j ] - 'a' ) ] ++ ;
			br[ ( a[ i + 1 ][ j ] - 'a' ) ] ++ ;
			br[ ( a[ i ][ j + 1 ] - 'a' ) ] ++ ;
			br[ ( a[ i + 1 ][ j + 1 ] - 'a' ) ] ++ ;
			if ( br[ ( 'f' - 'a' ) ] == 1 && br[ ( 'a' - 'a' ) ] == 1 && br[ ( 'c' - 'a' ) ] == 1 && br[ ( 'e' - 'a' ) ] == 1 ) { ans ++ ; }
        }
    }
	printf ( "%d\n" , ans ) ;
}
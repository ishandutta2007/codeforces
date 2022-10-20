#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;


int n , m ;
string a[ 1007 ] ;
int f[ 1007 ] ;
int nf[ 1007 ] ;



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
	int i , j ;
	int ans = 0 ;
	for ( i = 0 ; i < n ; i ++ ) { f[ i ] = -1 ; } 


	for ( j = 0 ; j < m ; j ++ ) {
		for ( i = 0 ; i < n ; i ++ ) {
			nf[ i ] = -1 ; 
        }
		for ( i = 1 ; i < n ; i ++ ) {
			if ( a[ i ][ j ] < a[ i - 1 ][ j ] && f[ i ] == -1 ) {
				break ;
            }
			if ( a[ i ][ j ] > a[ i - 1 ][ j ] ) {
				nf[ i ] = 1 ;
            }
		}
		if ( i != n ) { ans ++ ; } 
		else {
			for ( i = 0 ; i < n ; i ++ ) {
				if ( nf[ i ] == 1 ) f[ i ] = 1 ;
            }
        }
    }
	cout << ans << "\n" ;
}
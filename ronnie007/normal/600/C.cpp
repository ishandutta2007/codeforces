#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
using namespace std ;

int n ;
string a ;
int br[ 37 ] ;

void input ( ) {
	cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
	int i , j ;
	for ( i = 0 ; i < n ; i ++ ) {
    	br[ ( a[ i ] - 'a' ) ] ++ ;
    }
    for ( i = 25 ; i >= 0 ; i -- ) {
    	if ( ( br[ i ] % 2 ) == 0 ) { continue ; }
    	for ( j = 0 ; j < i ; j ++ ) {
        	if ( ( br[ j ] % 2 ) == 1 ) {
            	br[ j ] ++ ;
                br[ i ] -- ;
                break ;
            }
        }
    }
    string ret ;
    for ( i = 0 ; i < 26 ; i ++ ) {
    	int val = ( br[ i ] / 2 ) ;
        for ( j = 1 ; j <= val ; j ++ ) {
        	ret += char ( ( 'a' + i ) ) ;
        }
    }
	for ( i = 0 ; i < 26 ; i ++ ) {
    	if ( ( br[ i ] % 2 ) == 1 ) { ret += char ( ( 'a' + i ) ) ; br[ i ] -- ; }
    }
    for ( i = 25 ; i >= 0 ; i -- ) {
    	br[ i ] /= 2 ;
		while ( br[ i ] != 0 ) {
        	br[ i ] -- ;
        	ret += char ( ( 'a' + i ) ) ;
        }
    }
    cout << ret << "\n" ; 
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
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

int n , p ;
string a ;

int diff[ 100007 ] ;

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
	cin >> n >> p ;
	p -- ;
	cin >> a ;
}


void solve ( ) {
	int i ;
	int j ;
	int fst = -1 ;
	int lst = -1 ;
	int ans = 0 ;
	for ( i = 0 ; i < n / 2 ; i ++ ) {
		j = n - i - 1 ;
		if ( p == j ) { p = i ; break ; }
    }
	for ( i = 0 ; i < n / 2 ; i ++ ) {
		j = n - i - 1 ;
		int x = ( a[ i ] - 'a' ) - ( a[ j ] - 'a' ) ;
		if ( x < 0 ) x = -x ;
		if ( 2 * x > 26 ) x = 26 - x ;
		diff[ i ] = x ;
		if ( x != 0 ) {
			if ( fst == -1 ) fst = i ;
            lst = i ; 
			ans += x ;
        }
    }
	if ( lst == -1 ) {
		printf ( "0\n" ) ;
		return ;
    }
	ans += ( lst - fst ) ;
	int ds1 = abs ( lst - p ) ;
	int ds2 = abs ( p - fst ) ;
	ans += min ( ds1 , ds2 ) ;
	printf ( "%d\n" , ans ) ;
}
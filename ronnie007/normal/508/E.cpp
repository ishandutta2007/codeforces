#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<set>
using namespace std ;

#define FULL -2

int n ;
pair < int , int > a[ 607 ] ;
int dp[ 607 ][ 607 ] ; 

string ans ;

void f ( int l , int r ) {
	if ( l > r ) { return ; } 
	if ( dp[ l ][ r ] == FULL ) {
		string u , h ; 
		int i ;
		//for ( i = l ; i <= r ; i ++ ) { u += '(' ; h += ')' ; } 
		//return ( u + h ) ;
		u = '(' ;
		h = ')' ;
		ans += u ;
		f ( l + 1 , r ) ;
		ans += h ;
		return ;
    }
	f ( l , dp[ l ][ r ] ) ;
	f ( dp[ l ][ r ] + 1 , r ) ; 
	return ;
}

void input ( ) ;
void solve ( ) ;

int main ( )  {
    ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	cin >> n ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		cin >> a[ i ].first >> a[ i ].second ;
    }
}

void solve ( )  {
	int i , j , len ;
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = 1 ; j <= n ; j ++ ) {
			dp[ i ][ j ] = -1 ;
        }
    }
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( a[ i ].first == 1 ) { dp[ i ][ i ] = FULL ; } 
    }
	int l , r ; 
	for ( len = 1 ; len < n ; len ++ ) {
		for ( i = 1 ; i + len <= n ; i ++ ) {
			l = i ;
			r = i + len ;
			int u = ( 2 * len + 1 ) ;
			if ( dp[ l + 1 ][ r ] != -1 && a[ l ].first <= u && u <= a[ l ].second ) { dp[ l ][ r ] = FULL  ; continue ; }
			for ( j = l ; j <= r ; j ++ ) {
				if ( dp[ l ][ j ] != -1 && dp[ j + 1 ][ r ] != -1 ) { dp[ l ][ r ] = j ; break ; } 
            }
        }
    }
	if ( dp[ 1 ][ n ] == -1 ) { cout << "IMPOSSIBLE\n" ;  return ; } 
	f ( 1 , n ) ;
	cout << ans << "\n" ;
}
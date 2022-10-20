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
string a , b ;

int f[ 37 ][ 37 ] ;

int mx , ans1 , ans2 ; 

void input ( ) {
	cin >> n ;
	cin >> a ;
	cin >> b ;
}
void solve ( ) {
	int i , j , t , z ;
	for ( i = 0 ; i < n ; i ++ ) {
		int x = ( a[ i ] - 'a' ) + 1 ;
		int y = ( b[ i ] - 'a' ) + 1 ;
		f[ x ][ y ] = i + 1 ; 
	}
	mx = 0 ;
	ans1 = ans2 = -1 ;
	for ( i = 1 ; i <= 26 ; i ++ ) {
		for ( j = 1 ; j <= 26 ; j ++ ) {
			if ( f[ i ][ j ] == 0 ) { continue ; }
			for ( t = 1 ; t <= 26 ; t ++ ) {
				for ( z = 1 ; z <= 26 ; z ++ ) {
					if ( f[ t ][ z ] == 0 ) { continue ; }
					if ( f[ i ][ j ] == f[ t ][ z ] ) { continue ; }
					int val = 0 ;
					if ( i == j ) { val -- ; }
					if ( t == z ) { val -- ; }
					if ( i == z ) { val ++ ; }
					if ( t == j ) { val ++ ; }
					if ( mx < val ) { mx = val ; ans1 = f[ i ][ j ] ; ans2 = f[ t ][ z ] ; }
				}
			}
		}
	}
	if ( ans1 != -1 && ans2 != -1 ) { swap ( a[ ( ans1 - 1 ) ] , a[ ( ans2 - 1 ) ] ) ; }
	int ret = 0 ;
	for ( i = 0 ; i < n ; i ++ ) {
		ret += ( a[ i ] != b[ i ] ) ;
	}
	cout << ret << "\n" ;
	cout << ans1 << " " << ans2 << "\n" ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
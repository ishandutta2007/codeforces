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

void input ( ) {
	cin >> a >> b ;
	n = a.size ( ) ;
}

void solve ( ) {
	int i , j , mask ;
	int pos = 0 ;
	for ( i = 0 ; i < n ; i ++ ) {
		if ( a[ i ] == '+' ) { pos ++ ; }
		else { pos -- ; }
	}
	double br = 0.0000000000 ;
	double tot = 0.0000000000 ;
	for ( mask = 0 ; mask < (1<<n) ; mask ++ ) {
		for ( i = 0 ; i < n ; i ++ ) {
			if ( (mask&(1<<i)) == 0 && b[ i ] != '?' ) { break ; }
		}
		if ( i < n ) { continue ; }
		tot += 1.000000000 ;
		int cur = 0 ;
		for ( i = 0 ; i < n ; i ++ ) {
			if ( (mask&(1<<i)) == 0 ) { cur -- ; }
			else {
				if ( b[ i ] == '?' || b[ i ] == '+' ) { cur ++ ; }
				else { cur -- ; }
			}
		}
		if ( cur == pos ) { br += 1.00000000000 ; }
	}
	cout << setprecision ( 12 ) << ( br / tot ) << "\n" ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
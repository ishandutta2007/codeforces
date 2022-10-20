#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
using namespace std ;

#define OFFSET 1500

int n ;

long long ans = 0 ;

long long br1[ 3 * OFFSET ] ;
long long br2[ 3 * OFFSET ] ;


void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	int x , y ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d%d" , &x , &y ) ;
		int val1 = x + y ;
		int val2 = x - y + OFFSET ;
		ans += br1[ val1 ] ;
		ans += br2[ val2 ] ;
		br1[ val1 ] ++ ;
		br2[ val2 ] ++ ;
	}
}

void solve ( ) {
	printf ( "%I64d\n" , ans ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
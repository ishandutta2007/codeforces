#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<map>
using namespace std ;

#define MAXN 10007

int n ;
int a[ MAXN ] ;

map < pair < int , int > , bool > ZX ;

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
}

void solve ( ) {
	int i ;
	int ans = 0 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		int x = a[ i ] ;
		int y = a[ x ] ;
		if ( ZX.find ( make_pair ( x , y ) ) == ZX.end ( ) ) {
			ans ++ ;
			ZX[ make_pair ( x , y ) ] = true ;
			ZX[ make_pair ( y , x ) ] = true ;
		}
	}
	printf ( "%d\n" , ans ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
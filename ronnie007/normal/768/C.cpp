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

#define MAXN 100007

int n , k , x ;
int a[ MAXN ] ;

int br[ MAXN ] ;

int nw[ MAXN ] ;

int mn = 1001 ;
int mx = 0 ;

void input ( ) {
	scanf ( "%d%d%d" , &n , &k , &x ) ;
	int i ;
	
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
		br[ a[ i ] ] ++ ;
	}
}

void solve ( ) {
	int i , j ;
	for ( i = 1 ; i <= k ; i ++ ) {
		int cur = 0 ;
		for ( j = 0 ; j <= 2048 ; j ++ ) {
			if ( ( cur % 2 ) == 0 ) {
				nw[ ( j ^ x ) ] += ( ( br[ j ] + 1 ) / 2 ) ;
				nw[ j ] += ( br[ j ] - ( ( br[ j ] + 1 ) / 2 ) ) ;
			}
			else {
				nw[ ( j ^ x ) ] += ( br[ j ] / 2 ) ;
				nw[ j ] += ( br[ j ] - ( br[ j ] / 2 ) ) ;
			}
			cur += br[ j ] ;
		}
		for ( j = 0 ; j <= 2048 ; j ++ ) {
			br[ j ] = nw[ j ] ;
			nw[ j ] = 0 ;
		}
	}
	int ans1 , ans2 ;
	ans1 = ans2 = 0 ;
	for ( i = 0 ; i <= 2048 ; i ++ ) {
		if ( br[ i ] != 0 ) { ans1 = i ; }
	}
	for ( i = 2048 ; i >= 0 ; i -- ) {
		if ( br[ i ] != 0 ) { ans2 = i ; }
	}
	printf ( "%d %d\n" , ans1 , ans2 ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
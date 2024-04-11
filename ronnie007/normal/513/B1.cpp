#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
#include<set>
using namespace std ;

int n , k ;
int a[ 15 ] ;
int b[ 15 ] ;

int f ( ) {
	int i , j , t ;
	int mn = -1 ;
	int ans = 0 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = i ; j <= n ; j ++ ) {
			mn = a[ i ] ;
			for ( t = i + 1 ; t <= j ; t ++ ) {
				mn = min ( mn , a[ t ] ) ;
            }
			ans += mn ;
        }
    }
	return ans ;
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
	scanf ( "%d%d" , &n , &k ) ;
}

void solve ( )  {
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) { a[ i ] = i ; }
	int mx = f ( ) ;
	while ( next_permutation ( a + 1 , a + n + 1 ) ) {
		int cur = f ( ) ;
		if ( mx < cur ) { mx = cur ; }
    }
	for ( i = 1 ; i <= n ; i ++ ) { a[ i ] = i ; }
	if ( f ( ) == mx ) { k -- ; } 
	if ( k == 0 ) {
		for ( i = 1 ; i <= n ; i ++ ) {
			printf ( "%d" , a[ i ] ) ;
			if ( i == n ) { printf ( "\n" ) ; }
			else { printf ( " " ) ; }
		}
		return ;
    }
	while ( next_permutation ( a + 1 , a + n + 1 ) ) {
		int cur = f ( ) ;
		if ( cur == mx ) { k -- ; }
		if ( k == 0 ) { break ; }
    }
	for ( i = 1 ; i <= n ; i ++ ) {
		printf ( "%d" , a[ i ] ) ;
		if ( i == n ) { printf ( "\n" ) ; }
		else { printf ( " " ) ; }
	}
}
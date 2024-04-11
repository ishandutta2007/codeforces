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

#define inf 1000000007

int n , k ;
int a[ 407 ] ;

int dp[ 2 ][ 407 ][ 407 ] ;
int pref[ 407 ] ;


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
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
		pref[ i ] = pref[ i - 1 ] + a[ i ] ;
    }
}

void solve ( )  {
	int i , j , t , z ;
	int cur = 1 , prev = 0 ;
	for ( i = 1 ; i < k ; i ++ ) {
		for ( j = 0 ; j <= n ; j ++ ) {
			for ( t = j ; t <= n ; t ++ ) {
				dp[ cur ][ j ][ t ] = -inf ;
            }
        }
		for ( j = 1 ; j <= n ; j ++ ) {
			for ( t = j ; t <= n ; t ++ ) {
				int sm1 = ( pref[ t ] - pref[ j - 1 ] ) ;
				for ( z = t + 1 ; z <= n ; z ++ ) {
					int sm2 = ( pref[ z ] - pref[ t ] ) ;
					dp[ cur ][ t + 1 ][ z ] = max ( dp[ cur ][ t + 1 ][ z ] , dp[ prev ][ j ][ t ] + abs ( sm2 - sm1 ) ) ;
                }
            }
        }
		cur ^= 1 ;
		prev ^= 1 ;
    }
	int ans = 0 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = i ; j <= n ; j ++ ) {
			ans = max ( ans , dp[ prev ][ i ][ j ] ) ;
        }
    }
	printf ( "%d\n" , ans ) ;
}
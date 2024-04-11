#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<ctime>
using namespace std ;

#define inf 1000000007

int n , k ;
int a[ 5007 ] ;

set < int > s ;

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
	int i , j ;
	for ( i = 0 ; i < n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
		s.insert ( a[ i ] ) ;
    }
}

void solve ( )  {
	int q ;
	int x ;
	int i , j , t ;
	int ans = 0 ;
	scanf ( "%d" , &q ) ;
	while ( q != 0 ) {
		q -- ;
		scanf ( "%d" , &x ) ;
		ans = inf ;
		for ( i = 0 ; i < n ; i ++ ) {
			for ( j = 1 ; j <= k ; j ++ ) {
				for ( t = 0 ; t <= j ; t ++ ) {
					if ( t * a[ i ] > x ) { continue ; }
					if ( t * a[ i ] == x && t == j ) {
						ans = min ( ans , j ) ;
						continue ;
                    }
					if ( t == j ) { continue ; }
					int u = x - t * a[ i ] ;
					u /= ( j - t ) ;

					if ( s.find ( u ) != s.end ( ) && a[ i ] * t + u * ( j - t ) == x ) { ans = min ( ans , j ) ; }
                }
            }
        }
		if ( ans == inf ) { ans = -1 ; }
		printf ( "%d\n" , ans ) ;
    }
}
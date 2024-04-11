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

int n , stx , sty ;
struct tuhla {
	int x , y ;
};
struct tuhla a[ 1007 ] ;

int det ( struct tuhla p1 , struct tuhla p2 , struct tuhla p3 ) {
	int k = p1.x * p2.y * 1 + p1.y * 1 * p3.x + 1 * p2.x * p3.y ;
	k -= p3.x * p2.y * 1 + p3.y * 1 * p1.x + 1 * p2.x * p1.y ;
	return k ;
}

int used[ 1007 ] ;

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
	scanf ( "%d%d%d" , &n , &stx , &sty ) ;
	int i ;
	for ( i = 0 ; i < n ; i ++ ) {
		scanf ( "%d%d" , &a[ i ].x , &a[ i ].y ) ;
    }
}

void solve ( )  {
	int i , j ;
	int ans = 0 ;
	struct tuhla p ;
	p.x = stx ;
	p.y = sty ;
	for ( i = 0 ; i < n ; i ++ ) {
		if ( used[ i ] == 0 ) { 
			ans ++ ;
			for ( j = i + 1 ; j < n ; j ++ ) {
				if ( det ( p , a[ i ] , a[ j ] ) == 0 ) { used[ j ] = 1 ; } 
            }
		} 
    }
	printf ( "%d\n" , ans ) ;
}
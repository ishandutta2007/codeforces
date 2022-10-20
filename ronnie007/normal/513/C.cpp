#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
using namespace std ;

// true -- bigger
// false -- smaller

int n ;
int l[ 7 ] ;
int r[ 7 ] ;
int a[ 7 ] ;
int br[ 7 ] ; 

void input ( ) ;
void solve ( ) ;

long long get ( int st , int en , int x , bool fl ) {
	if ( fl == true ) {
		if ( en < x ) { return 0 ; }
		return min ( ( en - st + 1 ) , en - x ) ;
    }
	if ( st > x ) { return 0 ; }
	return min ( ( en - st + 1 ) , x - st ) ;
}

long long equ ( int st , int en , int x ) {
	if ( x < st || en < x ) { return 0 ; }
	return 1 ;
}

int main ( )  {
    ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 0 ; i < n ; i ++ ) {
		scanf ( "%d%d" , &l[ i ] , &r[ i ] ) ;
    }
}

void solve ( ) {
	int i , j , t ;
	double ans = 0 ;
	long long prob ;
	int lim ;
	lim = 1 ;
	for ( i = 0 ; i < n ; i ++ ) { lim *= 3 ; }
	int mask ;
	int u ;
	for ( i = 1 ; i <= 10000 ; i ++ ) {
		for ( mask = 0 ; mask < lim ; mask ++ ) {
			int k = mask ;
			u = n - 1 ;
			while ( u != -1 ) {
				a[ u ] = ( k % 3 ) ;
				k /= 3 ;
				u -- ;
            }
			// 0 --> < i
			// 1 --> = i
			// 2 --> > i
			br[ 0 ] = br[ 1 ] = br[ 2 ] = 0 ;
			for ( j = 0 ; j < n ; j ++ ) {
				br[ a[ j ] ] ++ ;
            }
			if ( br[ 1 ] == 0 ) { continue ; }
			if ( br[ 2 ] > 1 ) { continue ; }
			if ( br[ 2 ] == 0 && br[ 1 ] < 2 ) { continue ; }
			prob = 1 ;
			for ( j = 0 ; j < n ; j ++ ) {
				if ( a[ j ] == 0 ) { prob *= get ( l[ j ] , r[ j ] , i , false ) ; }
				if ( a[ j ] == 1 ) { prob *= equ ( l[ j ] , r[ j ] , i ) ; }
				if ( a[ j ] == 2 ) { prob *= get ( l[ j ] , r[ j ] , i , true ) ; }
            }
			ans += ( i * prob ) ;
        }
    }
	for ( i = 0 ; i < n ; i ++ ) {
		ans /= ( r[ i ] - l[ i ] + 1 ) ;
	}
	printf ( "%.12lf\n" , ans ) ;
}
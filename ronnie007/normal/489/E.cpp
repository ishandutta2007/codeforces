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

#define MAXN 1007

int n , l ;

int a[ MAXN ] ;
int b[ MAXN ] ;
double dp[ MAXN ] ;
int par[ MAXN ] ;

bool f ( double x ) {
	int i , j ;
	double mn = 0 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		mn = MAXN * MAXN * MAXN ;
		for ( j = i - 1 ; j >= 0 ; j -- ) {
			double cost ;
			cost = dp[ j ] + sqrt ( fabs ( l - ( a[ i ] - a[ j ] ) ) ) - x * b[ i ] ;
			if ( cost < mn ) {
				mn = cost ;
				par[ i ] = j ;
            }
        }
		dp[ i ] = mn ;
    }
	return ( dp[ n ] > 0 ) ;
}

void input ( ) ;
void solve ( ) ;

int main ( )  {
    ios::sync_with_stdio ( false ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%d%d" , &n , &l ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d%d" , &a[ i ] , &b[ i ] ) ;
    }
}

void solve ( )  {
	double l , r , mid ;
	l = 0 ;
	r = MAXN * MAXN * MAXN ;
	while ( r - l > 0.0000001 ) {
		mid = ( r + l ) / 2 ;
		//printf ( "%lf\n" , mid ) ;
		if ( f ( mid ) == false ) r = mid ;
		else l = mid ;
    }
	f ( l ) ;
	vector < int > ans ;
	ans.clear ( ) ;
	int x = n ;
	while ( x != 0 ) {
		ans.push_back ( x ) ;
		x = par[ x ] ;
    }
	int sz = ans.size ( ) ;
	int i ;
	for ( i = sz - 1 ; i >= 0 ; i -- ) {
		printf ( "%d" , ans[ i ] ) ;
		if ( i == 0 ) printf ( "\n" ) ;
		else printf ( " " ) ;
    }
}
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
#include<stack>
using namespace std ;

int n , l , r , x ;
int a[ 17 ] ;

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
	scanf ( "%d%d%d%d" , &n , &l , &r , &x ) ;
	int i ;
	for ( i = 0 ; i < n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( )  {
	int limit = (1<<n) ;
	int mask = 0 ;
	int i ;
	int sm = 0 ;
	int mx = 0 ;
	int mn = 1000007 ;
	int ans = 0 ;
	for ( mask = 0 ; mask < limit ; mask ++ ) {
		sm = 0 ;
		mx = 0 ;
		mn = 1000007 ;
		for ( i = 0 ; i < n ; i ++ ) {
			int u = (1<<i) ;
			if ( ((mask)&(u)) != 0 ) {
				sm += a[ i ] ;
				if ( mx < a[ i ] ) { mx = a[ i ] ; }
				if ( mn > a[ i ] ) { mn = a[ i ] ; } 
            }
        }
		if ( sm < l || sm > r ) { continue ; }
		if ( mx - mn < x ) { continue ; }
		ans ++ ;
    }
	printf ( "%d\n" , ans ) ;
}
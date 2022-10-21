#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std ;


#define MAXN 5000007

int n , k ;

int pos[ MAXN ] ;

struct segment_tree {
	int tr[ MAXN ] ;
	void init ( int where , int IL , int IR ) {
		tr[ where ] = 0 ;
		if ( IL == IR ) {
			pos[ IL ] = where ;
			return ;
		}
		int mid = ( IL + IR ) / 2 ;
		init ( 2 * where , IL , mid ) ;
		init ( 2 * where + 1 , mid + 1 , IR ) ;
	}
	void update ( int where ) {
		while ( where != 0 ) {
			tr[ where ] ++ ;
			where /= 2 ;
		}
	}
	int query ( int where , int IL , int IR , int CURL , int CURR ) {
		if ( IL > IR ) { return 0 ; }
		if ( CURL > CURR ) { return 0 ; }
		if ( IR < CURL || CURR < IL ) { return 0 ; }
		if ( CURL <= IL && IR <= CURR ) {
			return tr[ where ] ;
		}
		int mid = ( IL + IR ) / 2 ;
		return ( query ( 2 * where , IL , mid , CURL , CURR ) + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
	}
};
segment_tree w ;
void input ( ) {
	cin >> n >> k ;
}

void solve ( ) {
	w.init ( 1 , 1 , n ) ;
	int i ;
	long long ans = 1 ;
	int st = 1 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		int nxt = st + k ;
		if ( 2 * k <= n ) {
			if ( nxt <= n ) {
				ans += w.query ( 1 , 1 , n , st + 1 , nxt - 1 ) ;
				ans ++ ;
				w.update ( pos[ st ] ) ;
				w.update ( pos[ nxt ] ) ;
				st = nxt ;
			}
			else {
				nxt = nxt - n ;
				ans += w.query ( 1 , 1 , n , st + 1 , n ) ;
				ans += w.query ( 1 , 1 , n , 1 , nxt - 1 ) ;
				ans ++ ;
				w.update ( pos[ st ] ) ;
				w.update ( pos[ nxt ] ) ;			
				st = nxt ;
			}
		}
		else {
			nxt = st - ( n - k ) ;
			if ( nxt >= 1 ) {
				ans += w.query ( 1 , 1 , n , nxt + 1 , st - 1 ) ;
				ans ++ ;
				w.update ( pos[ nxt ] ) ;
				w.update ( pos[ st ] ) ;
				st = nxt ; 
			}
			else {
				nxt += n ;
				ans += w.query ( 1 , 1 , n , nxt + 1 , n ) ;
				ans += w.query ( 1 , 1 , n , 1 , st - 1 ) ;
				ans ++ ;
				w.update ( pos[ nxt ] ) ;
				w.update ( pos[ st ] ) ;				
				st = nxt ;
			}
		}
		cout << ans ;
		if ( i == n ) { cout << "\n" ; }
		else { cout << " " ; }
	}
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
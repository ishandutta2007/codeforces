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

#define MAXN 300007

int n ;
int a[ MAXN ] ;

int LEAVES ;

struct node {
	int len ;
	long long l , r ;
	int linc , rinc ;
	int ldec , rdec ;
	int lhill , rhill ;
	int ans ;
	node ( ) {
		len = linc = rinc = ldec = rdec = ans = 0 ;
		l = r = 0 ;
		lhill = rhill = 0 ;
	}
	node ( int x ) {
		len = 1 ;
		l = r = a[ x ] ;
		len = linc = rinc = ldec = rdec = ans = 1 ;
		lhill = rhill = 1 ;		
	}
};

node merge ( node p1 , node p2 ) {
	if ( p1.len == 0 ) { return p2 ; }
	if ( p2.len == 0 ) { return p1 ; }
	node ret ;
	ret.len = ( p1.len + p2.len ) ;
	ret.l = p1.l ;
	ret.r = p2.r ;
	if ( p1.linc == p1.len && p1.r < p2.l ) { ret.linc = p1.linc + p2.linc ; }
	else { ret.linc = p1.linc ; }
	
	if ( p1.ldec == p1.len && p1.r > p2.l ) { ret.ldec = p1.ldec + p2.ldec ; }
	else { ret.ldec = p1.ldec ; }

	if ( p2.rinc == p2.len && p1.r < p2.l ) { ret.rinc = p2.rinc + p1.rinc ; }
	else { ret.rinc = p2.rinc ; }

	if ( p2.rdec == p2.len && p1.r > p2.l ) { ret.rdec = p2.rdec + p1.rdec ; }
	else { ret.rdec = p2.rdec ; }

	ret.lhill = max ( ret.linc , ret.ldec ) ;
	if ( p1.lhill == p1.len && p1.r > p2.l ) { ret.lhill = max ( ret.lhill , p1.lhill + p2.ldec ) ; }
	else { ret.lhill = max ( ret.lhill , p1.lhill ) ; }
	if ( p1.linc == p1.len && p1.r < p2.l ) { ret.lhill = max ( ret.lhill , p1.linc + p2.lhill ) ; }
	else { ret.lhill = max ( ret.lhill , p1.linc ) ; }

	ret.rhill = max ( ret.rinc , ret.rdec ) ;
	if ( p2.rhill == p2.len && p1.r < p2.l ) { ret.rhill = max ( ret.rhill , p2.rhill + p1.rinc ) ; }
	else { ret.rhill = max ( ret.rhill , p2.rhill ) ; }
	if ( p2.rdec == p2.len && p1.r > p2.l ) { ret.rhill = max ( ret.rhill , p2.rdec + p1.rhill ) ; }
	else { ret.rhill = max ( ret.rhill , p2.rdec ) ; }

	ret.ans = max ( p1.ans , p2.ans ) ;
	ret.ans = max ( ret.ans , ret.lhill ) ;
	ret.ans = max ( ret.ans , ret.rhill ) ;
	if ( p1.r > p2.l ) { ret.ans = max ( ret.ans , p1.rhill + p2.ldec ) ; }
	if ( p1.r < p2.l ) { ret.ans = max ( ret.ans , p1.rinc + p2.lhill ) ; }
	return ret ;	
}

struct segment_tree {
	node tr[ 10 * MAXN ] ;
	long long lazy[ 10 * MAXN ] ;
	void print_vertex ( int where ) {
		printf ( "----- %d\n" , where ) ;
		printf ( "len = %d ; l = %d ; r = %d\n" , tr[ where ].len , tr[ where ].l , tr[ where ].r ) ;
		printf ( "linc = %d ; ldec = %d\n" , tr[ where ].linc , tr[ where ].ldec ) ;
		printf ( "rinc = %d ; rdec = %d\n" , tr[ where ].rinc , tr[ where ].rdec ) ;
		printf ( "lhill = %d ; rhill = %d\n" , tr[ where ].lhill , tr[ where ].rhill ) ;
		printf ( "ans = %d\n" , tr[ where ].ans ) ;
		printf ( "-----\n" ) ;
	}
	void init ( int where , int IL , int IR ) {
		if ( IL > IR ) { return ; }
		if ( IL == IR ) {
			tr[ where ] = node ( IL ) ;
			return ;
		}
		int mid = ( IL + IR ) / 2 ;
		init ( 2 * where , IL , mid ) ;
		init ( 2 * where + 1 , mid + 1 , IR ) ;
		tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
	}
	void push ( int where ) {
		if ( lazy[ where ] != 0 ) {
			tr[ where ].l += lazy[ where ] ;
			tr[ where ].r += lazy[ where ] ;
			if ( tr[ where ].len != 1 ) {
				lazy[ 2 * where ] += lazy[ where ] ;
				lazy[ 2 * where + 1 ] += lazy[ where ] ;
			}
			lazy[ where ] = 0 ;
		}
	}
	void update ( int where , int IL , int IR , int CURL , int CURR , int add ) {
		if ( IL > IR ) { return ; }
		push ( where ) ;
		if ( IR < CURL || CURR < IL ) { return ; }
		if ( CURL <= IL && IR <= CURR ) {
			lazy[ where ] += add ;
			push ( where ) ;
			return ;
		}
		int mid = ( IL + IR ) / 2 ;
		update ( 2 * where , IL , mid , CURL , CURR , add ) ;
		update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , add ) ;
		tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
		//print_vertex ( where ) ;
	}
};

segment_tree w ;

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
}

void solve ( ) {
	w.init ( 1 , 1 , n ) ;
	int q ;
	int x , y , z ;
	scanf ( "%d" , &q ) ;
	while ( q != 0 ) {
		q -- ;
		scanf ( "%d%d%d" , &x , &y , &z ) ;
		w.update ( 1 , 1 , n , x , y , z ) ;
		printf ( "%d\n" , w.tr[ 1 ].ans ) ;
	}
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
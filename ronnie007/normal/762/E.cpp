#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
#include<set>
#include<stack>
using namespace std ;

#define MAXN 100007
#define inf 1000000007
int n , k ;
struct tuhla {
	int x ;
	int r ;
	int f ;
};

tuhla a[ MAXN ] ;


struct Tree {
 	Tree *pl , *pr ;
	int l , r ;
	int br ;
	Tree ( int x , int y ) {
		this->l = x ;
		this->r = y ;
		this->br = 0 ;
		this->pl = this->pr = NULL ;
	}
	void update ( int pos ) {
		this->br ++ ;		
		if ( this->l == this->r ) { return ; }		
		int mid = ( this->l + this->r ) / 2 ;
		if ( pos <= mid ) {
			if ( this->pl == NULL ) {
				this->pl = new Tree ( this->l , mid ) ;
			}
			this->pl->update ( pos ) ;
		}
		else {
			if ( this->pr == NULL ) {
				this->pr = new Tree ( mid + 1 , this->r ) ;
			}
			this->pr->update ( pos ) ;
		}
	}
	int query ( int IL , int IR ) {
		if ( IL > IR ) { return 0 ; }
		if ( this->r < IL || IR < this->l ) { return 0 ; }
		if ( IL <= this->l && this->r <= IR ) { return this->br ; }
		int mid = ( IL + IR ) / 2 ;
		int ret = 0 ;
		if ( this->pl != NULL ) { ret += this->pl->query ( IL , IR ) ; }
		if ( this->pr != NULL ) { ret += this->pr->query ( IL , IR ) ; }
		return ret ;
	}
};

Tree* root[ MAXN ] ;

bool cmp ( tuhla p1 , tuhla p2 ) {
	return ( p1.r > p2.r ) ;
}

void input ( ) {
	scanf ( "%d%d" , &n , &k ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d%d%d" , &a[ i ].x , &a[ i ].r , &a[ i ].f ) ;
	}
	sort ( a + 1 , a + n + 1 , cmp ) ;
}

void solve ( ) {
	int i ;
	int j ;
	long long ans = 0 ;
	for ( i = 1 ; i <= 10000 ; i ++ ) {
		root[ i ] = new Tree ( 1 , inf ) ;
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		int st = max ( 1 , a[ i ].x - a[ i ].r ) ;
		int en = min ( inf , a[ i ].x + a[ i ].r ) ;	
		for ( j = a[ i ].f - k ; j <= a[ i ].f + k ; j ++ ) {
			if ( j < 1 || j > 10000 ) { continue ; }
			ans += root[ j ]->query ( st , en ) ;
		}
		root[ a[ i ].f ]->update ( a[ i ].x ) ;
	}
	cout << ans << "\n" ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
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

#define MAXN 200007

int n ;
pair < int , int > a[ MAXN ] ;

vector < int > srt ;
map < int , int > ZX ;

vector < pair < int , int > > tosolve[ MAXN ] ;

int ans[ MAXN ] ;

int MAXVAL ;

struct Tree {
	Tree *pl , *pr ;
	int l , r ;
	int val ;
	bool lazy ;
	Tree ( int x , int y ) {
		this->l = x ;
		this->r = y ;
		this->val = this->lazy = 0 ;
		this->pl = this->pr = NULL ;
	}
	void merge ( ) {
		this->val = 0 ;
		if ( this->pl != NULL ) {
			this->val += this->pl->val ;
		}
		if ( this->pr != NULL ) {
			this->val += this->pr->val ;
		}
		if ( this->lazy == 1 ) {
			this->val = ( this->r - this->l + 1 ) ;
		}
	}
	void update ( int CURL , int CURR ) {
		if ( this->lazy == 1 ) {
			this->val = ( this->r - this->l + 1 ) ;
			return ;
		}
		if ( CURL > CURR ) { return ; }
		if ( this->r < CURL || CURR < this->l ) { return ; }
		if ( CURL <= this->l && this->r <= CURR ) {
			this->lazy = 1 ;
			this->val = ( this->r - this->l + 1 ) ;
			return ;
		}
		if ( this->pl == NULL ) {
			if ( ( 0LL + this->l + this->r ) / 2 >= CURL || CURR >= this->l ) {
				this->pl = new Tree ( this->l , ( 0LL + this->l + this->r ) / 2 ) ;
				this->pl->lazy = this->lazy ;
				this->pl->update ( CURL , CURR ) ;
			}
		}
		else {
			if ( this->lazy == 1 ) { this->pl->lazy = 1 ; }
			this->pl->update ( CURL , CURR ) ;
		}
		if ( this->pr == NULL ) {
			if ( this->r >= CURL || CURR >= ( 0LL + this->l + this->r ) / 2 + 1 ) {
				this->pr = new Tree ( ( 0LL + this->l + this->r ) / 2 + 1 , this->r ) ;
				this->pr->lazy = this->lazy ;
				this->pr->update ( CURL , CURR ) ;
			}
		}
		else {
			if ( this->lazy == 1 ) { this->pr->lazy = 1 ; }
			this->pr->update ( CURL , CURR ) ;
		}
		this->merge ( ) ;
	}
	int query ( int CURL , int CURR ) {
		if ( this->lazy == 1 ) {
			this->val = ( this->r - this->l + 1 ) ;
		}	
		if ( CURL > CURR ) { return 0 ; }
		if ( this->r < CURL || CURR < this->l ) { return 0 ; }
		if ( CURL <= this->l && this->r <= CURR ) {
			return this->val ;
		}
		int ret = 0 ;
		if ( this->pl != NULL ) {
			if ( this->lazy == 1 ) { this->pl->lazy = 1 ; }
			ret += this->pl->query ( CURL , CURR ) ;
		}
		else {
			if ( ( 0LL + this->l + this->r ) / 2 >= CURL || CURR >= this->l ) {
				this->pl = new Tree ( this->l , ( 0LL + this->l + this->r ) / 2 ) ;
				this->pl->lazy = this->lazy ;
				ret += this->pl->query ( CURL , CURR ) ;
			}			
		}
		if ( this->pr != NULL ) {
			if ( this->lazy == 1 ) { this->pr->lazy = 1 ; }		
			ret += this->pr->query ( CURL , CURR ) ;		
		}
		else {
			if ( this->r >= CURL || CURR >= ( 0LL + this->l + this->r ) / 2 + 1 ) {
				this->pr = new Tree ( ( 0LL + this->l + this->r ) / 2 + 1 , this->r ) ;
				this->pr->lazy = this->lazy ;
				ret += this->pr->query ( CURL , CURR ) ;
			}		
		}
		return ret ;
	}
};

Tree *root ;

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
		a[ i ].second += a[ i ].first ;
		MAXVAL = max ( MAXVAL , a[ i ].second ) ;
	}
	root = new Tree ( 1 , MAXVAL ) ;
}

void solve ( ) {
	int q ;
	int i , j ;
	scanf ( "%d" , &q ) ;
	for ( i = 1 ; i <= q ; i ++ ) {
		int x , y ;
		scanf ( "%d%d" , &x , &y ) ;
		tosolve[ x ].push_back ( make_pair ( y , i ) ) ;
	}
	for ( i = n ; i >= 1 ; i -- ) {
		root->update ( a[ i ].first , a[ i ].second - 1 ) ;
		int sz = tosolve[ i ].size ( ) ;
		for ( j = 0 ; j < sz ; j ++ ) {
			int len = ( a[ tosolve[ i ][ j ].first ].second - a[ i ].first ) ;
			ans[ tosolve[ i ][ j ].second ] = ( len - root->query ( a[ i ].first , a[ tosolve[ i ][ j ].first ].second - 1 ) ) ;
		}
	}
	for ( i = 1 ; i <= q ; i ++ ) {
		printf ( "%d\n" , ans[ i ] ) ;
	}
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
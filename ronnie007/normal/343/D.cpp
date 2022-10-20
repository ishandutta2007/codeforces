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

#define MAXN 500007

int n ;
vector < int > v[ MAXN ] ;

vector < int > ord ;

int st[ MAXN ] ;
int en[ MAXN ] ;

int lst[ MAXN ] ;

struct Tree {
	Tree *pl , *pr ;
	int l , r ;
	int val , lazy ;
	int has ;
	Tree ( int x , int y ) {
		this->l = x ;
		this->r = y ;
		this->val = this->lazy = this->has = 0 ;
		this->pl = this->pr = NULL ;
		if ( this->l == this->r ) { return ; }
		this->pl = new Tree ( x , ( ( x + y ) / 2 ) ) ;
		this->pr = new Tree ( ( ( x + y ) / 2 + 1 ) , y ) ;
	}
	void push_lazy ( ) {
		if ( this->lazy == 0 ) { return ; }
		this->val = 1 ;
		this->has = 0 ;
		if ( this->pl != NULL ) {
			this->pl->lazy = 1 ;
		}
		if ( this->pr != NULL ) {
			this->pr->lazy = 1 ;
		}
		this->lazy = 0 ;
	}
	void merge ( ) {
		if ( this->pl->has != 0 || this->pr->has != 0 ) {
			this->has = 1 ;
		}
		else {
			this->has = 0 ;
		}
	}
	void update ( int x , int y , bool val ) {
		if ( x > y ) { return ; }
		if ( this->l > this->r ) { return ; }
		this->push_lazy ( ) ;
		if ( this->r < x || y < this->l ) { return ; }
		if ( x <= this->l && this->r <= y ) {
			if ( val == true ) {
				this->lazy = 1 ;
				this->push_lazy ( ) ;
			}
			else {
				this->val = 0 ;
				this->has = 1 ;
			}
			return ;
		}
		this->pl->update ( x , y , val ) ;
		this->pr->update ( x , y , val ) ;
		this->merge ( ) ;
	}
	bool is_lit ( int pos ) {
		if ( this->l > this->r ) { return false ; }
		this->push_lazy ( ) ;
		if ( this->r < pos || pos < this->l ) { return false ; }
		if ( this->l == this->r ) {
			return ( this->val == 1 ) ;
		}
		return ( max ( this->pl->is_lit ( pos ) , this->pr->is_lit ( pos ) ) ) ;
	}
	bool f ( int x , int y ) {
		if ( x > y ) { return false ; }
		if ( this->l > this->r ) { return false ; }
		this->push_lazy ( ) ;
		if ( this->r < x || y < this->l ) { return false ; }
		if ( x <= this->l && this->r <= y ) {
			return ( this->has != 0 ) ;
		}
		return ( max ( this->pl->f ( x , y ) , this->pr->f ( x , y ) ) ) ;
	}
};

Tree *root ;

void dfs ( int vertex , int prv ) {
	lst[ vertex ] = prv ;
	ord.push_back ( vertex ) ;
	st[ vertex ] = ord.size ( ) ;
	int i ;
	int sz = v[ vertex ].size ( ) ;
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( v[ vertex ][ i ] == prv ) { continue ; }
		dfs ( v[ vertex ][ i ] , vertex ) ;
	}
	en[ vertex ] = ord.size ( ) ;
}

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i < n ; i ++ ) {
		int x , y ;
		scanf ( "%d%d" , &x , &y ) ;
		v[ x ].push_back ( y ) ;
		v[ y ].push_back ( x ) ;
	}
}

void solve ( ) {
	dfs ( 1 , -1 ) ;
	root = new Tree ( 1 , n ) ;
	int q ;
	scanf ( "%d" , &q ) ;
	int x , y ;
	while ( q != 0 ) {
		q -- ;
		scanf ( "%d%d" , &x , &y ) ;
		if ( x == 1 ) {
			if ( y != 1 ) {
				if ( root->is_lit ( st[ y ] ) == false || root->f ( st[ y ] , en[ y ] ) == true ) {
					root->update ( st[ lst[ y ] ] , st[ lst[ y ] ] , false ) ;
				}
			}
			root->update ( st[ y ] , en[ y ] , true ) ;
		}
		else if ( x == 2 ) {
			root->update ( st[ y ] , st[ y ] , false ) ;
		}
		else {	
			if ( root->is_lit ( st[ y ] ) == true && root->f ( st[ y ] , en[ y ] ) == false ) {
				printf ( "1\n" ) ;
			}
			else {
				printf ( "0\n" ) ;
			}
		}
	}
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
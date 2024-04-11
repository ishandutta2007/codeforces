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

int n , q ;
string a ;

struct Tree {
	Tree *pl , *pr ;
	int l , r ;
	int br4 , br7 ;
	int br47 , br74 ;
	bool lazy ;
	void merge ( ) {
		this->br4 = this->pl->br4 + this->pr->br4 ;
		this->br7 = this->pl->br7 + this->pr->br7 ;
		this->br47 = max ( this->pl->br47 , this->pr->br47 ) ;
		this->br47 = max ( this->br47 , this->pl->br47 + this->pr->br7 ) ;
		this->br47 = max ( this->br47 , this->pl->br4 + this->pr->br47 ) ;
		this->br47 = max ( this->br47 , this->pl->br4 + this->pr->br7 ) ;		
		this->br74 = max ( this->pl->br74 , this->pr->br74 ) ;
		this->br74 = max ( this->br74 , this->pl->br74 + this->pr->br4 ) ;
		this->br74 = max ( this->br74 , this->pl->br7 + this->pr->br74 ) ;
		this->br74 = max ( this->br74 , this->pl->br7 + this->pr->br4 ) ;				
	}
	void push_lazy ( ) {
		if ( this->lazy == 0 ) { return ; }
		swap ( this->br4 , this->br7 ) ;
		swap ( this->br47 , this->br74 ) ;
		if ( this->l != this->r ) {
			this->pl->lazy ^= 1 ;
			this->pr->lazy ^= 1 ;
		}
		this->lazy = 0 ;
	}
	Tree ( int x , int y ) {
		this->l = x ;
		this->r = y ;
		this->lazy = 0 ;
		if ( x == y ) {
			if ( a[ ( x - 1 ) ] == '4' ) {
				this->br4 = 1 ;
				this->br7 = 0 ;
				this->br47 = 1 ;
				this->br74 = 1 ;
			}
			else {
				this->br4 = 0 ;
				this->br7 = 1 ;
				this->br47 = 1 ;
				this->br74 = 1 ;				
			}
			return ;
		}
		this->pl = new Tree ( x , ( ( x + y ) / 2 ) ) ;
		this->pr = new Tree ( ( ( x + y ) / 2 + 1 ) , y ) ;
		this->merge ( ) ;
	}
	void update ( int CURL , int CURR ) {
		if ( CURL > CURR ) { return ; }
		this->push_lazy ( ) ;		
		if ( this->r < CURL || CURR < this->l ) { return ; }
		if ( CURL <= this->l && this->r <= CURR ) {
			this->lazy ^= 1 ;
			this->push_lazy ( ) ;
			return ;
		}
		this->pl->update ( CURL , CURR ) ;
		this->pr->update ( CURL , CURR ) ;
		this->merge ( ) ;
	}
};
Tree *root ;

void input ( ) {
	cin >> n >> q ;
	cin >> a ;
	root = new Tree ( 1 , n ) ;
}

void solve ( ) {
	string type ;
	int l , r ;
	while ( q != 0 ) {
		q -- ;
		cin >> type ;
		if ( type == "switch" ) {
			cin >> l >> r ;
			root->update ( l , r ) ;
		}
		else {
			cout << root->br47 << "\n" ;
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
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

#define MAXN 100007

int n ;
pair < int , int > a[ MAXN ] ;

int id[ MAXN ] ;

struct Tree {
	Tree *pl , *pr ;
	int l , r ;
	long long val ;
	Tree ( int x , int y ) {
		this->l = x ;
		this->r = y ;
		this->val = 0 ;
		if ( x == y ) {
			this->pl = this->pr = NULL ;
			return ;
		}
		this->pl = new Tree ( x , ( ( x + y ) / 2 ) ) ;
		this->pr = new Tree ( ( ( x + y ) / 2 + 1 ) , y ) ;
	}
	void merge ( ) {
		this->val = max ( this->pl->val , this->pr->val ) ;
	}
	void update ( int pos , long long cur ) {
		if ( this->r < pos || pos < this->l ) { return ; }
		if ( this->l == this->r && this->l == pos ) {
			this->val = cur ;
			return ;
		}
		this->pl->update ( pos , cur ) ;
		this->pr->update ( pos , cur ) ;
		merge ( ) ;
	}
	long long query ( int CURL , int CURR ) {
		if ( this->r < CURL || CURR < this->l ) { return 0 ; }
		if ( CURL <= this->l && this->r <= CURR ) {
			return this->val ;
		}
		return max ( this->pl->query ( CURL , CURR ) , this->pr->query ( CURL , CURR ) ) ;
	}
};
Tree *root ;

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	vector < pair < long long , int > > srt ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
		srt.push_back ( make_pair ( ( 1LL * a[ i ].first * a[ i ].first * a[ i ].second ) , -i ) ) ;
	}
	sort ( srt.begin ( ) , srt.end ( ) ) ;
	for ( i = 0 ; i < n ; i ++ ) {
		id[ -srt[ i ].second ] = i + 1 ;
	}
	root = new Tree ( 1 , n ) ;
}

void solve ( ) {
	int i ;
	long long ans = -1 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		long long h = root->query ( 1 , id[ i ] ) ;
		root->update ( id[ i ] , h + ( 1LL * a[ i ].first * a[ i ].first * a[ i ].second ) ) ;
		ans = max ( ans , ( h + ( 1LL * a[ i ].first * a[ i ].first * a[ i ].second ) ) ) ;
	}
	printf ( "%.12lf\n" , M_PI * ans ) ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
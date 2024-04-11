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

int n ;
long long k ;
long long pref[ MAXN ] ;

pair < long long , int > srt[ MAXN ] ;

int revid[ MAXN ] ;

struct Tree {
	Tree *pl , *pr ;
	int l , r ;
	int br ;
	Tree ( int x , int y ) {
		this->l = x ;
		this->r = y ;
		this->br = 0 ;
		if ( x == y ) { return ; }
		this->pl = new Tree ( x , ( ( x + y ) / 2 ) ) ;
		this->pr = new Tree ( ( ( x + y ) / 2 + 1 ) , y ) ;
	}
	void update ( int pos , int val ) {
		if ( this->r < pos || pos < this->l ) { return ; }
		if ( this->l == this->r && this->l == pos ) {
			this->br += val ;
			return ;
		}
		this->pl->update ( pos , val ) ;
		this->pr->update ( pos , val ) ;
		this->br = ( this->pl->br + this->pr->br ) ; 
	}
	int query ( long long val ) {
		if ( srt[ this->r ].first <= val ) { return this->br ; }
		if ( srt[ this->l ].first > val ) { return 0 ; }
		return ( this->pl->query ( val ) + this->pr->query ( val ) ) ;
	}
};
Tree *root ;

long long f ( long long x ) {
	int i ;
	long long ret = 0 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		long long val = pref[ i ] - x ;
		ret += root->query ( val ) ;
		root->update ( revid[ i ] , 1 ) ;
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		root->update ( revid[ i ] , -1 ) ;
	}
	return ret ;
}

void input ( ) {
	cin >> n >> k ;
	int i ;
	int x ;
	for ( i = 1 ; i <= n ; i ++ ) {
		cin >> x ;
		pref[ i ] = ( pref[ i - 1 ] + x ) ;
		srt[ i ] = make_pair ( pref[ i ] , i ) ;
	}
	srt[ n + 1 ] = make_pair ( 0 , 0 ) ;
	sort ( srt + 1 , srt + n + 2 ) ;
	root = new Tree ( 1 , n + 1 ) ;	
	for ( i = 1 ; i <= n + 1 ; i ++ ) {
		revid[ srt[ i ].second ] = i ;
		if ( srt[ i ].second == 0 ) {
			root->update ( i , 1 ) ;
		}
	}
}

void solve ( ) {
	long long l , r , mid ;
	int i ;
	l = -1 ;
	r = 1 ;
	for ( i = 1 ; i <= 14 ; i ++ ) {
		l *= 10 ;
		r *= 10 ;
	}
	while ( r - l > 3 ) {
		mid = ( l + r ) / 2 ;
		if ( f ( mid ) < k ) { r = mid ; }
		else { l = mid ; }
	}
	while ( f ( r ) < k ) { r -- ; }
	cout << r << "\n" ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
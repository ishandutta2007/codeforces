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

int n , g , r ;
int tot ;
long long dist[ MAXN ] ;

vector < long long > v ;

long long dp[ MAXN ] ;

struct Tree {
	Tree *pl , *pr ;
	int val ;
	int l , r ;
	void merge ( ) {
		val = min ( pl->val , pr->val ) ;
	}
	Tree ( int x , int y ) {
		l = x ;
		r = y ;
		val = n ;
		if ( x == y ) { return ; }
		pl = new Tree ( x , ((x+y)/2) ) ;
		pr = new Tree ( ((x+y)/2) + 1 , y ) ;
		merge ( ) ;
	}
	void update ( int where , int cur ) {
		if ( l > r ) { return ; }
		if ( v[ r ] < where || where < v[ l ] ) { return ; }
		if ( l == r ) {
			val = min ( val , cur ) ;
			return ;
		}
		pl->update ( where , cur ) ;
		pr->update ( where , cur ) ;
		merge ( ) ;
	}
	int query ( int IL , int IR ) {
		if ( IL > IR ) { return n ; }
		if ( v[ r ] < IL || IR < v[ l ] ) { return n ; }
		if ( IL <= v[ l ] && v[ r ] <= IR ) {
			return val ;
		}
		return min ( pl->query ( IL , IR ) , pr->query ( IL , IR ) ) ;
	}
};
Tree *root ;

int get ( long long where , long long st ) {
	long long h = ( st - ( where % tot ) + tot ) % tot ;
	if ( h <= g ) {
		return root->query ( g - h , tot - h - 1 ) ;
	}
	else {
		return min ( root->query ( 0 , tot - h - 1 ) , root->query ( tot - h + g , tot - 1 ) ) ;
	}
}

vector < long long > norm ( vector < long long > x ) {
	vector < long long > ret ;
	int i ;
	int sz = x.size ( ) ;
	ret.clear ( ) ;
	ret.push_back ( x[ 0 ] ) ;
	for ( i = 1 ; i < sz ; i ++ ) {
		if ( x[ i ] == x[ i - 1 ] ) { continue ; }
		ret.push_back ( x[ i ] ) ;
	}
	return ret ;
}

long long wait ( long long x ) {
	return ( tot - ( x % tot ) ) ;
}

void input ( ) {
	cin >> n >> g >> r ;
	tot = ( g + r ) ;
	int i ;
	for ( i = 0 ; i <= n ; i ++ ) {
		cin >> dist[ i ] ;
		if ( i != 0 ) { dist[ i ] += dist[ i - 1 ] ; }
		v.push_back ( ( dist[ i ] % tot ) ) ;
	}
	sort ( v.begin ( ) , v.end ( ) ) ;
	v = norm ( v ) ;
	root = new Tree ( 0 , v.size ( ) - 1 ) ;
}

void solve ( ) {
	int i ;
	dp[ n ] = 0 ;
	for ( i = n - 1 ; i >= 0 ; i -- ) {
		int id = get ( dist[ i ] , 0 ) ;
		if ( id == n ) {
			dp[ i ] = dist[ n ] - dist[ i ] ;
		}
		else {
			dp[ i ] = dp[ id ] + dist[ id ] - dist[ i ] + wait ( dist[ id ] - dist[ i ] ) ;
		}
		root->update ( ( dist[ i ] % tot ) , i ) ;
	}
	int q ;
	cin >> q ;
	long long t ;
	while ( q != 0 ) {
		q -- ;
		cin >> t ;
		int id = get ( 0 , t ) ;
		if ( id == n ) {
			cout << t + dist[ n ] << "\n" ;
		}
		else {
			cout << t + dist[ id ] + wait ( t + dist[ id ] ) + dp[ id ] << "\n" ;
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
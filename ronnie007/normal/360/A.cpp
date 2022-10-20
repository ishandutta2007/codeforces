#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
using namespace std ;

#define MAXN 5007
#define inf 1000000000


int n , m ;
int cur[ MAXN ] ;
int diff[ MAXN ] ;
int st[ MAXN ] ;

struct op {
	int type ;
	int l , r ;
	int val ;
};
vector < struct op > v ;

void input ( ) ;
void solve ( ) ;

int main ( )  {
    ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}

void input ( ) {
	scanf ( "%d%d" , &n , &m ) ;
	int i , j ;
	int x , y , z , t ;
	for ( i = 1 ; i <= n ; i ++ ) { diff[ i ] = inf ; }
	for ( i = 1 ; i <= m ; i ++ ) {
		scanf ( "%d%d%d%d" , &x , &y , &z , &t ) ;
		struct op u ;
		u.type = x ; u.l = y ; u.r = z ; u.val = t ;
		v.push_back ( u ) ;
		if ( x == 1 ) {
			for ( j = y ; j <= z ; j ++ ) { cur[ j ] += t ; }
		}
		else {
			for ( j = y ; j <= z ; j ++ ) { diff[ j ] = min ( diff[ j ] , t - cur[ j ] ) ; }
		}
	}
}

void solve ( ) {
	int i , j ;
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( abs ( diff[ i ] ) > inf ) { printf ( "NO\n" ) ; return ; }
		st[ i ] = diff[ i ] ;
	}
	for ( i = 0 ; i < m ; i ++ ) {
		if ( v[ i ].type == 1 ) {
			for ( j = v[ i ].l ; j <= v[ i ].r ; j ++ ) { st[ j ] += v[ i ].val ; }
		}
		else {
			int mx = -2 * inf ;
			for ( j = v[ i ].l ; j <= v[ i ].r ; j ++ ) { mx = max ( mx , st[ j ] ) ; }
			if ( mx != v[ i ].val ) { printf ( "NO\n" ) ; return ; }
		}
	}
	printf ( "YES\n" ) ;
	for ( i = 1 ; i <= n ; i ++ ) {
		printf ( "%d" , diff[ i ] ) ;
		if ( i == n ) { printf ( "\n" ) ; }
		else { printf ( " " ) ; }
	}
}
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

#define MAXN 300007

int n , m ;
char a[ MAXN ] ;
int pos[ MAXN ] ;
char prv[ MAXN ] ;

int par[ MAXN ] ;
int len[ MAXN ] ;

int LEAVES ;

struct tuhla {
	int lend ;
	int rend ;
	int val ;
	int len ;
};

struct tuhla tr[ 4 * MAXN ] ;

int w ( int len ) {
	return ( max ( len - 1 , 0 ) ) ;
}


void update ( int where ) {
	int cur ;

	while ( where != 0 ) {
		int l = 2 * where ;
		int r = 2 * where + 1 ;
		tr[ where ].len = tr[ l ].len + tr[ r ].len ;
		if ( tr[ l ].lend == tr[ l ].len ) {
			tr[ where ].lend = tr[ l ].lend + tr[ r ].lend ; 
        }
		else { tr[ where ].lend = tr[ l ].lend ; }
		if ( tr[ r ].rend == tr[ r ].len ) {
			tr[ where ].rend = tr[ r ].rend + tr[ l ].rend ;
        }
		else { tr[ where ].rend = tr[ r ].rend ; }
		tr[ where ].val = tr[ l ].val + tr[ r ].val ;
		tr[ where ].val += w ( tr[ l ].rend + tr[ r ].lend ) ;
		tr[ where ].val -= w ( tr[ l ].rend ) ;
		tr[ where ].val -= w ( tr[ r ].lend ) ;
		where /= 2 ;
    }
}

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
	scanf ( "%s" , &a ) ;
	int i ;
	char u ;
	for ( i = 1 ; i <= m ; i ++ ) {
		scanf ( "\n%d %c" , &pos[ i ] , &prv[ i ] ) ;
		pos[ i ] -- ;
    }
	LEAVES = 1 ;
	while ( LEAVES < n ) { LEAVES *= 2 ; }
}

void solve ( ) {
	int i ;
	for ( i = 0 ; i < n ; i ++ ) {
		int p ;
		if ( a[ i ] == '.' ) { p = 1 ; }
		else { p = 0 ; }
		tr[ LEAVES + i ].len = 1 ;
		tr[ LEAVES + i ].lend = tr[ LEAVES + i ].rend = p ;
		tr[ LEAVES + i ].val = 0 ;
		update ( ( LEAVES + i ) / 2 ) ;
    }
	for ( i = 1 ; i <= m ; i ++ ) {
		a[ pos[ i ] ] = prv[ i ] ;
		int p ;
		if ( a[ pos[ i ] ] == '.' ) { p = 1 ; }
		else { p = 0 ; }
		tr[ LEAVES + pos[ i ] ].lend = tr[ LEAVES + pos[ i ] ].rend = p ;
		update ( ( LEAVES + pos[ i ] ) / 2 ) ;
		printf ( "%d\n" , tr[ 1 ].val ) ;
    }
}
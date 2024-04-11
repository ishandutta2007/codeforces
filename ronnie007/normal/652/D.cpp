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

#define MAXN 200007

int n ;
int st[ MAXN ] ;
int ans[ MAXN ] ;
struct tuhla {
	int x , y ;
    int id ;
    int type ;
};

bool cmp ( struct tuhla p1 , struct tuhla p2 ) {
	return ( p1.y < p2.y ) ;
}

vector < struct tuhla > v ;

long long LEAVES = 1 ;
struct node {
	int val ;
    int l , r ;
};
struct node q ;
vector < struct node > tr ;

void update ( int where , long long IL , long long IR , int pos ) {
	tr[ where ].val ++ ;
    if ( IL == pos && IR == pos ) { return ; }
    long long mid = IL ;
    mid += IR ;
    mid /= 2 ;
    if ( pos <= mid ) {
    	if ( tr[ where ].l == 0 ) {
        	tr.push_back ( q ) ;
            tr[ where ].l = tr.size ( ) - 1 ;
        }
        update ( tr[ where ].l , IL , mid , pos ) ;
    }
    else {
    	if ( tr[ where ].r == 0 ) {
        	tr.push_back ( q ) ;
            tr[ where ].r = tr.size ( ) - 1 ;
        }
        update ( tr[ where ].r , mid + 1 , IR , pos ) ;
    }
}

int query ( int where , int IL , long long IR , long long CURL , int CURR ) {
	if ( CURR < IL || IR < CURL ) { return 0 ; }
    if ( CURL <= IL && IR <= CURR ) {
    	return tr[ where ].val ;
    }
    long long mid = IL ;
    mid += IR ;
    mid /= 2 ;
    int ret = 0 ;
    if ( tr[ where ].l != 0 ) { ret += query ( tr[ where ].l , IL , mid , CURL , CURR ) ; }
    if ( tr[ where ].r != 0 ) { ret += query ( tr[ where ].r , mid + 1 , IR , CURL , CURR ) ; }
    return ret ;
}

void input ( ) {
	scanf ( "%d" , &n ) ;
    int i ;
	int p , q ;
    struct tuhla u ;
    LEAVES = 1 ;
    while ( LEAVES < 2e9 ) { LEAVES *= 2 ; }
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d%d" , &p , &q ) ;
      	p += ( 1e9 + 1 ) ;
        q += ( 1e9 + 1 ) ;
        u.x = p ;
        u.y = q ;
        u.id = i ;
        u.type = 1 ;
        v.push_back ( u ) ;
    }
    sort ( v.begin ( ) , v.end ( ) , cmp ) ;
}

void solve ( ) {
	tr.resize ( 2 ) ;
	int i ;
    int br = 0 ;
    for ( i = 0 ; i < n ; i ++ ) {
    	ans[ v[ i ].id ] = query ( 1 , 1 , LEAVES , v[ i ].x , v[ i ].y ) ;
        update ( 1 , 1 , LEAVES , v[ i ].x ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
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
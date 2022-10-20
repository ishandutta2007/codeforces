#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
#include<set>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;
int q ;
int st[ MAXN ] , en[ MAXN ] ;
int num[ MAXN ] ;

int ans[ MAXN ] ;

vector < int > v[ MAXN ] ;
vector < int > h[ MAXN ] ;
int lo[ MAXN ] ;
int hi[ MAXN ] ;

map < int , int > ZX ;
map < int , int > REVZX ;

int MAXNUM ;
int LEAVES ;

struct node {
	int mx ;
	int tot ;
	int pref ;
    int suff ;
    node ( ) { mx = pref = suff = 0 ; tot = 1 ; }
    node ( int val ) { mx = pref = suff = val ; tot = 1 ; }
};

node merge ( node p1 , node p2 ) {
	node ret = node ( 0 ) ;
    ret.tot = p1.tot + p2.tot ;
    if ( p1.pref == p1.tot ) { ret.pref = p1.pref + p2.pref ; }
    else { ret.pref = p1.pref ; }
    if ( p2.suff == p2.tot ) { ret.suff = p2.suff + p1.suff ; }
    else { ret.suff = p2.suff ; }
    ret.mx = max ( p1.mx , p2.mx ) ;
    ret.mx = max ( ret.mx , p1.suff + p2.pref ) ;
    return ret ;
}

struct segment_tree {
	node tr[ 10 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
    	if ( IL == IR ) {
        	tr[ where ] = node ( 0 ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    void update ( int where , int IL , int IR , int pos ) {
    	if ( IL > IR ) { return ; }
    	if ( pos < IL || IR < pos ) { return ; }
        if ( IL == IR && IL == pos ) {
        	tr[ where ] = node ( 1 ) ;
            return ;
        }
       	int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , pos ) ;
        update ( 2 * where + 1 , mid + 1 , IR , pos ) ;
        tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    node query ( int where , int IL , int IR , int CURL , int CURR ) {
    	if ( IL > IR ) { return node ( 0 ) ; }
    	if ( CURR < IL || IR < CURL ) { return node ( 0 ) ; }
		if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        node ret = query ( 2 * where , IL , mid , CURL , CURR ) ;
        ret = merge ( ret , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
        return ret ;
    }
};

segment_tree w ;

void input ( ) {
	scanf ( "%d" , &n ) ;
    LEAVES = 1 ;
    while ( LEAVES < n ) { LEAVES *= 2 ; }
    int i ;
    vector < int > srt ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d" , &a[ i ] ) ;
        srt.push_back ( a[ i ] ) ;
    }
    scanf ( "%d" , &q ) ;
    for ( i = 1 ; i <= q ; i ++ ) {
    	scanf ( "%d%d%d" , &st[ i ] , &en[ i ] , &num[ i ] ) ;
    }
    sort ( srt.begin ( ) , srt.end ( ) ) ;
    int sz = srt.size ( ) ;
    ZX[ srt[ 0 ] ] = 1 ;
    REVZX[ 1 ] = srt[ 0 ] ;
    MAXNUM = 2 ;
    for ( i = 1 ; i < sz ; i ++ ) {
    	if ( srt[ i ] == srt[ i - 1 ] ) { continue ; }
        ZX[ srt[ i ] ] = MAXNUM ;
        REVZX[ MAXNUM ] = srt[ i ] ;
        MAXNUM ++ ;
    }
    MAXNUM -- ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	a[ i ] = ZX[ a[ i ] ] ;
        v[ a[ i ] ].push_back ( i ) ;
    }
}

void solve ( ) {
	int i , j , t ;
    int sz ; 
    for ( i = 1 ; i <= q ; i ++ ) {
    	lo[ i ] = 1 ;
        hi[ i ] = MAXNUM ;
    }
    for ( i = 1 ; i <= 18 ; i ++ ) {
    	w.init ( 1 , 1 , LEAVES ) ;
        for ( j = 1 ; j <= MAXNUM ; j ++ ) { h[ j ].clear ( ) ; }
        for ( j = 1 ; j <= q ; j ++ ) {
        	int val = ( lo[ j ] + hi[ j ] ) / 2 ;
            h[ val ].push_back ( j ) ;
        }
        for ( j = MAXNUM ; j >= 1 ; j -- ) {
        	sz = v[ j ].size ( ) ;
        	for ( t = 0 ; t < sz ; t ++ ) { w.update ( 1 , 1 , LEAVES , v[ j ][ t ] ) ; }
            sz = h[ j ].size ( ) ;
            for ( t = 0 ; t < sz ; t ++ ) {
            	int val = w.query ( 1 , 1 , LEAVES , st[ h[ j ][ t ] ] , en[ h[ j ][ t ] ] ).mx ;
                if ( val >= num[ h[ j ][ t ] ] ) {
                	ans[ h[ j ][ t ] ] = j ;
                    lo[ h[ j ][ t ] ] = j + 1 ;
                }
                else {
                	hi[ h[ j ][ t ] ] = j - 1 ;
                }
            }
        }
    }
    for ( i = 1 ; i <= q ; i ++ ) {
    	printf ( "%d\n" , REVZX[ ans[ i ] ] ) ;
    }
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
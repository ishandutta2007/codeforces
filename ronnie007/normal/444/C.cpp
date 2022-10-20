#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<map>
using namespace std ;

#define MAXN 100007

int n , q ;

int LEAVES ;

struct node {
	long long sm , lazy ;
    int cur ;
	node ( ) { sm = cur = lazy = 0 ; }
	node ( int x ) {
    	sm = 0 ;
        cur = x ;
        lazy = 0 ;
    }
};

node merge ( node p1 , node p2 ) {
	node ret = node ( 0 ) ;
    ret.sm = ( p1.sm + p2.sm ) ;
    if ( p1.cur != p2.cur ) { ret.cur = 0 ; }
    else { ret.cur = p1.cur ; }
    ret.lazy = 0 ;
    return ret ;
}

struct segment_tree {
	node tr[ 6 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
    	if ( IL == IR ) {
        	tr[ where ] = node ( IL ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    void push_lazy ( int where , int IL , int IR ) {
    	if ( tr[ where ].lazy == 0 ) { return ; }
		tr[ where ].sm += tr[ where ].lazy * ( IR - IL + 1 ) ;
		if ( IL != IR ) {
        	if ( tr[ where ].cur != 0 ) { tr[ 2 * where ].cur = tr[ 2 * where + 1 ].cur = tr[ where ].cur ; }
            tr[ 2 * where ].lazy += tr[ where ].lazy ;
            tr[ 2 * where + 1 ].lazy += tr[ where ].lazy ;
		}
		tr[ where ].lazy = 0 ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR , long long val ) {
    	if ( IL > IR ) { return ; }
        push_lazy ( where , IL , IR ) ;		
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR && tr[ where ].cur > 0 ) {
        	tr[ where ].lazy = abs ( val - tr[ where ].cur ) ;
            tr[ where ].cur = val ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2;
        update ( 2 * where , IL , mid , CURL , CURR , val ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
        tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    node query ( int where , int IL , int IR , int CURL , int CURR ) {
    	if ( IL > IR ) { return node ( 0 ) ; }
        push_lazy ( where , IL , IR ) ;		
        if ( IR < CURL || CURR < IL ) { return node ( 0 ) ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return merge ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};

segment_tree w ;


void input ( ) {
	cin >> n >> q ;
    LEAVES = 1 ;
    while ( LEAVES < n ) { LEAVES *= 2 ; }
	w.init ( 1 , 1 , LEAVES ) ;
}

void solve ( ) {
	int type , x , y , z ;
	while ( q != 0 ) {
    	q -- ;
		cin >> type ;
        if ( type == 1 ) {
			cin >> x >> y >> z ;
            w.update ( 1 , 1 , LEAVES , x , y , z ) ;
        }
        else {
        	cin >> x >> y ;
            cout << w.query ( 1 , 1 , LEAVES , x , y ).sm << "\n" ;
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
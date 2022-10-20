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

#define MAXN 400007

int n , m ;
int a[ MAXN ] ;
int lst[ MAXN ] ;

vector < pair < int , int > > v[ MAXN ] ;

map < int , int > ZX ;

int MAXNUM ;

int ans[ MAXN ] ;

struct node {
	int ans ;
    int inc , dec ;
	node ( ) { ans = inc = dec = 0 ; }
    node ( int val ) { ans = inc = dec = val ; }
};


struct tree {
	node tr[ 10 * MAXN ] ;
	node merge ( node p1 , node p2 ) {
    	node ret = node ( 0 ) ;
        ret.ans = max ( p1.ans , p2.ans ) ;
        ret.ans = max ( ret.ans , p1.dec + p2.inc ) ;
        ret.inc = max ( p1.inc , p2.inc ) ;
        ret.dec = max ( p1.dec , p2.dec ) ;
        return ret ;
    }
    void init ( int where , int IL , int IR ) {
    	if ( IL == IR ) {
        	tr[ where ] = node ( ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    void update_inc ( int where , int IL , int IR , int pos , int val ) {
    	if ( IL > IR ) { return ; }
    	if ( pos < IL || IR < pos ) { return ; }
        if ( IL == IR && IL == pos ) {
        	tr[ where ].inc = val ;
            tr[ where ].ans = 1 ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update_inc ( 2 * where , IL , mid , pos , val ) ;
        update_inc ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
        tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    void update_dec ( int where , int IL , int IR , int pos , int val ) {
    	if ( IL > IR ) { return ; }
        if ( pos < IL || IR < pos ) { return ; }
        if ( IL == IR && IL == pos ) {
        	tr[ where ].dec = val ;
            tr[ where ].ans = 1 ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update_dec ( 2 * where , IL , mid , pos , val ) ;
        update_dec ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
        tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    node query ( int where , int IL , int IR , int CURL , int CURR ) {
    	if ( IL > IR ) { return node ( ) ; }
        if ( CURR < IL || IR < CURL ) { return node ( ) ; }
        if ( CURL <= IL && IR <= CURR ) {
        	return tr[ where ] ;
        }
        int mid = ( IL + IR ) / 2 ;
        return merge ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};
tree w ;
void f ( ) {
	vector < int > srt ;
    int i , j ;
    srt.clear ( ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	srt.push_back ( a[ i ] ) ;
        int sz = v[ i ].size ( ) ;
        for ( j = 0 ; j < sz ; j ++ ) {
        	srt.push_back ( v[ i ][ j ].first ) ;
        }
    }
    sort ( srt.begin ( ) , srt.end ( ) ) ;
    ZX[ srt[ 0 ] ] = 1 ;
    int id = 2 ;
    int sz = srt.size ( ) ;
    for ( i = 1 ; i < sz ; i ++ ) {
    	if ( srt[ i ] == srt[ i - 1 ] ) { continue ; }
        ZX[ srt[ i ] ] = id ;
        id ++ ;
    }
    while ( (id&(id-1)) != 0 ) { id ++ ; }
    MAXNUM = id ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	a[ i ] = ZX[ a[ i ] ] ;
        sz = v[ i ].size ( ) ;
        for ( j = 0 ; j < sz ; j ++ ) {
        	v[ i ][ j ].first = ZX[ v[ i ][ j ].first ] ;	
        }
    }
}

void input ( ) {
	scanf ( "%d%d" , &n , &m ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d" , &a[ i ] ) ;
    }
    for ( i = 1 ; i <= m ; i ++ ) {
    	int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( make_pair ( y , i ) ) ;
    }
}

void solve ( ) {
	f ( ) ; 
	w.init ( 1 , 1 , MAXNUM ) ;   
    int i , j ;
    for ( i = n ; i >= 1 ; i -- ) {
        lst[ i ] = w.query ( 1 , 1 , MAXNUM , a[ i ] , a[ i ] ).inc ;    
    	int val = w.query( 1 , 1 , MAXNUM , a[ i ] + 1 , MAXNUM ).inc + 1 ;
        w.update_inc( 1 , 1 , MAXNUM , a[ i ] , val ) ;
    }
    int g = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	w.update_inc ( 1 , 1 , MAXNUM , a[ i ] , lst[ i ] ) ;

        node h = w.tr[ 1 ] ;
		g = max ( h.inc , h.dec ) ;
        g = max ( g , h.ans ) ;
        int sz = v[ i ].size ( ) ;
        for ( j = 0 ; j < sz ; j ++ ) {
        	int val = w.query ( 1 , 1 , MAXNUM , 1 , v[ i ][ j ].first - 1 ).dec + w.query ( 1 , 1 , MAXNUM , v[ i ][ j ].first + 1 , MAXNUM ).inc + 1 ;
            ans[ v[ i ][ j ].second ] = max ( val , g ) ;
        }
    	int val = w.query ( 1 , 1 , MAXNUM , 1 , a[ i ] - 1 ).dec + 1 ;
        w.update_dec( 1 , 1 , MAXNUM , a[ i ] , val ) ;
    }
    for ( i = 1 ; i <= m ; i ++ ) {
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
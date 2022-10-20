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

int n , k ;
vector < pair < int , int > > v[ MAXN ] ;

int used[ MAXN ] ;

vector < int > u[ 2 * MAXN ] ;

bool dfs ( int vertex , int x , int y , int val ) {
	int i , sz ;
    sz = v[ vertex ].size ( ) ;
    if ( used[ vertex ] == 0 ) { used[ vertex ] = x ; }
    u[ used[ vertex ] ].push_back ( vertex ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
		int h = v[ vertex ][ i ].first ;
    	if ( v[ vertex ][ i ].second == val ) {
	        if ( used[ h ] != 0 && used[ h ] != used[ vertex ] ) { return false ; }
    	    if ( used[ h ] != 0 ) { continue ; }
        	used[ h ] = used[ vertex ] ;
	        bool g = dfs ( h , x , y , val ) ;
    	    if ( g == false ) { return false ; }        
		}
		else {
	        if ( used[ h ] == used[ vertex ] ) { return false ; }
    	    if ( used[ h ] != 0 ) { continue ; }
        	used[ h ] = ( x + y - used[ vertex ] ) ;
	        bool g = dfs ( h , x , y , val ) ;
    	    if ( g == false ) { return false ; }
		}
    }
    return true ;
}

vector < int > pos ( int val ) {
	vector < int > ret ;
    vector < int > bait ;
    ret.clear ( ) ;
    bait.clear ( ) ;
	int i , j ;
    for ( i = 1 ; i <= 2 * n ; i ++ ) { bait.push_back ( 1 ) ; }
    for ( i = 1 ; i <= n ; i ++ ) {
    	used[ i ] = 0 ;
    }
    for ( i = 1 ; i <= 2 * n ; i ++ ) {
    	u[ i ].clear ( ) ;
    }
    int id = 1 ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	if ( used[ i ] == 0 ) {
        	if ( dfs ( i , id , id + 1 , val ) == false ) { return bait ; }
            id += 2 ;
        }
    }
    id -- ;
    id /= 2 ;
    for ( i = 1 ; i <= id ; i ++ ) {
    	if ( u[ 2 * i - 1 ].size ( ) == 0 && u[ 2 * i ].size ( ) == 0 ) { continue ; }
		if ( u[ 2 * i - 1 ].size ( ) > u[ 2 * i ].size ( ) ) { swap ( u[ 2 * i - 1 ] , u[ 2 * i ] ) ; }
        int sz = u[ 2 * i - 1 ].size ( ) ;
        for ( j = 0 ; j < sz ; j ++ ) {
        	ret.push_back ( u[ 2 * i - 1 ][ j ] ) ;
        }
    }
    return ret ;
}

void input ( ) {
	cin >> n >> k ;
    int x , y , z ;
    char c ;
    int i ;
    for ( i = 1 ; i <= k ; i ++ ) {
    	cin >> x >> y >> c ;
        if ( c == 'R' ) { z = 0 ; }
        else { z = 1 ; }
        v[ x ].push_back ( make_pair ( y , z ) ) ;
        v[ y ].push_back ( make_pair ( x , z ) ) ;
    }
}

void solve ( ) {
	int i , sz ;
	vector < int > v1 , v2 ;
    v1 = pos ( 0 ) ;
    v2 = pos ( 1 ) ;
    if ( v1.size ( ) > v2.size ( ) ) { swap ( v1 , v2 ) ; }
    sz = v1.size ( ) ;
    if ( sz > n ) {	printf ( "-1\n" ) ; return ; }
    printf ( "%d\n" , sz ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
    	printf ( "%d" , v1[ i ] ) ;
        if ( i == ( sz - 1 ) ) { printf ( "\n" ) ; }
        else { printf ( " " ) ; }
    }
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
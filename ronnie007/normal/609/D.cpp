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

#define inf 1000000007
#define MAXN 200007

int n , m , k ;
long long s ;
long long a[ MAXN ] ;
long long b[ MAXN ] ;
vector < pair < long long , int > > p[ 2 ] ;
int id1 , id2 ;
vector < int > v ;
pair < int , int > init[ MAXN ] ;

bool f ( int x ) {
	int i ;
    id1 = id2 = 0 ;
    v.clear ( ) ;
    for ( i = 1 ; i <= x ; i ++ ) {
    	if ( a[ i ] < a[ id1 ] ) { id1 = i ; }
        if ( b[ i ] < b[ id2 ] ) { id2 = i ; }
    }
	long long cur = 0 ;
    int w1 , w2 ;
    w1 = w2 = 0 ;
    while ( w1 + w2 < k ) {
    	if ( cur > s ) { return false ; }
		if ( w1 == p[ 0 ].size ( ) ) {
        	cur += b[ id2 ] * p[ 1 ][ w2 ].first ;
            v.push_back ( p[ 1 ][ w2 ].second ) ;            
            w2 ++ ;
        }
        else if ( w2 == p[ 1 ].size ( ) ) {
        	cur += a[ id1 ] * p[ 0 ][ w1 ].first ;
            v.push_back ( p[ 0 ][ w1 ].second ) ;            
            w1 ++ ;
        }
        else {
        	if ( a[ id1 ] * p[ 0 ][ w1 ].first <= b[ id2 ] * p[ 1 ][ w2 ].first ) {
    	    	cur += a[ id1 ] * p[ 0 ][ w1 ].first ;
	            v.push_back ( p[ 0 ][ w1 ].second ) ;                            
	            w1 ++ ;            	
            }
            else {
    	    	cur += b[ id2 ] * p[ 1 ][ w2 ].first ;
	            v.push_back ( p[ 1 ][ w2 ].second ) ;                            
	            w2 ++ ;            
            }
        }
    }
    if ( cur > s ) { return false ; }
    return true ;
}

void input ( ) {
    cin >> n >> m >> k >> s ;
    int i ;
    a[ 0 ] = b[ 0 ] = inf ;
    for ( i = 1 ; i <= n ; i ++ ) {
        cin >> a[ i ] ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        cin >> b[ i ] ;
    }    
    for ( i = 1 ; i <= m ; i ++ ) {
	    int x , y ;
		cin >> x >> y ;
        init[ i ] = make_pair ( x , y ) ;
        x -- ;
        p[ x ].push_back ( make_pair ( y , i ) ) ;
    }
    sort ( p[ 0 ].begin ( ) , p[ 0 ].end ( ) ) ;
    sort ( p[ 1 ].begin ( ) , p[ 1 ].end ( ) ) ;
}

void solve ( ) {
	int l , r , mid ;
    l = 1 ;
    r = n ;
    if ( f ( r ) == false ) { printf ( "-1\n" ) ; return ; }
    while ( r - l > 3 ) {
    	mid = ( l + r ) / 2 ;
        if ( f ( mid ) == true ) { r = mid ; }
        else { l = mid ; }
    }
    while ( f ( l ) == false ) { l ++ ; }
    printf ( "%d\n" , l ) ;
    int i ;
    for ( i = 0 ; i < k ; i ++ ) {
    	if ( init[ v[ i ] ].first == 1 ) { printf ( "%d %d\n" , v[ i ] , id1 ) ; }
        else { printf ( "%d %d\n" , v[ i ] , id2 ) ; }
    }
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
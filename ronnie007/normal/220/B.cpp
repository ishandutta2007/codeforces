#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std ;

#define MAXN 100007

int n , k ;
int a[ MAXN ] ;
int br[ MAXN ] ;
int ans[ MAXN ] ;
int sqr ;
int cur = 0 ; 
struct tuhla {
	int st , en ;
    int id ;
};

bool cmp ( struct tuhla p1 , struct tuhla p2 ) {
	if ( ( p1.st / sqr ) != ( p2.st / sqr ) ) { return ( p1.st < p2.st ) ; }
    return ( p1.en < p2.en ) ;
}

vector < struct tuhla > v ;

void add ( int x ) {
	if ( x > n ) { return ; }
    br[ x ] ++ ;
    if ( br[ x ] == ( x + 1 ) ) { cur -- ; }
    if ( br[ x ] == x ) { cur ++ ; }
}

void remove ( int x ) {
	if ( x > n ) { return ; }
    br[ x ] -- ;
    if ( br[ x ] == ( x - 1 ) ) { cur -- ; }
    if ( br[ x ] == x ) { cur ++ ; }
}

void input ( ) {
	scanf ( "%d%d" , &n , &k ) ;
    sqr = sqrt ( n ) ;
    int i ;
    v.resize ( k ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d" , &a[ i ] ) ;
    }
    for ( i = 0 ; i < k ; i ++ ) {
    	scanf ( "%d%d" , &v[ i ].st , &v[ i ].en ) ;
        v[ i ].id = i + 1 ;
    }
    sort ( v.begin ( ) , v.end ( ) , cmp ) ;
}

void solve ( ) {
	int i , l , r ;
    l = v[ 0 ].st ;
    r = v[ 0 ].en ;
    for ( i = l ; i <= r ; i ++ ) {
    	add ( a[ i ] ) ;
    }
    ans[ v[ 0 ].id ] = cur ;
    for ( i = 1 ; i < k ; i ++ ) {
    	while ( l > v[ i ].st ) { l -- ; add ( a[ l ] ) ; }
        while ( l < v[ i ].st ) { remove ( a[ l ] ) ; l ++ ; }

        while ( r > v[ i ].en ) { remove ( a[ r ] ) ; r -- ; }
        while ( r < v[ i ].en ) { r ++ ; add ( a[ r ] ) ; }
        
        ans[ v[ i ].id ] = cur ; 
    }
    for ( i = 1 ; i <= k ; i ++ ) {
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
#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std ;

#define MAXN 100007

int n , k , m ;
int a[ MAXN ] ;

long long cur = 0 ;
int br[ 20 * MAXN ] ;
long long ans[ MAXN ] ;
int pref[ MAXN ] ;

int u ;

struct tuhla {
	int st , en ;
	int id ;
};
struct tuhla q[ 3 * MAXN ] ;

bool cmp ( struct tuhla p1 , struct tuhla p2 ) {
	if ( ( p1.st / u ) != ( p2.st / u ) ) { return ( ( p1.st / u ) < ( p2.st / u ) ) ; }
	return ( p1.en < p2.en ) ;
}

void add ( int x , int mul ) {
		if ( mul == -1 ) { br[ x ] += mul ; }
		cur += ( mul * br[ ( x ^ k ) ] ) ;
		if ( mul == 1 ) { br[ x ] += mul ; }
}

void input ( ) {
	scanf ( "%d%d%d" , &n , &m , &k ) ;
	u = 1 ;
	while ( u * u <= n ) { u ++ ; }
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
		pref[ i ] = ( pref[ i - 1 ] ^a[ i ] ) ;
	}
	for ( i = 1 ; i <= m ; i ++ ) {
		scanf ( "%d%d" , &q[ i ].st , &q[ i ].en ) ;
		q[ i ].id = i ;
	}
	sort ( q + 1 , q + m + 1 , cmp ) ;
}

void solve ( ) {
	int i ;
	int l , r ;
	l = q[ 1 ].st ; 
	r = q[ 1 ].en ;
	for ( i = l ; i <= r ; i ++ ) {
		add ( pref[ i - 1 ] , 1 ) ;
	}
	add ( pref[ r ] , 1 ) ;
	ans[ q[ 1 ].id ] = cur ;
	for ( i = 2 ; i <= m ; i ++ ) {
		while ( l > q[ i ].st ) { l -- ; add ( pref[ l - 1 ] , 1 ) ; }
		while ( l < q[ i ].st ) { add ( pref[ l - 1 ] , -1 ) ; l ++ ; }
		
		while ( r < q[ i ].en ) { r ++ ; add ( pref[ r ] , 1 ) ; }
		while ( r > q[ i ].en ) { add ( pref[ r ] , -1 ) ; r -- ; }
		ans[ q[ i ].id ] = cur ;
	}
	for ( i = 1 ; i <= m ; i ++ ) {
		printf ( "%I64d\n" , ans[ i ] ) ;
	}
}

int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
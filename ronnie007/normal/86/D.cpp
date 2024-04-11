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

int n , q ;
long long a[ MAXN ] ;

long long ans[ MAXN ] ;

struct tuhla {
	int first , second ;
	int id ;
};
struct tuhla h[ MAXN ] ;

int br[ 10 * MAXN ] ;
long long sm = 0 ;

bool cmp ( struct tuhla p1 , struct tuhla p2 ) {
	int w1 , w2 ;
	w1 = ( p1.first / ( sqrt ( n ) ) ) ;
	w2 = ( p2.first / ( sqrt ( n ) ) ) ;
	if ( w1 == w2 ) {
		return ( p1.second > p2.second ) ;
	}
	else {
		return ( p1.first < p2.first ) ;
	}
}

void add ( long long val , int u ) {
	sm += u * ( val * ( br[ val ] + br[ val ] + u ) ) ;
	br[ val ] += u ;
}

void input ( ) {
	cin >> n >> q ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		cin >> a[ i ] ;
	}
	for ( i = 1 ; i <= q ; i ++ ) {
		cin >> h[ i ].first >> h[ i ].second ;
		h[ i ].id = i ;
	}
	sort ( h + 1 , h + q + 1 , cmp ) ;
}

void solve ( ) {
	int i ;
	for ( i = h[ 1 ].first ; i <= h[ 1 ].second ; i ++ ) {
		add ( a[ i ] , 1 ) ;
	}
	int l = h[ 1 ].first ;
	int r = h[ 1 ].second ;
	for ( i = 1 ; i <= q ; i ++ ) {
		while ( r < h[ i ].second ) {
			r ++ ;
			add ( a[ r ] , 1 ) ;
		}
		while ( r > h[ i ].second ) {
			add ( a[ r ] , -1 ) ;
			r -- ;
		}
		while ( l < h[ i ].first ) {
			add ( a[ l ] , -1 ) ;
			l ++ ;
		}
		while ( l > h[ i ].first ) {
			l -- ;
			add ( a[ l ] , 1 ) ;
		}
		ans[ h[ i ].id ] = sm ;
	}
	for ( i = 1 ; i <= q ; i ++ ) {
		cout << ans[ i ] << "\n" ;
	}
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
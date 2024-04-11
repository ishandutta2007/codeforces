#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
#include<set>
#include<stack>
using namespace std ;

#define MAXN 100007
#define LIMIT 100002

int n , m ;

struct tuhla {
	int len ;
	int used ;
	int id ;
};

struct tuhla a[ MAXN ] ;

bool cmp ( struct tuhla p1 , struct tuhla p2 ) {
	if ( p1.len != p2.len ) { return ( p1.len < p2.len ) ; }
	return ( p1.used > p2.used ) ;
}

pair < int , int > ans[ MAXN ] ;
pair < int , int > lft[ MAXN ] ;



void input ( ) ;
void solve ( ) ;

int main ( )  {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%d%d" , &n , &m ) ;
	int i ;
	for ( i = 1 ; i <= m ; i ++ ) {
		scanf ( "%d%d" , &a[ i ].len , &a[ i ].used ) ;
		a[ i ].id = i ;
	}
	sort ( a + 1 , a + m + 1 , cmp ) ;
}

void solve ( ) {
	int i , j ;
	int tot = 1 ;
	int cur = 1 ;
	int br = 1 ;
	for ( i = 1 ; i <= m ; i ++ ) {
		if ( a[ i ].used == 1 ) {
			ans[ a[ i ].id ].first = br ;
			ans[ a[ i ].id ].second = br + 1 ;
			br ++ ;
			for ( j = 1 ; j < br - 1 ; j ++ ) {
				if ( tot >= LIMIT ) { break ; }
				lft[ tot ].first = j ;
				lft[ tot ].second = br ;
				tot ++ ;
			}
		}
		else { 
			if ( cur == tot ) { printf ( "-1\n" ) ; return ; }
			ans[ a[ i ].id ].first = lft[ cur ].first ;
			ans[ a[ i ].id ].second = lft[ cur ].second ;
			cur ++ ;
		}
	}
	for ( i = 1 ; i <= m ; i ++ ) {
		printf ( "%d %d\n" , ans[ i ].first , ans[ i ].second ) ;
	}
}
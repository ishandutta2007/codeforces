#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
using namespace std ;

#define MAXN 200007

int n ;
int sz ;
pair < int , int > a[ MAXN ] ;

map < pair < int , int > , int > good ;

map < pair < int , int > , int > used ;

struct tuhla {
	long long first , second ;
	int id ;
};

struct tuhla hull[ MAXN ] ;

int nxt[ MAXN ] ;
int prv[ MAXN ] ;

bool f ( struct tuhla p1 , struct tuhla p2 ) {
	if ( p1.first != p2.first ) {
		return ( p1.first > p2.first ) ;
	}
	return ( p1.second > p2.second ) ;
}

int det ( struct tuhla p1 , struct tuhla p2 , struct tuhla p3 ) {
	//int k = ( p1.first * p2.second + p1.second * p3.first + p2.first * p3.second ) ;
	//k -= ( p3.first * p2.second + p3.second * p1.first + p2.first * p1.second ) ;
	//k = -k ;
	long long k = ( p1.second * p2.first * p3.first * p3.second +
					p1.first * p2.first * p2.second * p3.second + 
					p1.first * p1.second * p2.second * p3.first ) ;
	k -= ( p3.second * p2.first * p1.first * p1.second +
					p3.first * p2.first * p2.second * p1.second + 
					p3.first * p3.second * p2.second * p1.first ) ;
	if ( k > 0 ) { return 1 ; }
	if ( k < 0 ) { return -1 ; }
	return 0 ;
}

void input ( ) ;
void solve ( ) ;

int main ( )  {
    ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	sz = 0 ;
	for ( i = 0 ; i < n ; i ++ ) {
		scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
		if ( used[ make_pair ( a[ i ].first , a[ i ].second ) ] == 1 ) { continue ; }

		hull[ sz ].first = a[ i ].first ;
		hull[ sz ].second = a[ i ].second ;
		hull[ sz ].id = i + 1 ;
		sz ++ ;
		used[ make_pair ( a[ i ].first , a[ i ].second ) ] = 1 ; 
    }
}

void solve ( ) {
	sort ( hull , hull + sz , f ) ;
	int i ;
	// next -- counter-clockwise
	// prev -- clockwise	
	if ( sz == 1 ) {
		good[ make_pair ( hull[ 0 ].first , hull[ 0 ].second ) ] = 1 ;
		
    }
	if ( sz == 2 ) {
		good[ make_pair ( hull[ 0 ].first , hull[ 0 ].second ) ] = 1 ;
		good[ make_pair ( hull[ 1 ].first , hull[ 1 ].second ) ] = 1 ;
    }
	if ( sz <= 2 ) {
		vector < int > ans ;
		int i ;
		for ( i = 0 ; i < n ; i ++ ) {
			if ( good[ make_pair ( a[ i ].first , a[ i ].second ) ] == 1 ) { ans.push_back ( i + 1 ) ; }
	    }
		sort ( ans.begin ( ) , ans.end ( ) ) ;
		int psz = ans.size ( ) ;
		for ( i = 0 ; i < psz ; i ++ ) {
			printf ( "%d" , ans[ i ] ) ;
			if ( i == psz - 1 ) { printf ( "\n" ) ; }
			else { printf ( " " ) ; }
	    }
		return ;
    }
	if ( det ( hull[ 0 ] , hull[ 1 ] , hull[ 2 ] ) < 0 ) {
		nxt[ 0 ] = 2 ;
		nxt[ 2 ] = 1 ;
		nxt[ 1 ] = 0 ;

		prv[ 0 ] = 1 ;
		prv[ 1 ] = 2 ;
		prv[ 2 ] = 0 ;
    }
	else {
		nxt[ 0 ] = 1 ;
		nxt[ 1 ] = 2 ;
		nxt[ 2 ] = 0 ;

		prv[ 0 ] = 2 ;
		prv[ 2 ] = 1 ;
		prv[ 1 ] = 0 ;
    }
	int id1 , id2 ;
	for ( i = 3 ; i < sz ; i ++ ) {
		id1 = i - 1 ;
		id2 = i - 1 ;
		//if ( hull[ i ].first == hull[ i - 1 ].first && hull[ i ].second == hull[ i - 1 ].second ) { continue ; }
		while ( det ( hull[ i ] , hull[ id1 ] , hull[ nxt[ id1 ] ] ) < 0 ) {
			id1 = nxt[ id1 ] ;
        }
		while ( id1 == id2 || det ( hull[ i ] , hull[ id2  ] , hull[ prv[ id2 ] ] ) > 0 ) {
			id2 = prv[ id2 ] ;
        }
		nxt[ i ] = id1 ;
		prv[ i ] = id2 ;
		nxt[ id2 ] = i ;
		prv[ id1 ] = i ;
    }

	vector < int > ans ;
	ans.clear ( ) ;
	int h = 0 ;
	good[ make_pair ( hull[ 0 ].first , hull[ 0 ].second ) ] = 1 ;
	while ( 1 ) {
		h = nxt[ h ] ;
		//printf ( "%d\n" , h ) ;
		if ( hull[ h ].second < hull[ prv[ h ] ].second ) { break ; }
		if ( hull[ h ].second == hull[ prv[ h ] ].second && hull[ h ].first != hull[ prv[ h ] ].first ) { break ; }
		if ( h == 0 ) { break ; }
		good[ make_pair ( hull[ h ].first , hull[ h ].second ) ] = 1 ;
		//ans.push_back ( hull[ h ].id ) ;
    }
	for ( i = 0 ; i < n ; i ++ ) {
		if ( good[ make_pair ( a[ i ].first , a[ i ].second ) ] == 1 ) { ans.push_back ( i + 1 ) ; }
    }
	sort ( ans.begin ( ) , ans.end ( ) ) ;
	int psz = ans.size ( ) ;
	for ( i = 0 ; i < psz ; i ++ ) {
		printf ( "%d" , ans[ i ] ) ;
		if ( i == psz - 1 ) { printf ( "\n" ) ; }
		else { printf ( " " ) ; }
    }
}
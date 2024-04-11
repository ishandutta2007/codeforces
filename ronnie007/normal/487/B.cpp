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
using namespace std ;

#define MAXN 100007

int n , s , l ;
int a[ MAXN ] ;

struct tuhla {
	int mx , mn ;
};

struct tuhla tr[ 5 * MAXN  ] ;
int dp[ MAXN ] ;

int LEAVES ;
int g ;

int v[ MAXN ] ;
set < int > p ;

int totmx ;
int totmn ;


void add ( int where , int val , bool fl ) {
	if ( where == 0 ) return ;
	if ( fl == true ) tr[ where ].mn = min ( tr[ where ].mn , val ) ;
	else tr[ where ].mx = max ( tr[ where ].mx , val ) ;
	add ( where / 2 , val , fl ) ;
}

void f ( int where , int IL , int IR , int CURL , int CURR ) {
	if ( IL == CURL && IR == CURR ) {
		totmx = max ( totmx , tr[ where ].mx ) ;
		totmn = min ( totmn , tr[ where ].mn ) ;
		return ;
    }
	int mid = ( IL + IR ) / 2 ;
	if ( CURL <= mid ) {
		f ( 2 * where , IL , mid , CURL , min ( CURR , mid ) ) ;
    }
	if ( CURR > mid ) {
		f ( 2 * where + 1 , mid + 1 , IR , max ( CURL , mid + 1 ) , CURR ) ;
    }
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


void input ( )  {
	scanf ( "%d%d%d" , &n , &s , &l ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( )  {
	int i , j ;
	set < int >::iterator t ;
	g = 1 ;
	for ( i = 0 ; i < 9 ; i ++ ) {
		g *= 10 ;
    }
	g += 7 ;

	LEAVES = 1 ;
	while ( LEAVES < n ) LEAVES *= 2 ;

	for ( i = 0 ; i <= 2 * LEAVES ; i ++ ) {
		tr[ i ].mn = g ; 
		tr[ i ].mx = -g ;
    }
	for ( i = 1 ; i <= n ; i ++ ) {
		dp[ i ] = -1 ;
		add ( i + LEAVES - 1 , a[ i ] , true ) ;
		add ( i + LEAVES - 1 , a[ i ] , false ) ;
    }
	//lst[ 0 ].push_back ( 0 ) ;
	//p.insert ( 0 ) ;
	dp[ 0 ] = 0 ;
	for ( i = 1 ; i < l ; i ++ ) dp[ i ] = -1 ;

	for ( i = l ; i <= n ; i ++ ) {
		int id = i - l ;
		if ( dp[ id ] != -1 ) {
			v[ dp[ id ] ] = id  ;
			p.insert ( dp[ id ] ) ;
        }
		for ( t = p.begin ( ) ; t != p.end ( ) ; t ++ ) {
			j = v[ *t ] ;
			totmx = -g ;
			totmn = g ;
			f ( 1 , 1 , LEAVES , j + 1 , i ) ;
			if ( totmx - totmn <= s ) {
				dp[ i ] = *t + 1 ;
				break ;
            }
        }
		for ( t = p.begin ( ) ; t != p.end ( ) ; t ++ ) {
			if ( *t < dp[ i ] - 1 ) p.erase ( t ) ;
        }
    }
	printf ( "%d\n" , dp[ n ] ) ;
}
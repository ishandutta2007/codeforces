#include<fstream>
#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
using namespace std ;

int n , m ;
int dp[ 400007 ] ;
int r[ 400007 ] ;
struct tuhla {
	int x , y ;
	int len ;
};

vector < struct tuhla > v ;

bool f ( struct tuhla p1 , struct tuhla p2 ) {
	return ( p1.len < p2.len ) ;
}

struct tuhla make ( int x , int y , int z ) {
	struct tuhla ret ;
	ret.x = x ; ret.y = y ;
	ret.len = z ;
	return ret ;
}

void input ( ) ;
void solve ( ) ;



int main ( )  {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
	scanf ( "%d%d" , &n , &m ) ;
	int i ;
	int x , y , z ;
	for ( i = 0 ; i < m ; i ++ ) {
		scanf ( "%d%d%d" , &x , &y , &z ) ;
		v.push_back ( make ( x , y , z ) ) ;
	}
	sort ( v.begin ( ) , v.end ( ) , f ) ;
}


void solve ( ) {
	int i , j ;
	int ans = -1 ;
	for ( i = 0 ; i < m ; i ++ ) {
		if ( i != 0 && v[ i ].len != v[ i - 1 ].len ) {
			j = i - 1 ;
			while ( j >= 0 && v[ j ].len == v[ i - 1 ].len ) {
				dp[ v[ j ].y ] = max ( dp[ v[ j ].y ] , r[ v[ j ].y ] ) ;
				r[ v[ j ].y ] = -1 ;
				j -- ;
			}
		}
		if ( dp[ v[ i ].y ] < dp[ v[ i ].x ] + 1 && r[ v[ i ].y ] < dp[ v[ i ].x ] + 1 ) { r[ v[ i ].y ] = dp[ v[ i ].x ] + 1 ; ans = max ( ans , r[ v[ i ].y ] ) ; }
	}
	printf ( "%d\n" , ans ) ;
}
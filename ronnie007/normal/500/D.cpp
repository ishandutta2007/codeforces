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
int n ;

struct tuhla {
    int to ;
    int cost ;
    int id ;
};

vector < struct tuhla > v[ MAXN ] ;

int br[ MAXN ] ;
int cst[ MAXN ] ;

int dfs ( int vertex , int par ) {
    int i ;
    int sz = v[ vertex ].size ( ) ;
    int ret = 1 ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ].to == par ) { continue ; }
        br[ v[ vertex ][ i ].id ] += dfs ( v[ vertex ][ i ].to , vertex ) ;
        ret += br[ v[ vertex ][ i ].id ] ;
    }
    return ret ;
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
    scanf ( "%d" , &n ) ;
    int i ;
    struct tuhla u ;
    int x , y , z ;
    for ( i = 1 ; i < n ; i ++ ) {
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        u.to = y ;
        u.cost = z ;
        u.id = i ;
        v[ x ].push_back ( u ) ;
        u.to = x ;
        v[ y ].push_back ( u ) ;
        cst[ i ] = u.cost ;
    }
}

void solve ( ) {
    dfs ( 1 , -1 ) ;
    double st = 0.0000 ;
    double cur ;
    int i ;
    for ( i = 1 ; i < n ; i ++ ) {
        cur = br[ i ] ;
        cur *= ( n - br[ i ] ) ;
        cur = cur * ( n - 2 ) ;
        cur *= cst[ i ] ;
        cur /= n ;
        cur /= ( n - 1 ) ;
        cur /= ( n - 2 ) ;
        cur *= 6.0000 ;
        st += cur ;
    }
    int q ;
    scanf ( "%d" , &q ) ;
    int x , y ;
    while ( q != 0 ) {
        q -- ;
        scanf ( "%d%d" , &x , &y ) ;
        int diff = cst[ x ] - y ;
        cst[ x ] = y ;
        double cur = br[ x ] ;
        cur *= ( n - br[ x ] ) ;
        cur = cur * ( n - 2 ) ;
        cur *= diff ;
        cur /= n ;
        cur /= ( n - 1 ) ;
        cur /= ( n - 2 ) ;
        cur *= 6.0000 ;
        st -= cur ;
        printf ( "%.9lf\n" , st ) ;
    }
}
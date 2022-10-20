#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
using namespace std ;

#define MAXN 100007

int n , m ;
vector < int > v[ MAXN ] ;
int d[ MAXN ] ;
int prv[ MAXN ] ;
int used[ MAXN ] ;
int inst[ MAXN ] ;
vector < int > indset ;
int magic ;

void gen_tr ( int vertex ) {
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( d[ v[ vertex ][ i ] ] == 0 ) {
            d[ v[ vertex ][ i ] ] = d[ vertex ] + 1 ;
            prv[ v[ vertex ][ i ] ] = vertex ;
            gen_tr ( v[ vertex ][ i ] ) ;
        }
    }
}

void print_cycle ( int vertex , int en ) {
    printf ( "2\n%d\n" , d[ vertex ] - en + 1 ) ;
    while ( d[ vertex ] >= en ) {
        printf ( "%d " , vertex ) ;
        vertex = prv[ vertex ] ;
    }
    printf ( "\n" ) ;
}

void dfs ( int vertex ) {
    inst[ vertex ] = 1 ;
    int sz = v[ vertex ].size ( ) ;
    int cnt = 0 ;
    int mn = MAXN ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( inst[ v[ vertex ][ i ] ] == 1 ) {
            ++ cnt ;
            mn = min ( mn , d[ v[ vertex ][ i ] ] ) ;
        }
    }
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( prv[ v[ vertex ][ i ] ] == vertex ) {
            dfs ( v[ vertex ][ i ] ) ;
        }
    }
    if ( cnt >= magic - 1 ) {
        print_cycle ( vertex , mn ) ;
        exit ( 0 ) ;
    }
    else {
        for ( int i = 0 ; i < sz ; ++ i ) {
            if ( used[ v[ vertex ][ i ] ] == 1 ) { break ; }
            if ( i == ( sz - 1 ) ) { indset.push_back ( vertex ) ; used[ vertex ] = 1 ; }
        }
    }    
    inst[ vertex ] = 0 ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    d[ 1 ] = 1 ;
    gen_tr ( 1 ) ;
    magic = int ( sqrt ( n ) ) ;
    while ( magic * magic < n ) { ++ magic ; }
    dfs ( 1 ) ;
    printf ( "1\n" ) ;
    for ( int i = 0 ; i < magic ; ++ i ) {
        printf ( "%d " , indset[ i ] ) ;
    }
    printf ( "\n" ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
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
int a[ MAXN ] ;
vector < int > v[ MAXN ] ;
long long in[ MAXN ] ;
long long out[ MAXN ] ;

long long ans = 0 ;


void update ( int vertex , int nw ) {
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        long long old = in[ v[ vertex ][ i ] ] * out[ v[ vertex ][ i ] ] ;
        -- out[ v[ vertex ][ i ] ] ;
        ++ in[ v[ vertex ][ i ] ] ;
        ans += in[ v[ vertex ][ i ] ] * out[ v[ vertex ][ i ] ] - old ;
        v[ v[ vertex ][ i ] ].push_back ( vertex ) ;
    }
    ans -= in[ vertex ] * out[ vertex ] ;
    out[ vertex ] += in[ vertex ] ;
    in[ vertex ] = 0 ;
    a[ vertex ] = nw ;
    v[ vertex ].clear ( ) ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        if ( x > y ) { swap ( x , y ) ; }
        v[ x ].push_back ( y ) ;
        ++ in[ x ] ;
        ++ out[ y ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        a[ i ] = i ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        ans += in[ i ] * out[ i ] ;
    }
    int q ;
    scanf ( "%d" , &q ) ;
    int tp = n ;
    printf ( "%I64d\n" , ans ) ;
    while ( q -- ) {
        int x ;
        scanf ( "%d" , &x ) ;
        update ( x , ++ tp ) ;
        printf ( "%I64d\n" , ans ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
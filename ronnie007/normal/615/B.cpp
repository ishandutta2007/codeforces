#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std ;

#define MAXN 100007

int n ;
vector < int > v[ MAXN ] ;
long long br[ MAXN ] ;
long long f[ MAXN ] ;

long long dfs ( int vertex ) {
    if ( f[ vertex ] != 0 ) { return f[ vertex ] ; }
    f[ vertex ] = 1 ;
    int i ;
    int sz = v[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] > vertex ) { continue ; }
        f[ vertex ] = max ( f[ vertex ] , 1 + dfs ( v[ vertex ][ i ] ) ) ;
    }
    return f[ vertex ] ;
}

void input ( ) {
    int m ;
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    int x , y ;
    for ( i = 1 ; i <= m ; i ++ ) {
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
        br[ x ] ++ ; br[ y ] ++ ;
    }
}

void solve ( ) {
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) { dfs ( i ) ; }
    long long ans = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) { ans = max ( ans , f[ i ] * br[ i ] ) ; }
    printf ( "%I64d\n" , ans ) ;
}


int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
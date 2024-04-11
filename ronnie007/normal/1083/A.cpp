#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 300007

int n ;
int a[ MAXN ] ;
vector < pair < int , int > > v[ MAXN ] ;

long long f[ MAXN ] ;
long long dp[ MAXN ] ;

void dfs ( int vertex , int prv ) {
    int i ;
    int sz = v[ vertex ].size ( ) ;
    long long mx1 , mx2 ;
    mx1 = mx2 = 0 ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ].first == prv ) { continue ; }
        dfs ( v[ vertex ][ i ].first , vertex ) ;
        long long cur = f[ v[ vertex ][ i ].first ] - v[ vertex ][ i ].second ;
        if ( cur < 0 ) { continue ; }
        cur += a[ vertex ] ;
        if ( mx1 <= cur ) { mx2 = mx1 ; mx1 = cur ; }
        else if ( mx2 <= cur ) { mx2 = cur ; }
    }
    if ( mx1 <= 0 ) { mx1 = a[ vertex ] ; }
    f[ vertex ] = mx1 ;
    if ( mx1 > 0 && mx2 > 0 ) { dp[ vertex ] = mx1 + mx2 - a[ vertex ] ; }
    else { dp[ vertex ] = f[ vertex ] ; }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( i = 1 ; i < n ; i ++ ) {
        int x , y , z ;
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        v[ x ].push_back ( make_pair ( y , z ) ) ;
        v[ y ].push_back ( make_pair ( x , z ) ) ;
    }
}

void solve ( ) {
    dfs ( 1 , -1 ) ;
    long long ans = 0 ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( ans < dp[ i ] ) { ans = dp[ i ] ; }
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
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

#define MAXN 600007
int n , k ;
int f[ MAXN ] ;

long long ans = 0 ;

struct edge {
    int to ;
    int len ;
    edge ( ) { to = len = 0 ; }
    edge ( int _to , int _len ) {
        to = _to ;
        len = _len ;
    }
};


vector < struct edge > v[ MAXN ] ;

long long dp_all[ MAXN ] ;
long long dp_sub[ MAXN ] ;

bool cmp ( pair < long long , long long > p1 , pair < long long , long long > p2 ) {
    long long k1 = ( p1.first - p1.second ) ;
    long long k2 = ( p2.first - p2.second ) ;
    return ( k1 > k2 ) ;
}

void dfs ( int vertex , int prv ) {
    int sz = v[ vertex ].size ( ) ;
    vector < pair < long long , long long > > aux ;
    aux.clear ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ vertex ][ i ].to == prv ) { continue ; }
        dfs ( v[ vertex ][ i ].to , vertex ) ;
        aux.push_back ( { v[ vertex ][ i ].len + dp_sub[ v[ vertex ][ i ].to ] , dp_all[ v[ vertex ][ i ].to ] } ) ;
    }
    sort ( aux.begin ( ) , aux.end ( ) , cmp ) ;
    int hh = aux.size ( ) ;
    dp_all[ vertex ] = dp_sub[ vertex ] = 0 ;
    for ( int i = 0 ; i < min ( hh , k - 1 ) ; ++ i ) {
        dp_sub[ vertex ] += max ( aux[ i ].first , aux[ i ].second ) ;
    }
    for ( int i = min ( hh , k - 1 ) ; i < hh ; ++ i ) {
        dp_sub[ vertex ] += aux[ i ].second ;
    }

    for ( int i = 0 ; i < min ( hh , k ) ; ++ i ) {
        dp_all[ vertex ] += max ( aux[ i ].first , aux[ i ].second ) ;
    }
    for ( int i = min ( hh , k ) ; i < hh ; ++ i ) {
        dp_all[ vertex ] += aux[ i ].second ;
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        v[ i ].clear ( ) ;
    }
    ans = 0 ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y , z ;
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        v[ x ].push_back ( edge ( y , z ) ) ;
        v[ y ].push_back ( edge ( x , z ) ) ;
    }

}

void solve ( ) {
    dfs ( 1 , -1 ) ;
    printf ( "%I64d\n" , dp_all[ 1 ] ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int q ;
    scanf ( "%d" , &q ) ;
    while ( q -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
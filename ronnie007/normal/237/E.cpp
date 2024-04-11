#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
using namespace std ;

#define MAXN 107
#define inf 1000000007

string a ;
int n ;
string b[ MAXN ] ;
int mx[ MAXN ] ;
int br[ MAXN ][ 28 ] ;
int source , sink ;

int lim[ 2 * MAXN ][ 2 * MAXN ] ;
int c[ 2 * MAXN ][ 2 * MAXN ] ;
int flow[ 2 * MAXN ][ 2 * MAXN ] ;

int used[ 2 * MAXN ] ;

int dfs ( int vertex , int cur ) {
    if ( vertex == sink ) { return cur ; }
    if ( cur == 0 ) { return 0 ; }
    if ( used[ vertex ] == 1 ) { return 0 ; }
    used[ vertex ] = 1 ;
    int i ;
    for ( i = 1 ; i <= n + 28 ; i ++ ) {
        int go = min ( cur , ( lim[ vertex ][ i ] - flow[ vertex ][ i ] ) ) ;
        int ret = dfs ( i , go ) ;
        if ( ret != 0 ) {
            flow[ vertex ][ i ] += ret ;
            flow[ i ][ vertex ] -= ret ;
            used[ vertex ] = 0 ;
            return ret ;
        }
    }
    return 0 ;
}

void input ( ) {
    cin >> a ;
    int i , j ;
    cin >> n ;
    for ( i = 1 ; i <= n ; i ++ ) {
        cin >> b[ i ] >> mx[ i ] ;
        int sz = b[ i ].size ( ) ;
        for ( j = 0 ; j < sz ; j ++ ) {
            br[ i ][ ( b[ i ][ j ] - 'a' ) ] ++ ;
        }
    }
    for ( i = 0 ; i < a.size ( ) ; i ++ ) {
        br[ 0 ][ ( a[ i ] - 'a' ) ] ++ ;
    }
}

void solve ( ) {
    int i , j ;
    source = n + 27 ;
    sink = n + 28 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        lim[ source ][ i ] = mx[ i ] ;
        c[ source ][ i ] = i ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 0 ; j < 26 ; j ++ ) {
            lim[ i ][ n + j + 1 ] = br[ i ][ j ] ;
            c[ i ][ n + j + 1 ] = 0 ;
        }
    }
    for ( i = 0 ; i < 26 ; i ++ ) {
        lim[ n + i + 1 ][ sink ] = br[ 0 ][ i ] ;
        c[ n + i + 1 ][ sink ] = 0 ;
    }
    while ( 1 ) {
        int ret = dfs ( source , inf ) ;
        if ( ret == 0 ) { break ; }
        for ( i = 1 ; i <= n + 28 ; i ++ ) { used[ i ] = 0 ; }
    }
    for ( i = 0 ; i < 26 ; i ++ ) {
        if ( flow[ n + i + 1 ][ sink ] != lim[ n + i + 1 ][ sink ] ) { printf ( "-1\n" ) ; return ; }
    }
    int ans = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        ans += flow[ source ][ i ] * c[ source ][ i ] ;
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
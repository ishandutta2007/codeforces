#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<stack>
#include<ctime>
#include<set>
using namespace std ;

#define MAXN 200007

int n ;
vector < int > v[ MAXN ] ;

int lst[ MAXN ] ;
int ch[ MAXN ] ;

int a[ 2 * MAXN ] ;


void dfs ( int vertex , int prv ) {
    int i ;
    int sz = v[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        lst[ v[ vertex ][ i ] ] = vertex ;
        ch[ vertex ] ++ ;
        dfs ( v[ vertex ][ i ] , vertex ) ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i < n ; i ++ ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    dfs ( 1 , -1 ) ;
    int i ;
    if ( a[ 1 ] != 1 ) { printf ( "No\n" ) ; return ; }
    queue < int > q ;
    q.push ( 1 ) ;
    int id = 2 ;
    int tot = 0 ;
    while ( q.empty ( ) == false ) {
        int x = q.front ( ) ;
        tot ++ ;
        q.pop ( ) ;
        for ( i = 0 ; i < ch[ x ] ; i ++ ) {
            if ( lst[ a[ id + i ] ] != x ) {
                printf ( "No\n" ) ;
                return ;
            }
            q.push ( a[ id + i ] ) ;
        }
        id += ch[ x ] ;
    }
    if ( tot != n ) {
        printf ( "No\n" ) ;
        return ;
    }
    printf ( "Yes\n" ) ;
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
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

#define MAXN 2007
int n ;
vector < int > v[ MAXN ] ;
vector < int > ord ;
int prv[ MAXN ] ;
int cnt[ MAXN ] ;

int root ;

int d[ MAXN ] ;
int ans[ MAXN ] ;

queue < int > q[ MAXN ] ;

void dfs ( int vertex ) {
    if ( cnt[ vertex ] == 0 ) {
        q[ d[ vertex ] ].push ( vertex ) ;
    }
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        d[ v[ vertex ][ i ] ] = d[ vertex ] + 1 ;
        dfs ( v[ vertex ][ i ] ) ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    root = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d%d" , &prv[ i ] , &cnt[ i ] ) ;
        if ( prv[ i ] == 0 ) { root = i ; }
        else {
            v[ prv[ i ] ].push_back ( i ) ;
        }
    }
}

void solve ( ) {
    d[ root ] = 1 ;
    dfs ( root ) ;
    int id = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int h = 0 ;
        for ( int j = 1 ; j <= n ; ++ j ) {
            if ( q[ j ].empty ( ) == false ) {
                h = q[ j ].front ( ) ;
                q[ j ].pop ( ) ;
                break ;
            }
        }
        if ( h == 0 ) { printf ( "NO\n" ) ; return ; }
        ans[ h ] = id ;
        h = prv[ h ] ;
        while ( h > 0 ) {
            if ( cnt[ h ] > 0 ) {
                -- cnt[ h ] ;
                if ( cnt[ h ] == 0 ) {
                    q[ d[ h ] ].push ( h ) ;
                }
            }
            h = prv[ h ] ;
        }
        ++ id ;
    }
    printf ( "YES\n" ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        printf ( "%d " , ans[ i ] ) ;
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
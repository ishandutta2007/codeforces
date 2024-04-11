#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std ;

#define MAXN 300007
#define MOD 1000000007

int n ;
int a[ MAXN ] ;
int b[ MAXN ] ;

vector < int > v[ MAXN ] ;

int h[ MAXN ] ;

bool bad[ MAXN ] ;
int used[ MAXN ] ;
int root[ MAXN ] ;
int comp[ MAXN ] ;
int cycle[ MAXN ] ;

void dfs ( int vertex ) {
    if ( used[ vertex ] == 2 ) {
        root[ vertex ] = vertex ;
        comp[ vertex ] = 1 ;
        cycle[ vertex ] = 1 ;
        return ;
    }
    if ( used[ vertex ] == 1 ) { return ; }
    used[ vertex ] = 2 ;
    int i , sz ;
    sz = v[ vertex ].size ( ) ;
    if ( sz == 0 ) {
        used[ vertex ] = 1 ;
        if ( bad[ vertex ] == 1 ) {
            return ;
        }
        else {
            root[ vertex ] = vertex ;
            comp[ vertex ] = 1 ;
            return ;
        }
    }
    for ( i = 0 ; i < sz ; i ++ ) {
        dfs ( v[ vertex ][ i ] ) ;
        root[ vertex ] = root[ v[ vertex ][ i ] ] ;
        comp[ root[ vertex ] ] ++ ;
    }
    used[ vertex ] = 1 ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d%d" , &a[ i ] , &b[ i ] ) ;
        if ( a[ i ] == b[ i ] ) {
            bad[ a[ i ] ] = 1 ;
            continue ;
        }
        v[ a[ i ] ].push_back ( b[ i ] ) ;
        h[ b[ i ] ] ++ ;
    }
}

void solve ( ) {
    int i ;
    long long ans = 1 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( a[ i ] == b[ i ] ) { continue ; }
        if ( h[ a[ i ] ] == 0 && h[ b[ i ] ] == 0 ) {
            ans = ( ans * 2 ) % MOD ;
            continue ;
        }
        if ( used[ a[ i ] ] == 0 ) {
            dfs ( a[ i ] ) ;
        }
    }
    for ( i = 1 ; i <= 2 * n ; i ++ ) {
        if ( comp[ i ] == 0 || root[ i ] != i ) { continue ; }
        if ( bad[ i ] == 1 ) { continue ; }
        if ( cycle[ i ] == 1 ) {
            ans = ( ans * 2 ) % MOD ;
        }
        else {
            ans = ( ans * comp[ i ] ) % MOD ;
        }
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
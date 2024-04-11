#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std ;

#define MAXN 300007
#define LOG 21

int n , q ;
int value[ MAXN ] ;

vector < pair < int , int > > v[ MAXN ] ;

long long dp[ MAXN ] ;
long long up[ MAXN ] ;

int lvl[ MAXN ] ;
int LCA[ MAXN ][ LOG ] ;

long long prefix[ MAXN ] ;

void dfs_bot ( int vertex , int prv ) {
    int i ;
    int sz = v[ vertex ].size ( ) ;
    dp[ vertex ] = value[ vertex ] ;
    if ( prv != -1 ) {
        for ( i = 1 ; i < LOG ; i ++ ) {
            LCA[ vertex ][ i ] = LCA[ LCA[ vertex ][ i - 1 ] ][ i - 1 ] ;
        }
    }
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ].first == prv ) { continue ; }
        lvl[ v[ vertex ][ i ].first ] = lvl[ vertex ] + 1 ;
        LCA[ v[ vertex ][ i ].first ][ 0 ] = vertex ;
        dfs_bot ( v[ vertex ][ i ].first , vertex ) ;
        long long aux = dp[ v[ vertex ][ i ].first ] - 2 * v[ vertex ][ i ].second ;
        if ( aux < 0 ) { aux = 0 ; }
        dp[ vertex ] += aux ;
    }
}
void dfs_top ( int vertex , int prv , long long prv_edge ) {
    up[ vertex ] = dp[ vertex ] ;
    if ( prv != -1 ) {
        long long aux = up[ vertex ] + up[ prv ] ;
        aux -= 2 * prv_edge ;
        aux -= max ( dp[ vertex ] - 2 * prv_edge , 0LL ) ;
        if ( up[ vertex ] < aux ) { up[ vertex ] = aux ; }
    }
    int i ;
    int sz = v[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ].first == prv ) { continue ; }
        dfs_top ( v[ vertex ][ i ].first , vertex , v[ vertex ][ i ].second ) ;
    }
}
int get_lca ( int x , int y ) {
    int i ;
    for ( i = LOG - 1 ; i >= 0 ; i -- ) {
        if ( lvl[ x ] - (1<<i) >= lvl[ y ] ) {
            x = LCA[ x ][ i ] ;
        }
        if ( lvl[ y ] - (1<<i) >= lvl[ x ] ) {
            y = LCA[ y ][ i ] ;
        }
    }
    for ( i = LOG - 1 ; i >= 0 ; i -- ) {
        if ( LCA[ x ][ i ] != LCA[ y ][ i ] ) {
            x = LCA[ x ][ i ] ;
            y = LCA[ y ][ i ] ;
        }
    }
    if ( x != y ) { x = LCA[ x ][ 0 ] ; }
    return x ;
}

void calculate_prefixes ( int vertex , int prv , int prv_edge ) {
    int i ;
    int sz = v[ vertex ].size ( ) ;
    if ( prv == -1 ) { prefix[ vertex ] = 0 ; }
    else { prefix[ vertex ] = prefix[ prv ] - prv_edge ; }
    prefix[ vertex ] += dp[ vertex ] ;
    if ( prv != -1 ) {
        long long aux = dp[ vertex ] - 2 * prv_edge ;
        if ( aux < 0 ) { aux = 0 ; }
        prefix[ vertex ] -= aux ;
    }
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ].first == prv ) { continue ; }
        calculate_prefixes ( v[ vertex ][ i ].first , vertex , v[ vertex ][ i ].second ) ;
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &value[ i ] ) ;
    }
    for ( i = 1 ; i < n ; i ++ ) {
        int x , y , z ;
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        v[ x ].push_back ( make_pair ( y , z ) ) ;
        v[ y ].push_back ( make_pair ( x , z ) ) ;
    }
}


void solve ( ) {
    dfs_bot ( 1 , -1 ) ;
    dfs_top ( 1 , -1 , 0 ) ;
    calculate_prefixes ( 1 , -1 , 0 ) ;
    while ( q != 0 ) {
        q -- ;
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        int u = get_lca ( x , y ) ;
        long long ans = up[ u ] ;
        ans += prefix[ x ] - prefix[ u ] ;
        ans += prefix[ y ] - prefix[ u ] ;
        printf ( "%I64d\n" , ans ) ;
    }
}


int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
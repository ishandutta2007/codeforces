#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std ;

#define MAXN 100007

int n , q ;
vector < int > v[ MAXN ] ;

int used[ MAXN ] ;

vector < int > aux[ MAXN ] ;
int subtree[ MAXN ] ;

int dist[ MAXN ] ;

int lst[ MAXN ] ;

int lvl[ MAXN ] ;

int br ;
int LCA[ MAXN ][ 22 ] ;


void init ( int vertex , int prv , bool fl ) {
    if ( used[ vertex ] != 0 ) { return ; }
    int sz = v[ vertex ].size ( ) ;
    int i ;
    subtree[ vertex ] = 1 ;
    br ++ ;
    if ( fl == true ) {
        for ( i = 1 ; i <= 20 ; i ++ ) {
            LCA[ vertex ][ i ] = LCA[ LCA[ vertex ][ i - 1 ] ][ i - 1 ] ;
        }
    }
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        if ( used[ v[ vertex ][ i ] ] != 0 ) { continue ; }
        if ( fl == true ) {
            LCA[ v[ vertex ][ i ] ][ 0 ] = vertex ;
            lvl[ v[ vertex ][ i ] ] = lvl[ vertex ] + 1 ;
        }
        init ( v[ vertex ][ i ] , vertex , fl ) ;
        subtree[ vertex ] += subtree[ v[ vertex ][ i ] ] ;
    }
}

int get_LCA ( int x , int y ) {
    int i ;
    for ( i = 20 ; i >= 0 ; i -- ) {
        if ( lvl[ x ] - (1<<i) >= lvl[ y ] ) {
            x = LCA[ x ][ i ] ;
        }
        if ( lvl[ y ] - (1<<i) >= lvl[ x ] ) {
            y = LCA[ y ][ i ] ;
        }
    }
    for ( i = 20 ; i >= 0 ; i -- ) {
        if ( LCA[ x ][ i ] != LCA[ y ][ i ] ) {
            x = LCA[ x ][ i ] ;
            y = LCA[ y ][ i ] ;
        }
    }
    if ( x != y ) { x = LCA[ x ][ 0 ] ; }
    return x ;
}

int get_dist ( int x , int y ) {
    int u = get_LCA ( x , y ) ;
    return ( lvl[ x ] + lvl[ y ] - 2 * lvl[ u ] ) ;
}

int get_centroid ( int vertex , int prv ) {
    int sz = v[ vertex ].size ( ) ;
    int i ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        if ( used[ v[ vertex ][ i ] ] != 0 ) { continue ; }
        if ( subtree[ v[ vertex ][ i ] ] > ( br / 2 ) ) {
            return get_centroid ( v[ vertex ][ i ] , vertex ) ;
        }
    }
    return vertex ;
}

void decompose ( int vertex , int prv ) {
    br = 0 ;
    if ( prv == 0 ) {
        init ( vertex , -1 , true ) ;
    }
    else {
        init ( vertex , -1 , false ) ;
    }
    int u = get_centroid ( vertex , 0 ) ;
    if ( prv > 0 ) { lst[ u ] = prv ; }
    int i ;
    int sz = v[ u ].size ( ) ;
    used[ u ] = 1 ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( used[ v[ u ][ i ] ] != 0 ) { continue ; }
        decompose ( v[ u ][ i ] , u ) ;
    }
    used[ u ] = 0 ;
}

void input ( ) {
    scanf ( "%d%d", &n , &q ) ;
    int i ;
    for ( i = 1 ; i < n ; i ++ ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    decompose ( 1 , 0 ) ;
    int type , vertex ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) { dist[ i ] = get_dist ( i , 1 ) ; }
    while ( q != 0 ) {
        q -- ;
        scanf ( "%d%d", &type , &vertex ) ;
        if ( type == 1 ) {
            int st = vertex ;
            while ( vertex != 0 ) {
                dist[ vertex ] = min ( dist[ vertex ] , get_dist ( vertex , st ) ) ;
                vertex = lst[ vertex ] ;
            }
        }
        else {
            int ans = MAXN ;
            int st = vertex ;
            while ( vertex != 0 ) {
                ans = min ( ans , get_dist ( vertex , st ) + dist[ vertex ] ) ;
                vertex = lst[ vertex ] ;
            }
            printf ( "%d\n" , ans ) ;
        }
    }
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
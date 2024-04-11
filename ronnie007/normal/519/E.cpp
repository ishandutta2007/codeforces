#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<cstdlib>
using namespace std ;

#define MAXN 100007
#define LOG 20

int n ;
vector < int > v[ MAXN ] ;
int lvl[ MAXN ] ;
int LCA[ MAXN ][ LOG ] ;
int subtree[ MAXN ] ;

void dfs ( int vertex , int prv ) {
    if ( prv != -1 ) {
        for ( int i = 1 ; i < LOG ; ++ i ) {
            LCA[ vertex ][ i ] = LCA[ LCA[ vertex ][ i - 1 ] ][ i - 1 ] ;
        }
    }
    subtree[ vertex ] = 1 ;
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ] ;
        if ( h == prv ) { continue ; }
        lvl[ h ] = lvl[ vertex ] + 1 ;
        LCA[ h ][ 0 ] = vertex ;
        dfs ( h , vertex ) ;
        subtree[ vertex ] += subtree[ h ] ;
    }
}

int get_LCA ( int x , int y ) {
    for ( int i = LOG - 1 ; i >= 0 ; -- i ) {
        if ( lvl[ x ] - (1<<i) >= lvl[ y ] ) {
            x = LCA[ x ][ i ] ;
        }
        if ( lvl[ y ] - (1<<i) >= lvl[ x ] ) {
            y = LCA[ y ][ i ] ;
        }
    }
    for ( int i = LOG - 1 ; i >= 0 ; -- i ) {
        if ( LCA[ x ][ i ] != LCA[ y ][ i ] ) {
            x = LCA[ x ][ i ] ;
            y = LCA[ y ][ i ] ;
        }
    }
    if ( x != y ) { x = LCA[ x ][ 0 ] ; }
    return x ;
}

int dist ( int x , int y ) {
    int z = get_LCA ( x , y ) ;
    return ( lvl[ x ] + lvl[ y ] - 2 * lvl[ z ] ) ;
}

int get_vertex ( int x , int aux ) {
    for ( int i = LOG - 1 ; i >= 0 ; -- i ) {
        if ( aux >= (1<<i) ) {
            aux -= (1<<i) ;
            x = LCA[ x ][ i ] ;
        }
    }
    return x ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) , v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    dfs ( 1 , -1 ) ;
    int q ;
    scanf ( "%d" , &q ) ;
    while ( q -- ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        if ( x == y ) { printf ( "%d\n" , n ) ; }
        else if ( lvl[ x ] == lvl[ y ] ) {
            for ( int i = LOG - 1 ; i >= 0 ; -- i ) {
                if ( LCA[ x ][ i ] != LCA[ y ][ i ] ) {
                    x = LCA[ x ][ i ] ;
                    y = LCA[ y ][ i ] ;
                }
            }
            printf ( "%d\n" , n - subtree[ x ] - subtree[ y ] ) ;
        }
        else {
            int aux = dist ( x , y ) ;
            if ( ( aux & 1 ) == 1 ) { printf ( "0\n" ) ; }
            else {
                int z = ( lvl[ x ] > lvl[ y ] ) ? x : y ;
                printf ( "%d\n" , subtree[ get_vertex ( z , (aux>>1) ) ] - subtree[ get_vertex ( z , (aux>>1) - 1 ) ] ) ;
            }
        }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
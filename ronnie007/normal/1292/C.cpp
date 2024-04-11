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

#define MAXN 3007
int n ;
vector < int > v[ MAXN ] ;

int lvl[ MAXN ] ;
int subtree[ MAXN ] ;
int jump[ MAXN ][ MAXN ] ;
int dist[ MAXN ][ MAXN ] ;

vector < pair < int , int > > aux[ MAXN ] ;

long long dp[ MAXN ][ MAXN ] ;

void calc_dist ( int ori ) {
    queue < int > q ;
    q.push ( ori ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        dist[ ori ][ i ] = MAXN ; 
    }
    dist[ ori ][ ori ] = 0 ;
    while ( q.empty ( ) == false ) {
        int x = q.front ( ) ;
        q.pop ( ) ;
        int sz = v[ x ].size ( ) ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            if ( dist[ ori ][ v[ x ][ i ] ] == MAXN ) {
                dist[ ori ][ v[ x ][ i ] ] = dist[ ori ][ x ] + 1 ;
                q.push ( v[ x ][ i ] ) ;
            }
        }
    }
}

void dfs ( int vertex ) {
    int sz = v[ vertex ].size ( ) ;
    subtree[ vertex ] = 1 ;
    jump[ vertex ][ 0 ] = vertex ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        jump[ vertex ][ i ] = jump[ jump[ vertex ][ 1 ] ][ i - 1 ] ;
    }
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ vertex ][ i ] == jump[ vertex ][ 1 ] ) { continue ; }
        jump[ v[ vertex ][ i ] ][ 1 ] = vertex ;
        lvl[ v[ vertex ][ i ] ] = lvl[ vertex ] + 1 ;
        dfs ( v[ vertex ][ i ] ) ;
        subtree[ vertex ] += subtree[ v[ vertex ][ i ] ] ;
    }
}

int extr ( int st , int en ) {
    if ( dist[ st ][ en ] == lvl[ en ] - lvl[ st ] ) {
        return jump[ en ][ dist[ st ][ en ] - 1 ] ;
    }
    return jump[ st ][ 1 ] ;
}

int get_size ( int x , int avoid ) {
    if ( jump[ x ][ 1 ] == avoid ) {
        return subtree[ x ] ;
    }
    return ( n - subtree[ avoid ] ) ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        calc_dist ( i ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = i + 1 ; j <= n ; ++ j ) {
            aux[ dist[ i ][ j ] ].push_back ( { i , j } ) ;
        }
    }
    dfs ( 1 ) ;
    long long ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int sz = aux[ i ].size ( ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            int x = aux[ i ][ j ].first ;
            int y = aux[ i ][ j ].second ;
            int z = extr ( x , y ) ;
            int t = extr ( y , x ) ;
            dp[ x ][ y ] = max ( dp[ z ][ y ] , dp[ x ][ t ] ) ;
            dp[ x ][ y ] += get_size ( x , z ) * get_size ( y , t ) ;
            dp[ y ][ x ] = dp[ x ][ y ] ;
            ans = max ( ans , dp[ x ][ y ] ) ;
        }
    }
    printf ( "%I64d\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
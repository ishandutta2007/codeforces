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

#define MAXN 200007
#define LOG 20

int n , m ;
int add[ MAXN ] ;

vector < int > v[ MAXN ] ;
vector < int > cycle_edges[ MAXN ] ;

int prv[ MAXN ] ;
int lvl[ MAXN ] ;
int LCA[ MAXN ][ LOG ] ;

long long cyclic_sum[ MAXN ] ;
bool inc[ MAXN ] ;
long long sm[ MAXN ] ;

int st_ver ;

bool cyc[ MAXN ] ;

int find_root ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    int y = find_root ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}

void UNITE ( int x , int y ) {
    int k1 = find_root ( x ) ;
    int k2 = find_root ( y ) ;
    if ( k1 != k2 ) {
        prv[ k1 ] = k2 ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
    else {
        cycle_edges[ x ].push_back ( y ) ;
        cycle_edges[ y ].push_back ( x ) ;
    }
}

void init ( int vertex , int lst ) {
    if ( lst != -1 ) {
        for ( int i = 1 ; i < LOG ; ++ i ) {
            LCA[ vertex ][ i ] = LCA[ LCA[ vertex ][ i - 1 ] ][ i - 1 ] ;
        }
    }
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ vertex ][ i ] == lst ) { continue ; }
        lvl[ v[ vertex ][ i ] ] = lvl[ vertex ] + 1 ;
        LCA[ v[ vertex ][ i ] ][ 0 ] = vertex ;
        init ( v[ vertex ][ i ] , vertex ) ;
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

void dfs ( int vertex , int lst ) {
    int sz = cycle_edges[ vertex ].size ( ) ;
    int mn = lvl[ vertex ] ;
    int hh = vertex ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int aux = get_LCA ( vertex , cycle_edges[ vertex ][ i ] ) ;
        if ( lvl[ aux ] < mn ) {
            mn = lvl[ aux ] ;
            hh = aux ;
        }
    }
    if ( hh != vertex ) { cyc[ vertex ] = true ; }
    sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ vertex ][ i ] != lst ) {
            dfs ( v[ vertex ][ i ] , vertex ) ;
            if ( cyc[ v[ vertex ][ i ] ] == true ) { cyc[ vertex ] = true ; }
        }
    }
    if ( cyc[ vertex ] == true && vertex != st_ver ) {
        sm[ st_ver ] += sm[ vertex ] + add[ vertex ] ;
        sm[ vertex ] = 0 ;
    }
    else {
        if ( hh == vertex ) {
            sm[ vertex ] += add[ vertex ] ;
        }
    }
}

void calc ( int vertex , int lst ) {
    int sz = v[ vertex ].size ( ) ;
    long long mx = 0 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ vertex ][ i ] != lst ) {
            calc ( v[ vertex ][ i ] , vertex ) ;
            mx = max ( mx , sm[ v[ vertex ][ i ] ] ) ;
        }
    }
    sm[ vertex ] += mx ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &add[ i ] ) ;
        prv[ i ] = -1 ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) , UNITE ( x , y ) ;
    }
    scanf ( "%d" , &st_ver ) ;
}

void solve ( ) {
    lvl[ st_ver ] = 1 ;
    init ( st_ver , -1 ) ;
    dfs ( st_ver , -1 ) ;
    calc ( st_ver , -1 ) ;
    printf ( "%I64d\n" , sm[ st_ver ] ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
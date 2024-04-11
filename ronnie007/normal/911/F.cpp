#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
using namespace std ;

#define MAXN 200007
#define LOG 20


int n ;
vector < int > v[ MAXN ] ;

int dist[ MAXN ] ;
int prv[ MAXN ] ;
int used[ MAXN ] ;

int en1 , en2 ;

int LCA[ MAXN ][ LOG + 1 ] ;
int lvl[ MAXN ] ;

bool mainchain[ MAXN ] ;

long long sm = 0 ;
vector < pair < int , int > > ans ;

void find_diam ( int vertex ) {
    used[ vertex ] = 1 ;
    int sz = v[ vertex ].size ( ) ;
    int i ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( used[ v[ vertex ][ i ] ] == 1 ) { continue ; }
        dist[ v[ vertex ][ i ] ] = dist[ vertex ] + 1 ;
        prv[ v[ vertex ][ i ] ] = vertex ;
        find_diam ( v[ vertex ][ i ] ) ;
    }
}

void init_lca ( int vertex , int prv ) {
    int i ;
    int sz = v[ vertex ].size ( ) ;
    if ( prv != -1 ) {
        for ( i = 1 ; i < LOG ; i ++ ) {
            LCA[ vertex ][ i ] = LCA[ LCA[ vertex ][ i - 1 ] ][ i - 1 ] ;
        }
    }
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        lvl[ v[ vertex ][ i ] ] = lvl[ vertex ] + 1 ;
        LCA[ v[ vertex ][ i ] ][ 0 ] = vertex ;
        init_lca ( v[ vertex ][ i ] , vertex ) ;
    }
}

int get_LCA ( int x , int y ) {
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

int get_dist ( int x , int y ) {
    int u = get_LCA ( x , y ) ;
    return ( lvl[ x ] + lvl[ y ] - 2 * lvl[ u ] ) ;
}

void dfs ( int vertex , int prv ) {
    int i ;
    int sz = v[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        dfs ( v[ vertex ][ i ] , vertex ) ;
    }
    if ( mainchain[ vertex ] == false ) {
        int dist1 , dist2 ;
        dist1 = get_dist ( vertex , en1 ) ;
        dist2 = get_dist ( vertex , en2 ) ;
        if ( dist1 >= dist2 ) {
            sm += dist1 ;
            ans.push_back ( make_pair ( en1 , vertex ) ) ;
        }
        else {
            sm += dist2 ;
            ans.push_back ( make_pair ( en2 , vertex ) ) ;
        }
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
}

void solve ( ) {
    int i ;
    int mx = -1 ;
    int id = 0 ;
    find_diam ( 1 ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( mx < dist[ i ] ) { mx = dist[ i ] ; id = i ; }
        dist[ i ] = used[ i ] = 0 ;
    }
    en1 = id ;
    mx = -1 ;
    id = 0 ;
    find_diam ( en1 ) ;
    prv[ en1 ] = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( mx < dist[ i ] ) { mx = dist[ i ] ; id = i ; }
        dist[ i ] = used[ i ] = 0 ;
    }
    en2 = id ;
    init_lca ( 1 , -1 ) ;
    int aux = en2 ;
    while ( aux != en1 ) {
        mainchain[ aux ] = true ;
        aux = prv[ aux ] ;
    }
    mainchain[ en1 ] = true ;
    dfs ( en1 , -1 ) ;
    aux = en2 ;
    while ( aux != en1 ) {
        ans.push_back ( make_pair ( en1 , aux ) ) ;
        sm += mx ;
        mx -- ;
        aux = prv[ aux ] ;
    }
    printf ( "%I64d\n" , sm ) ;
    for ( i = 0 ; i < n - 1 ; i ++ ) {
        printf ( "%d %d %d\n" , ans[ i ].first , ans[ i ].second , ans[ i ].second ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
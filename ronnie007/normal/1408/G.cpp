#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

#define MAXN 1507
#define MOD 998244353

int n ;
long long dp[ MAXN ][ MAXN ] ;
int prv[ MAXN ] ;
int rnk[ MAXN ] ;
int sz[ MAXN ] ;
int edge_cnt[ MAXN ] ;

struct edge {
    int x , y ;
    int cost ;
    edge ( ) { x = y = cost = 0 ; }
    edge ( int _x , int _y , int _cost ) {
        x = _x ; y = _y ;
        cost = _cost ;
    }
};
vector < edge > srt ;

int find ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    int y = find ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}

long long b[ MAXN ] ;

void upd ( int id1 , int id2 , int dest ) {
    for ( int i = 1 ; i <= sz[ id1 ] + sz[ id2 ] ; ++ i ) {
        b[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= sz[ id1 ] ; ++ i ) {
        for ( int j = 1 ; j <= sz[ id2 ] ; ++ j ) {
            b[ i + j ] += ( dp[ id1 ][ i ] * dp[ id2 ][ j ] ) % MOD ;
            if ( b[ i + j ] >= MOD ) { b[ i + j ] -= MOD ; }
        }
    }
    for ( int i = 1 ; i <= sz[ id1 ] + sz[ id2 ] ; ++ i ) {
        dp[ dest ][ i ] = b[ i ] ;
    }
}

void unite ( edge aux ) {
    int k1 = find ( aux.x ) ;
    int k2 = find ( aux.y ) ;
    if ( k1 == k2 ) {
        ++ edge_cnt[ k1 ] ;
        if ( edge_cnt[ k1 ] == sz[ k1 ] * ( sz[ k1 ] - 1 ) / 2 ) {
            ++ dp[ k1 ][ 1 ] ;
        }
    }
    else {
        if ( rnk[ k1 ] >= rnk[ k2 ] ) {
            prv[ k2 ] = k1 ;
            upd ( k1 , k2 , k1 ) ;
            sz[ k1 ] += sz[ k2 ] ;
            edge_cnt[ k1 ] += edge_cnt[ k2 ] + 1 ;
            if ( edge_cnt[ k1 ] == sz[ k1 ] * ( sz[ k1 ] - 1 ) / 2 ) {
                ++ dp[ k1 ][ 1 ] ;
            }
            rnk[ k1 ] += ( rnk[ k1 ] == rnk[ k2 ] ) ;
        }
        else {
            prv[ k1 ] = k2 ;
            upd ( k1 , k2 , k2 ) ;
            sz[ k2 ] += sz[ k1 ] ;
            edge_cnt[ k2 ] += edge_cnt[ k1 ] + 1 ;
            if ( edge_cnt[ k2 ] == sz[ k2 ] * ( sz[ k2 ] - 1 ) / 2 ) {
                ++ dp[ k2 ][ 1 ] ;
            }
        }
    }
}


void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            int x ;
            scanf ( "%d" , &x ) ;
            if ( i < j ) {
                srt.push_back ( edge ( i , j , x ) ) ;
            }
        }
    }
}

void solve ( ) {
    auto cmp = [ & ] ( edge p1 , edge p2 ) {
        return p1.cost < p2.cost ;
    } ;
    sort ( srt.begin ( ) , srt.end ( ) , cmp ) ;
    int len = srt.size ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        prv[ i ] = -1 ;
        rnk[ i ] = 0 ;
        dp[ i ][ 1 ] = 1 ;
        sz[ i ] = 1 ;
        edge_cnt[ i ] = 0 ;
    }
    for ( int i = 0 ; i < len ; ++ i ) {
        unite ( srt[ i ] ) ;
    }
    int root = find ( 1 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        printf ( "%I64d " , dp[ root ][ i ] ) ;
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
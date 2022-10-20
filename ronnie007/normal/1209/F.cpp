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

#define MAXN 2000007
#define LOG 22
#define NUM_MODS 3


long long MOD[ NUM_MODS ] = { 1000000007 , 1000003 , 98382749 } ;

int n , m ;

struct tuhla {
    long long h[ NUM_MODS ] ;
    tuhla ( ) {
        for ( int i = 0 ; i < NUM_MODS ; ++ i ) {
            h[ i ] = 0 ;
        }
    }
    void add_char ( int x ) {
        for ( int i = 0 ; i < NUM_MODS ; ++ i ) {
            h[ i ] = ( h[ i ] * 10 + x ) % MOD[ i ] ;
        }
    }
    bool operator == ( const tuhla &other ) const {
        for ( int i = 0 ; i < NUM_MODS ; ++ i ) {
            if ( h[ i ] != other.h[ i ] ) { return false ; }
        }
        return true ;
    }
    bool operator != ( const tuhla &other ) const {
        for ( int i = 0 ; i < NUM_MODS ; ++ i ) {
            if ( h[ i ] != other.h[ i ] ) { return true ; }
        }
        return false ;
    }
};

tuhla path[ MAXN ] ;

vector < pair < int , int > > v[ MAXN ] ;

int tp ;

int lvl[ MAXN ] ;
int LCA[ MAXN ][ LOG ] ;
int edge_val[ MAXN ] ;

bool pushed[ MAXN ] ;

void add_path ( int st , int en , int val ) {
    vector < int > digs ;
    while ( val > 0 ) {
        digs.push_back ( ( val % 10 ) ) ;
        val /= 10 ;
    }
    int sz = digs.size ( ) ;
    int lst = st ;
    for ( int i = sz - 1 ; i >= 1 ; -- i ) {
        v[ lst ].push_back ( { tp , digs[ i ] } ) ;
        lst = tp ++ ;
    }
    v[ lst ].push_back ( { en , digs[ 0 ] } ) ;
}




bool cmp ( int x , int cand , int lst_edge ) {
    int aux = LCA[ x ][ 0 ] ;
    if ( path[ aux ] == path[ cand ] ) {
        return ( lst_edge < edge_val[ x ] ) ;
    }
    for ( int i = LOG - 1 ; i >= 0 ; -- i ) {
        if ( lvl[ aux ] >= (1<<i) ) {
            if ( path[ LCA[ aux ][ i ] ] != path[ LCA[ cand ][ i ] ] ) {
                aux = LCA[ aux ][ i ] ;
                cand = LCA[ cand ][ i ] ;
            }
        }
    }
    return ( edge_val[ cand ] < edge_val[ aux ] ) ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    tp = n + 1 ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        add_path ( x , y , i ) ;
        add_path ( y , x , i ) ;
    }
}

void solve ( ) {
    queue < int > q ;
    q.push ( 1 ) ;
    lvl[ 1 ] = 1 ;
    pushed[ 1 ] = true ;
    while ( q.empty ( ) == false ) {
        int x = q.front ( ) ;
        q.pop ( ) ;
        int sz = v[ x ].size ( ) ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            if ( lvl[ v[ x ][ i ].first ] == 0 || cmp ( v[ x ][ i ].first , x , v[ x ][ i ].second ) == true ) {
                lvl[ v[ x ][ i ].first ] = lvl[ x ] + 1 ;
                LCA[ v[ x ][ i ].first ][ 0 ] = x ;
                edge_val[ v[ x ][ i ].first ] = v[ x ][ i ].second ;
                path[ v[ x ][ i ].first ] = path[ x ] , path[ v[ x ][ i ].first ].add_char ( v[ x ][ i ].second ) ;
                for ( int j = 1 ; j < LOG ; ++ j ) {
                    LCA[ v[ x ][ i ].first ][ j ] = LCA[ LCA[ v[ x ][ i ].first ][ j - 1 ] ][ j - 1 ] ;
                }
                if ( pushed[ v[ x ][ i ].first ] == false ) {
                    q.push ( v[ x ][ i ].first ) ;
                    pushed[ v[ x ][ i ].first ] = true ;
                }

            }
        }
    }
    for ( int i = 2 ; i <= n ; ++ i ) {
        printf ( "%I64d\n" , path[ i ].h[ 0 ] ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
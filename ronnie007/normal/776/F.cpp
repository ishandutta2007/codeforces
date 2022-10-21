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
#include<random>
using namespace std ;

#define MAXN 1000007

int n , m ;
pair < int , int > edges[ MAXN ] ;
int nxt[ MAXN ] ;

map < pair < int , int > , int > w ;
int ans[ MAXN ] ;

struct polygon {
    vector < int > vertices ;
    vector < int > srt ;
    bool operator < ( polygon other ) const {
        int sz1 = srt.size ( ) ;
        int sz2 = other.srt.size ( ) ;
        for ( int i = 0 ; i < min ( sz1 , sz2 ) ; ++ i ) {
            if ( srt[ i ] != other.srt[ i ] ) {
                return ( srt[ i ] > other.srt[ i ] ) ; 
            }
        }
        return false ;
    }
};
polygon a[ MAXN ] ;

vector < int > v[ MAXN ] ;

bool edge_cmp ( pair < int , int > p1 , pair < int , int > p2 ) {
    return ( p1.second - p1.first < p2.second - p2.first ) ;
}

void process ( int fst , int snd , int id ) {
    if ( fst > snd ) { swap ( fst , snd ) ; }
    if ( w.find ( { fst , snd } ) == w.end ( ) ) {
        w[ { fst , snd } ] = id ;
    }
    else {
        int ret = w[ { fst , snd } ] ;
        v[ id ].push_back ( ret ) ;
        v[ ret ].push_back ( id ) ;
    }
}


int subtree[ MAXN ] ;
int used[ MAXN ] ;
int cnt = 0 ;

void dfs ( int vertex , int prv ) {
    int sz = v[ vertex ].size ( ) ;
    subtree[ vertex ] = 1 ;
    ++ cnt ; 
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        if ( used[ v[ vertex ][ i ] ] > 0 ) { continue ; }
        dfs ( v[ vertex ][ i ] , vertex ) ;
        subtree[ vertex ] += subtree[ v[ vertex ][ i ] ] ;
    }
}

int get_cen ( int vertex , int prv ) {
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        if ( used[ v[ vertex ][ i ] ] > 0 ) { continue ; }
        if ( subtree[ v[ vertex ][ i ] ] > ( cnt / 2 ) ) {
            return get_cen ( v[ vertex ][ i ] , vertex ) ;
        }
    }
    return vertex ;
}

void decomp ( int vertex , int depth ) {
    cnt = 0 ;
    dfs ( vertex , -1 ) ;
    int cen = get_cen ( vertex , -1 ) ;
    ans[ cen ] = depth ;
    used[ cen ] = 1 ;
    int sz = v[ cen ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( used[ v[ cen ][ i ] ] > 0 ) { continue ; }
        decomp ( v[ cen ][ i ] , depth + 1 ) ;
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        scanf ( "%d%d" , &edges[ i ].first , &edges[ i ].second ) ;
        if ( edges[ i ].first > edges[ i ].second ) {
            swap ( edges[ i ].first , edges[ i ].second ) ;
        }
    }
    sort ( edges + 1 , edges + m + 1 , edge_cmp ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        nxt[ i ] = i + 1 ;
    }
    nxt[ n ] = 1 ;
}

void solve ( ) {
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x = edges[ i ].first ;
        while ( x < edges[ i ].second ) {
            a[ i ].vertices.push_back ( x ) ;
            x = nxt[ x ] ;
        }
        a[ i ].vertices.push_back ( edges[ i ].second ) ;
        nxt[ edges[ i ].first ] = edges[ i ].second ;
    }
    a[ m + 1 ].vertices.push_back ( 1 ) ;
    while ( 1 ) {
        int aux = a[ m + 1 ].vertices.back ( ) ;
        if ( nxt[ aux ] == 1 ) { break ; }
        a[ m + 1 ].vertices.push_back ( nxt[ aux ] ) ;
    }
    for ( int i = 1 ; i <= m + 1 ; ++ i ) {
        a[ i ].srt = a[ i ].vertices ;
        sort ( a[ i ].srt.begin ( ) , a[ i ].srt.end ( ) , greater<int>() ) ;
    }
    sort ( a + 1 , a + m + 2 ) ;
    for ( int i = 1 ; i <= m + 1 ; ++ i ) {
        int sz = a[ i ].vertices.size ( ) ;
        for ( int j = 0 ; j < sz - 1 ; ++ j ) {
            process ( a[ i ].vertices[ j ] , a[ i ].vertices[ j + 1 ] , m + 2 - i ) ;
        }
        process ( a[ i ].vertices.back ( ) , a[ i ].vertices[ 0 ] , m + 2 - i ) ;
    }
    decomp ( 1 , 1 ) ;
    for ( int i = 1 ; i <= m + 1 ; ++ i ) {
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
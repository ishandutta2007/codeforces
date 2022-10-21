#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
using namespace std ;

#define MAXN 1000007

int n , m ;
vector < pair < int , int > > v[ MAXN ] ;
vector < int > rv[ MAXN ] ;

int comp[ MAXN ] ;
vector < pair < int , int > > g[ MAXN ] ;
long long sm[ MAXN ] ;

int used[ MAXN ] ;

int stver ;
stack < int > s ;
vector < int > srt ;
bool val[ 100000002 ] ;
long long hval[ MAXN ] ;
long long dp[ MAXN ] ;

map < int , int > ZX ;

void dfs ( int vertex ) {
    used[ vertex ] = 1 ;
    int i ;
    int sz = v[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( used[ v[ vertex ][ i ].first ] == 0 ) {
            dfs ( v[ vertex ][ i ].first ) ;
        }
    }
    s.push ( vertex ) ;
}

void revdfs ( int vertex , int id ) {
    comp[ vertex ] = id ;
    int i ;
    int sz = rv[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( comp[ rv[ vertex ][ i ] ] == 0 ) {
            revdfs ( rv[ vertex ][ i ] , id ) ;
        }
    }
}

void precalc ( ) {
    int i ;
    long long cur = 0 ;
    int br = 1 ;
    if ( val[ 0 ] == true ) {
        hval[ 0 ] = 1 ;
    }
    for ( i = 1 ; i < 100000002 ; i ++ ) {
        cur = cur + br ;
        if ( i >= ( br * ( br + 1 ) / 2 ) ) {
            br ++ ;
        }
        if ( val[ i ] == true ) {
            hval[ ZX[ i ] ] = cur ;
        }
    }
}

void calc_dp ( int vertex ) {
    used[ vertex ] = 1 ;
    int i ;
    int sz = g[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( used[ g[ vertex ][ i ].first ] == 0 ) {
            calc_dp ( g[ vertex ][ i ].first ) ;
        }
        if ( dp[ vertex ] < dp[ g[ vertex ][ i ].first ] + g[ vertex ][ i ].second ) {
            dp[ vertex ] = dp[ g[ vertex ][ i ].first ] + g[ vertex ][ i ].second ;
        }
    }
    dp[ vertex ] += sm[ vertex ] ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    for ( i = 1 ; i <= m ; i ++ ) {
        int x , y , z ;
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        v[ x ].push_back ( make_pair ( y , z ) ) ;
        rv[ y ].push_back ( x ) ;
        srt.push_back ( z ) ;
        val[ z ] = true ;
    }
    if ( srt.size ( ) != 0 ) {
        sort ( srt.begin ( ) , srt.end ( ) ) ;
        ZX[ srt[ 0 ] ] = 1 ;
        for ( i = 1 ; i < m ; i ++ ) {
            if ( srt[ i ] == srt[ i - 1 ] ) { continue ; }
            ZX[ srt[ i ] ] = ZX[ srt[ i - 1 ] ] + 1 ;
        }
    }
    scanf ( "%d" , &stver ) ;
    precalc ( ) ;
}

void solve ( ) {
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( used[ i ] == 0 ) {
            dfs ( i ) ;
        }
    }
    int tp = 1 ;
    while ( s.empty ( ) == false ) {
        int u = s.top ( ) ;
        s.pop ( ) ;
        if ( comp[ u ] != 0 ) { continue ; }
        revdfs ( u , tp ) ;
        tp ++ ;
    }

    for ( i = 1 ; i <= n ; i ++ ) {
        int sz = v[ i ].size ( ) ;
        for ( j = 0 ; j < sz ; j ++ ) {
            if ( comp[ v[ i ][ j ].first ] == comp[ i ] ) {
                sm[ comp[ i ] ] += hval[ ZX[ v[ i ][ j ].second ] ] ;
            }
            else {
                g[ comp[ i ] ].push_back ( make_pair ( comp[ v[ i ][ j ].first ] , v[ i ][ j ].second ) ) ;
            }
        }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        used[ i ] = 0 ;
    }
    stver = comp[ stver ] ;
    calc_dp ( stver ) ;
    printf ( "%I64d\n" , dp[ stver ] ) ;

}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
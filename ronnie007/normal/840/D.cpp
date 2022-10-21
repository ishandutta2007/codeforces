#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

int n , q ;
int a[ MAXN ] ;
vector < int > v[ MAXN ] ;
int sz[ MAXN ] ;

int cand_sz ;
int cand[ MAXN ] ;

bool wtf[ MAXN ] ;

mt19937 rng ( time ( 0 ) ) ;

int f ( int id , int sr ) {
    int l , r , mid ;
    l = 0 ; r = sz[ id ] - 1 ;
    if ( v[ id ][ l ] > sr ) { return 0 ; }
    if ( v[ id ][ r ] <= sr ) { return sz[ id ] ; }
    while ( r - l > 1 ) {
        int mid = ( l + r ) / 2 ;
        if ( v[ id ][ mid ] <= sr ) { l = mid ; }
        else { r = mid ; }
    }
    while ( v[ id ][ r ] > sr ) { -- r ; }
    return ( r + 1 ) ;
}
class Tree {
public :
    vector < pair < int , int > > tr[ 4 * MAXN ] ;

    void unite ( int where ) {
        int sz1 = tr[ 2 * where ].size ( ) ;
        int sz2 = tr[ 2 * where + 1 ].size ( ) ;
        int pos1 , pos2 ;
        pos1 = pos2 = 0 ;
        while ( pos1 < sz1 || pos2 < sz2 ) {
            if ( pos1 == sz1 ) {
                tr[ where ].push_back ( tr[ 2 * where + 1 ][ pos2 ++ ] ) ;
            }
            else if ( pos2 == sz2 ) {
                tr[ where ].push_back ( tr[ 2 * where ][ pos1 ++ ] ) ;
            }
            else {
                if ( tr[ 2 * where ][ pos1 ].second < tr[ 2 * where + 1 ][ pos2 ].second ) {
                    tr[ where ].push_back ( tr[ 2 * where ][ pos1 ++ ] ) ;
                }
                else if ( tr[ 2 * where ][ pos1 ].second > tr[ 2 * where + 1 ][ pos2 ].second ) {
                    tr[ where ].push_back ( tr[ 2 * where + 1 ][ pos2 ++ ] ) ;
                }
                else {
                    tr[ where ].push_back ( tr[ 2 * where ][ pos1 ++ ] ) ;
                    ( tr[ where ].back ( ) ).first += tr[ 2 * where + 1 ][ pos2 ++ ].first ;
                }
            }
        }
    }
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            tr[ where ].push_back ( { 1 , a[ IL ] } ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        unite ( where ) ;
    }
    void srt ( int where , int IL , int IR ) {
        sort ( tr[ where ].begin ( ) , tr[ where ].end ( ) , greater < pair < int , int > > ( ) ) ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        srt ( 2 * where , IL , mid ) ;
        srt ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( CURL > CURR ) { return ; }
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            int en = tr[ where ].size ( ) ;
            en = min ( en , 5 ) ;
            for ( int i = 0 ; i < en ; ++ i ) {
                if ( wtf[ tr[ where ][ i ].second ] == false ) {
                    cand[ cand_sz ++ ] = tr[ where ][ i ].second ;
                    wtf[ tr[ where ][ i ].second ] = true ;
                }
            }
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( CURL <= mid ) {
            query ( 2 * where , IL , mid , CURL , CURR ) ;
        }
        if ( CURR > mid ) {
            query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
        }
    }
};
Tree w ;
    
void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        v[ a[ i ] ].push_back ( i ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        sz[ i ] = v[ i ].size ( ) ;
    }
    w.init ( 1 , 1 , n ) ;
    w.srt ( 1 , 1 , n ) ;
}

void solve ( ) {
    int l , r , k ;
    while ( q -- ) {
        scanf ( "%d%d%d" , &l , &r , &k ) ;
        int sr = ( r - l + 1 ) / k ;
        int len = ( r - l + 1 ) ;
        int ret = -1 ;
        cand_sz = 0 ;
        w.query ( 1 , 1 , n , l , r ) ;
        for ( int i = 0 ; i < cand_sz ; ++ i ) {
            wtf[ cand[ i ] ] = false ;
            int cnt = f ( cand[ i ] , r ) ;
            if ( cnt < sr ) { continue ; }
            else { cnt -= f ( cand[ i ] , l - 1 ) ; } 
            if ( cnt > sr ) {
                if ( ret == -1 || ret > cand[ i ] ) { ret = cand[ i ] ; }
            }
        }
        printf ( "%d\n" , ret ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
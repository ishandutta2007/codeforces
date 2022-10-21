#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n , q ;
int a[ MAXN ] ;

class Tree {
public : 
    long long sm[ 4 * MAXN ] ;
    int mx[ 4 * MAXN ] ;
    void unite ( int where ) {
        sm[ where ] = ( sm[ 2 * where ] + sm[ 2 * where + 1 ] ) ;
        mx[ where ] = max ( mx[ 2 * where ] , mx[ 2 * where + 1 ] ) ;
    }
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            sm[ where ] = mx[ where ] = a[ IL ] ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        unite ( where ) ;
    }
    void update ( int where , int IL , int IR , int pos , int val ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            sm[ where ] = mx[ where ] = val ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , val ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
        }
        unite ( where ) ;
    }
    long long query_sm ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( CURL > CURR ) { return 0 ; }
        if ( CURR < IL || IR < CURL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) { return sm[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return ( query_sm ( 2 * where , IL , mid , CURL , CURR ) + query_sm ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
    int get_fst ( int where , int IL , int IR , int bound , long long sr ) {
        if ( IR < bound ) { return 0 ; }
        if ( mx[ where ] < sr ) { return 0 ; }
        if ( IL == IR ) { return IL ; }
        int mid = ( IL + IR ) / 2 ;
        int ret = get_fst ( 2 * where , IL , mid , bound , sr ) ;
        if ( ret == 0 ) { return get_fst ( 2 * where + 1 , mid + 1 , IR , bound , sr ) ; }
        return ret ;
    }
};
Tree w ;

int obtain ( ) {
    long long sm = a[ 1 ] ;
    int en = 1 ;
    if ( sm == 0 ) { return 1 ; }
    while ( 1 ) {
        int ret = w.get_fst ( 1 , 1 , n , en + 1 , sm ) ;
        if ( ret == 0 ) { return -1 ; }
        sm += w.query_sm ( 1 , 1 , n , en + 1 , ret - 1 ) ;
        if ( a[ ret ] == sm ) { return ret ; }
        sm += a[ ret ] ; 
        en = ret ;
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    w.init ( 1 , 1 , n ) ;
}

void solve ( ) {
    while ( q -- ) {
        int pos , x ;
        scanf ( "%d%d" , &pos , &x ) ;
        w.update ( 1 , 1 , n , pos , x ) ;
        a[ pos ] = x ;
        printf ( "%d\n" , obtain ( ) ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
using namespace std ;

#define MAXN 200007

int n ;
pair < int , int > a[ MAXN ] ;

int mx[ MAXN ] ;

vector < int > v[ MAXN ] ;
int aux[ MAXN ] ;


class Tree {
    public :
    pair < int , int > tr[ 4 * MAXN ] ;
    void combine ( int where ) {
        if ( tr[ 2 * where ].second >= tr[ 2 * where + 1 ].second ) {
            tr[ where ] = tr[ 2 * where ] ;
        }
        else {
            tr[ where ] = tr[ 2 * where + 1 ] ;
        }
    }
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            tr[ where ] = make_pair ( IL , mx[ IL ] ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        combine ( where ) ;
    }
    void update ( int where , int IL , int IR , int pos , int val ) {
        if ( pos < IL || IR < pos ) { return ; }
        if ( IL == IR ) {
            tr[ where ] = make_pair ( pos , val ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , pos , val ) ;
        update ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
        combine ( where ) ;
    }
};
Tree w ;

int f ( int id , int sr ) {
    int l , r , mid ;
    l = 0 ;
    r = v[ id ].size ( ) - 1 ;
    if ( v[ id ][ l ] >= sr ) { return v[ id ][ l ] ; }
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( v[ id ][ mid ] >= sr ) { r = mid ; }
        else { l = mid ; }
    }
    while ( v[ id ][ l ] < sr ) { l ++ ; }
    return v[ id ][ l ] ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        mx[ i ] = 0 ;
        v[ i ].clear ( ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
        mx[ a[ i ].first ] = a[ i ].second ;
        v[ a[ i ].first ].push_back ( a[ i ].second ) ;
    }
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    int q ;
    int sz ;
    scanf ( "%d" , &q ) ;
    while ( q != 0 ) {
        q -- ;
        scanf ( "%d" , &sz ) ;
        int i ;
        for ( i = 0 ; i < sz ; i ++ ) {
            scanf ( "%d" , &aux[ i ] ) ;
            w.update ( 1 , 1 , n , aux[ i ] , 0 ) ;
        }
        if ( w.tr[ 1 ].second == 0 ) {
            printf ( "0 0\n" ) ;
        }
        else {
            int id = w.tr[ 1 ].first ;
            w.update ( 1 , 1 , n , id , 0 ) ;
            int sr = w.tr[ 1 ].second ;
            printf ( "%d %d\n" , id , f ( id , sr ) ) ;
            w.update ( 1 , 1 , n , id , mx[ id ] ) ;
        }
        for ( i = 0 ; i < sz ; i ++ ) {
            w.update ( 1 , 1 , n , aux[ i ] , mx[ aux[ i ] ] ) ;
        }
    }
}

int main ( ) {
    ///ios::sync_with_stdio ( false ) ;
    ///cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
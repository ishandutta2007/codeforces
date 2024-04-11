#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<stack>
#include<ctime>
#include<set>
using namespace std ;

#define MAXN 300007

int n ;
int a[ MAXN ] ;
int b[ MAXN ] ;

queue < int > q[ MAXN ] ;



class Tree {
    public :
    int tr[ 5 * MAXN ] ;
    int merge ( int x , int y ) {
        return ( x < y ) ? x : y ;
    }
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            tr[ where ] = a[ IL ] ; return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    void update ( int where , int IL , int IR , int pos , int val ) {
        if ( pos < IL || IR < pos ) { return ; }
        if ( IL == IR ) {
            tr[ where ] = val ; return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , val ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
        }
        tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    int query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IR < CURL || CURR < IL ) { return MAXN ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return merge ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};

Tree w ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        while ( q[ i ].empty ( ) == false ) {
            q[ i ].pop ( ) ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        q[ a[ i ] ].push ( i ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &b[ i ] ) ;
    }
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( q[ b[ i ] ].empty ( ) == true ) {
            printf ( "NO\n" ) ; return ;
        }
        int x = q[ b[ i ] ].front ( ) ; q[ b[ i ] ].pop ( ) ;
        if ( w.query ( 1 , 1 , n , 1 , x ) != b[ i ] ) {
            printf ( "NO\n" ) ; return ;
        }
        w.update ( 1 , 1 , n , x , MAXN ) ;
    }
    printf ( "YES\n" ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ; scanf ( "%d" , &t ) ;
    while ( t > 0 ) {
        -- t ;
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
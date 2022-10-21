#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;

pair < int , int > b[ MAXN ] ;

struct Tree {
    int tr[ 3 * MAXN ] ;
    int mn[ 3 * MAXN ] ;
    int id[ 3 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            tr[ where ] = 1 ;
            mn[ where ] = a[ IL ] ;
            id[ where ] = IL ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = tr[ 2 * where ] + tr[ 2 * where + 1 ] ;
        mn[ where ] = min ( mn[ 2 * where ] , mn[ 2 * where + 1 ] ) ;
        if ( mn[ 2 * where ] <= mn[ 2 * where + 1 ] ) {
            id[ where ] = id[ 2 * where ] ;
        }
        else {
            id[ where ] = id[ 2 * where + 1 ] ;
        }
    }
    void update ( int where , int IL , int IR , int pos , int val ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ] += val ;
            mn[ where ] = MAXN ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , val ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
        }
        tr[ where ] = tr[ 2 * where ] + tr[ 2 * where + 1 ] ;
        mn[ where ] = min ( mn[ 2 * where ] , mn[ 2 * where + 1 ] ) ;
        if ( mn[ 2 * where ] <= mn[ 2 * where + 1 ] ) {
            id[ where ] = id[ 2 * where ] ;
        }
        else {
            id[ where ] = id[ 2 * where + 1 ] ;
        }
    }
    int query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IR < CURL || CURR < IL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) {
            return tr[ where ] ;
        }
        int mid = ( IL + IR ) / 2 ;
        return ( query ( 2 * where , IL , mid , CURL , CURR ) + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
    int getl ( int where , int IL , int IR , int pos , int sr ) {
        if ( IR < pos ) { return MAXN ; }
        if ( mn[ where ] != sr ) { return MAXN ; }
        if ( pos <= IL ) { return id[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        int u = getl ( 2 * where , IL , mid , pos , sr ) ;
        if ( u != MAXN ) { return u ; }
        return getl ( 2 * where + 1 , mid + 1 , IR , pos , sr ) ;
    }
};

Tree w ;

void compress ( ) {
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        b[ i ].first = a[ i ] ;
        b[ i ].second = i ;
    }
    sort ( b + 1 , b + n + 1 ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
        a[ b[ i ].second ] = i ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    int i ;
    int x = 1 ;
    long long ans = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        int sr = w.mn[ 1 ] ;
        int pos = w.getl ( 1 , 1 , n , x , sr ) ;
        if ( pos == MAXN ) { pos = w.getl ( 1 , 1 , n , 1 , sr ) ; }
        if ( pos >= x ) {
            ans += w.query ( 1 , 1 , n , x , pos ) ;
        }
        else {
            ans += w.query ( 1 , 1 , n , x , n ) ;
            ans += w.query ( 1 , 1 , n , 1 , pos ) ;
        }
        w.update ( 1 , 1 , n , pos , -1 ) ;
        x = pos + 1 ;
        if ( x == ( n + 1 ) ) { x = 1 ; }
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
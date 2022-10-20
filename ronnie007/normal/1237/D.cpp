#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

#define MAXN 300007

int n ;
int a[ MAXN ] ;
int mn_id[ MAXN ] ;

int ans[ MAXN ] ;
int stk[ MAXN ] ;
int tpsz ;

class Tree {
    public :
    int mx[ 10 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            mx[ where ] = mn_id[ IL ] ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        mx[ where ] = max ( mx[ 2 * where ] , mx[ 2 * where + 1 ] ) ;
    }
    int getl ( int where , int IL , int IR , int pos , int sr ) {
        if ( IR < pos ) { return MAXN ; }
        if ( mx[ where ] < sr ) { return MAXN ; }
        if ( IL == IR ) { return IL ; }
        int mid = ( IL + IR ) / 2 ;
        int ret = getl ( 2 * where , IL , mid , pos , sr ) ;
        if ( ret == MAXN ) { return getl ( 2 * where + 1 , mid + 1 , IR , pos , sr ) ; }
        return ret ;
    }
};

Tree w ;

int get ( int sr ) {
    int l , r , mid ;
    l = 1 ;
    r = tpsz ;
    if ( a[ stk[ l ] ] < sr ) { return 0 ; }
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( a[ stk[ mid ] ] < sr ) { r = mid ; }
        else { l = mid ; }
    }
    while ( a[ stk[ r ] ] < sr ) { -- r ; }
    return stk[ r ] ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        a[ n + i ] = a[ n + n + i ] = a[ i ] ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= 3 * n ; ++ i ) {
        while ( tpsz > 0 && a[ i ] >= a[ stk[ tpsz ] ] ) { -- tpsz ; }
        stk[ ++ tpsz ] = i ;
        mn_id[ i ] = get ( 2 * a[ i ] + 1 ) ;
    }
    w.init ( 1 , 1 , 3 * n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int ret = w.getl ( 1 , 1 , 3 * n , i , i ) ;
        if ( ret != MAXN ) { printf ( "%d " , ret - i ) ; }
        else { printf ( "-1 " ) ; }
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
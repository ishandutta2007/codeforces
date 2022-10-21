#include<bits/stdc++.h>
using namespace std ;

#define MAXN 35007

int n , k ;
int a[ MAXN ] ;
int prv[ MAXN ] ;

int lst[ MAXN ] ;

int dp[ 2 ][ MAXN ] ;

class Tree {
public :
    int tr[ 4 * MAXN ] ;
    int lazy[ 4 * MAXN ] ;

    void push_lazy ( int where , int IL , int IR ) {
        tr[ where ] += lazy[ where ] ;
        if ( IL != IR ) {
            lazy[ 2 * where ] += lazy[ where ] ;
            lazy[ 2 * where + 1 ] += lazy[ where ] ;
        }
        lazy[ where ] = 0 ;
    }
    void init ( int where , int IL , int IR , int id ) {
        lazy[ where ] = 0 ;
        if ( IL == IR ) {
            tr[ where ] = dp[ id ][ IL ] ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid , id ) ;
        init ( 2 * where + 1 , mid + 1 , IR , id ) ;
        tr[ where ] = max ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( CURL > CURR ) { return ; }
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            ++ lazy[ where ] ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
        tr[ where ] = max ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    int query ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( CURL > CURR ) { return 0 ; }
        if ( IR < CURL || CURR < IL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return max ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};
Tree w ;

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        prv[ i ] = lst[ a[ i ] ] ;
        lst[ a[ i ] ] = i ;
    }
}

void solve ( ) {
    int old = 0 ;
    int nw = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        dp[ old ][ i ] = dp[ old ][ i - 1 ] ;
        if ( prv[ i ] == 0 ) { ++ dp[ old ][ i ] ; }
    }
    for ( int j = 2 ; j <= k ; ++ j ) {
        w.init ( 1 , 1 , n , old ) ;
        for ( int i = j ; i <= n ; ++ i ) {
            w.update ( 1 , 1 , n , prv[ i ] , i - 1 ) ;
            dp[ nw ][ i ] = w.query ( 1 , 1 , n , 1 , i - 1 ) ;
        }
        for ( int i = 1 ; i <= n ; ++ i ) {
            dp[ old ][ i ] = 0 ;
        }
        old ^= 1 ; nw ^= 1 ;
    }
    printf ( "%d\n" , dp[ old ][ n ] ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
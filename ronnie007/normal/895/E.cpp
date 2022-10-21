#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
using namespace std ;

#define MAXN 100007

int n , q ;
int a[ MAXN ] ;

class Tree {
    public :
    double tr[ 5 * MAXN ] ;
    double lazymul[ 5 * MAXN ] ;
    double lazyadd[ 5 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        lazymul[ where ] = 1 ;
        lazyadd[ where ] = 0 ;
        if ( IL == IR ) { tr[ where ] = a[ IL ] ; return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        merge ( where ) ;
    }
    void push_lazy ( int where , int IL , int IR ) {
        if ( lazymul[ where ] != 1 ) {
            tr[ where ] = ( tr[ where ] * lazymul[ where ] ) ;
            if ( IL != IR ) {
                lazymul[ 2 * where ] *= lazymul[ where ] ;
                lazyadd[ 2 * where ] *= lazymul[ where ] ;
                lazymul[ 2 * where + 1 ] *= lazymul[ where ] ;
                lazyadd[ 2 * where + 1 ] *= lazymul[ where ] ;
            }
            lazymul[ where ] = 1 ;
        }
        if ( lazyadd[ where ] != 0 ) {
            tr[ where ] = tr[ where ] + ( IR - IL + 1 ) * lazyadd[ where ] ;
            if ( IL != IR ) {
                lazyadd[ 2 * where ] += lazyadd[ where ] ;
                lazyadd[ 2 * where + 1 ] += lazyadd[ where ] ;
            }
            lazyadd[ where ] = 0 ;
        }
    }
    void merge ( int where ) {
        tr[ where ] = tr[ 2 * where ] + tr[ 2 * where + 1 ] ;
        lazymul[ where ] = 1 ;
        lazyadd[ where ] = 0 ;
    }
    void update_mul ( int where , int IL , int IR , int CURL , int CURR , double val ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazymul[ where ] *= val ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update_mul ( 2 * where , IL , mid , CURL , CURR , val ) ;
        update_mul ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
        merge ( where ) ;
    }
    void update_add ( int where , int IL , int IR , int CURL , int CURR , double val ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazyadd[ where ] += val ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update_add ( 2 * where , IL , mid , CURL , CURR , val ) ;
        update_add ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
        merge ( where ) ;
    }
    double query ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < CURL || CURR < IL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return ( query ( 2 * where , IL , mid , CURL , CURR ) + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};
Tree w ;

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    w.init ( 1 , 1 , n ) ;
}

void solve ( ) {
    int type ;
    int x , y , z , t ;
    while ( q != 0 ) {
        q -- ;
        scanf ( "%d" , &type ) ;
        if ( type == 1 ) {
            scanf ( "%d%d%d%d" , &x , &y , &z , &t ) ;
            double sm1 , sm2 ;
            sm1 = w.query ( 1 , 1 , n , x , y ) ;
            sm2 = w.query ( 1 , 1 , n , z , t ) ;
            double len1 = ( y - x + 1 ) ;
            double len2 = ( t - z + 1 ) ;
            w.update_mul ( 1 , 1 , n , x , y , ( len1 - 1 ) / len1 ) ;
            w.update_mul ( 1 , 1 , n , z , t , ( len2 - 1 ) / len2 ) ;
            w.update_add ( 1 , 1 , n , x , y , sm2 / ( len2 * len1 ) ) ;
            w.update_add ( 1 , 1 , n , z , t , sm1 / ( len1 * len2 ) ) ;
        }
        else {
            scanf ( "%d%d" , &x , &y ) ;
            printf ( "%.12f\n" , w.query ( 1 , 1 , n , x , y ) ) ;
        }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
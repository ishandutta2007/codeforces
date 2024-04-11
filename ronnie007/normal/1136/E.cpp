#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<cstdlib>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;
int b[ MAXN ] ;
long long pref[ MAXN ] ;
long long sq[ MAXN ] ;


class Tree {
    public :
    static const int SIZE = 5 * MAXN ;
    long long tr[ SIZE ] ;
    long long mx[ SIZE ] ;
    long long mn[ SIZE ] ;
    long long lazy[ SIZE ] ;
    bool trigger[ SIZE ] ;
    void init ( int where , int IL , int IR ) {
        lazy[ where ] = 0 ;
        trigger[ where ] = false ;
        if ( IL == IR ) {
            tr[ where ] = mx[ where ] = mn[ where ] = a[ IL ] - pref[ IL - 1 ] ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = ( tr[ 2 * where ] + tr[ 2 * where + 1 ] ) ;
        mx[ where ] = max ( mx[ 2 * where ] , mx[ 2 * where + 1 ] ) ;
        mn[ where ] = min ( mn[ 2 * where ] , mn[ 2 * where + 1 ] ) ;
    }
    void push_lazy ( int where , int IL , int IR ) {
        if ( trigger[ where ] == false ) { return ; }
        trigger[ where ] = false ;
        tr[ where ] = ( IR - IL + 1 ) * lazy[ where ] ;
        mx[ where ] = mn[ where ] = lazy[ where ] ;
        if ( IL != IR ) {
            lazy[ 2 * where ] = lazy[ 2 * where + 1 ] = lazy[ where ] ;
            trigger[ 2 * where ] = trigger[ 2 * where + 1 ] = true ;
        }
    }
    void update ( int where , int IL , int IR , int pos , long long val ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < pos ) { return ; }
        if ( mn[ where ] >= val ) { return ; }
        if ( IL >= pos && mx[ where ] <= val ) {
            lazy[ where ] = val ;
            trigger[ where ] = true ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , pos , val ) ;
        update ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
        tr[ where ] = ( tr[ 2 * where ] + tr[ 2 * where + 1 ] ) ;
        mx[ where ] = max ( mx[ 2 * where ] , mx[ 2 * where + 1 ] ) ;
        mn[ where ] = min ( mn[ 2 * where ] , mn[ 2 * where + 1 ] ) ;
    }
    long long query ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < CURL || CURR < IL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) {
            return tr[ where ] ;
        }
        int mid = ( IL + IR ) / 2 ;
        return ( query ( 2 * where , IL , mid , CURL , CURR ) + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};

Tree w ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( i = 1 ; i < n ; i ++ ) {
        scanf ( "%d" , &b[ i ] ) ;
        pref[ i ] = pref[ i - 1 ] + b[ i ] ;
        sq[ i ] = sq[ i - 1 ] + pref[ i ] ;
    }
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    int q ;
    scanf ( "%d" , &q ) ;
    while ( q != 0 ) {
        q -- ;
        char c ;
        int x , y ;
        scanf ( "\n%c%d%d" , &c , &x , &y ) ;
        if ( c == '+' ) {
            long long aux = w.query ( 1 , 1 , n , x , x ) ;
            w.update ( 1 , 1 , n , x , aux + y ) ;
        }
        else {
            long long aux = w.query ( 1 , 1 , n , x , y ) ;
            aux += sq[ y - 1 ] ;
            if ( x >= 2 ) {
                aux -= sq[ x - 2 ] ;
            }
            printf ( "%I64d\n" , aux ) ;
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
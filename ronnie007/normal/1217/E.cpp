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

#define inf 2000000007
#define MAXN 200007
#define dig 10

int n , m ;
int a[ MAXN ] ;

struct tuhla {
    long long sm[ 11 ][ 3 ] ;
    tuhla ( ) {
        for ( int i = 0 ; i < dig ; ++ i ) {
            sm[ i ][ 0 ] = 0 ;
            for ( int j = 1 ; j < 3 ; ++ j ) {
                sm[ i ][ j ] = inf ;
            }
        }
    }
    tuhla ( int x ) {
        for ( int i = 0 ; i < dig ; ++ i ) {
            sm[ i ][ 0 ] = 0 ;
            sm[ i ][ 2 ] = inf ;
        }
        int init = x ;
        for ( int i = 0 ; i < dig ; ++ i ) {
            int h = ( x % 10 ) ;
            x /= 10 ;
            if ( h > 0 ) {
                sm[ i ][ 1 ] = init ;
            }
            else {
                sm[ i ][ 1 ] = inf ;
            }
        }
    }
};

tuhla merge ( tuhla p1 , tuhla p2 ) {
    tuhla ret = tuhla ( ) ;
    for ( int i = 0 ; i < dig ; ++ i ) {
        for ( int j = 1 ; j <= 2 ; ++ j ) {
            for ( int t = 0 ; t <= j ; ++ t ) {
                ret.sm[ i ][ j ] = min ( ret.sm[ i ][ j ] , p1.sm[ i ][ t ] + p2.sm[ i ][ j - t ] ) ;
            }
        }
    }
    return ret ;
}

tuhla ans ;

class Tree {
    public :
    tuhla tr[ 5 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            tr[ where ] = tuhla ( a[ IL ] ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    void update ( int where , int IL , int IR , int pos , int val ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ] = tuhla ( val ) ;
            return ;
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
    void query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( CURR < IL || IR < CURL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            ans = merge ( ans , tr[ where ] ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        query ( 2 * where , IL , mid , CURL , CURR ) ;
        query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
    }
};

Tree w ;

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    while ( m -- ) {
        int type , x , y ;
        scanf ( "%d%d%d" , &type , &x , &y ) ;
        if ( type == 1 ) {
            w.update ( 1 , 1 , n , x , y ) ;
        }
        else {
            ans = tuhla ( ) ;
            w.query ( 1 , 1 , n , x , y ) ;
            long long ww = inf ;
            for ( int i = 0 ; i < dig ; ++ i ) {
                ww = min ( ww , ans.sm[ i ][ 2 ] ) ;
            }
            if ( ww >= inf ) { printf ( "-1\n" ) ; }
            else { printf ( "%I64d\n" , ww ) ; }
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
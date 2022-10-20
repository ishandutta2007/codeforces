#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 120007

int n , q ;
long long a[ MAXN ] , b[ MAXN ] , c[ MAXN ] ;

struct node {
    long long mx , mn , sm ;
    node ( ) { mx = mn = sm = 0 ; }
};

node merge ( node p1 , node p2 ) {
    node ret = node ( ) ;
    ret.sm = p1.sm + p2.sm ;
    ret.mx = max ( p1.mx , p1.sm + p2.mx ) ;
    ret.mn = min ( p1.mn , p1.sm + p2.mn ) ;
    return ret ;
}

class Tree {
public :
    node tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = node ( ) ;
        if ( IL == IR ) {
            tr[ where ].sm += c[ IL ] ;
            tr[ where ].mn = min ( tr[ where ].mn , tr[ where ].sm ) ;
            tr[ where ].mx = max ( tr[ where ].mx , tr[ where ].sm ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    node query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IL > IR || CURL > CURR ) { return node ( ) ; }
        if ( IR < CURL || CURR < IL ) { return node ( ) ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return merge ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};
Tree w ;

void input ( ) {
    cin >> n >> q ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> b[ i ] ;
        c[ i ] = a[ i ] - b[ i ] ;
    }
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    for ( int i = 1 ; i <= q ; ++ i ) {
        int l , r ;
        cin >> l >> r ;
        node ret = w.query ( 1 , 1 , n , l , r ) ;
        if ( ret.mx > 0 || ret.sm != 0 ) {
            cout << "-1\n" ;
            continue ;
        }
        cout << -ret.mn << "\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
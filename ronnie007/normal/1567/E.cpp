#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 200007

int n , q ;
int a[ MAXN ] ;

struct node {
    long long ans = 0 ;
    long long pref , suff ;
    int l , r ;
    node ( ) {
        ans = pref = suff = -1 ;
        l = r = 0 ;
    }
    node ( int pos ) {
        ans = pref = suff = 1 ;
        l = r = pos ;
    }
};

node merge ( node p1 , node p2 ) {
    if ( p1.ans < 0 ) { return p2 ; }
    if ( p2.ans < 0 ) { return p1 ; }
    node ret ;
    ret.l = p1.l , ret.r = p2.r ;
    ret.ans = p1.ans + p2.ans ;
    if ( a[ p1.r ] <= a[ p2.l ] ) {
        ret.ans += p1.suff * p2.pref ;
    }

    if ( a[ p1.r ] <= a[ p2.l ] && p1.pref == p1.r - p1.l + 1 ) {
        ret.pref = p1.pref + p2.pref ;
    }
    else {
        ret.pref = p1.pref ;
    }

    if ( a[ p1.r ] <= a[ p2.l ] && p2.suff == p2.r - p2.l + 1 ) {
        ret.suff = p1.suff + p2.suff ;
    }
    else {
        ret.suff = p2.suff ;
    }
    return ret ;
}

class Tree {
public :
    node tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            tr[ where ] = node ( IL ) ;
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
            a[ IL ] = val ;
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
    w.init ( 1 , 1 , n ) ;
}

void solve ( ) {
    while ( q -- ) {
        int type , x , y ;
        cin >> type >> x >> y ;
        if ( type == 1 ) {
            w.update ( 1 , 1 , n , x , y ) ;
        }
        else {
            node hh = w.query ( 1 , 1 , n , x , y ) ;
            cout << hh.ans << "\n" ;
        }
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
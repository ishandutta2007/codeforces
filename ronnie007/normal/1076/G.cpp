#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n , m , q ;
int a[ MAXN ] ;
int lim ;

struct node {
    int id ;
    int f[ 2 ][ 32 ] ;
    node ( ) {
        id = 0 ;
        for ( int pos = 0 ; pos < 2 ; ++ pos ) {
            for ( int i = 0 ; i <= lim ; ++ i ) {
                f[ pos ][ i ] = i ;
            }
        }
    }
    node ( int x ) {
        id = 0 ;
        for ( int i = 0 ; i <= lim ; ++ i ) {
            if ( i < lim || x == 0 ) {
                f[ 0 ][ i ] = 1 + ( ( i << 1 ) & lim ) ;
            }
            else {
                f[ 0 ][ i ] = ( ( i << 1 ) & lim ) ;
            }

            if ( i < lim || x == 1 ) {
                f[ 1 ][ i ] = 1 + ( ( i << 1 ) & lim ) ;
            }
            else {
                f[ 1 ][ i ] = ( ( i << 1 ) & lim ) ;
            }            
        }
    }
};

node merge ( node p1 , node p2 ) {
    node ret ;
    ret.id = p1.id ;
    for ( int i = 0 ; i <= lim ; ++ i ) {
        ret.f[ ret.id ][ i ] = p1.f[ p1.id ][ p2.f[ p2.id ][ i ] ] ;
        ret.f[ ret.id ^ 1 ][ i ] = p1.f[ p1.id ^ 1 ][ p2.f[ p2.id ^ 1 ][ i ] ] ;
    }
    return ret ;
}

class Tree {
public :
    node tr[ 4 * MAXN ] ;
    int lazy[ 4 * MAXN ] ;
    void push_lazy ( int where , int IL , int IR ) {
        tr[ where ].id ^= lazy[ where ] ;
        if ( IL != IR ) {
            lazy[ 2 * where ] ^= lazy[ where ] ;
            lazy[ 2 * where + 1 ] ^= lazy[ where ] ;
        }
        lazy[ where ] ^= lazy[ where ] ;
    }
    void init ( int where , int IL , int IR ) {
        lazy[ where ] = 0 ;
        if ( IL == IR ) {
            tr[ where ] = node ( a[ IL ] ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( IL > IR || CURL > CURR ) { return ; }
        if ( CURR < IL || IR < CURL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazy[ where ] ^= 1 ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR ) ;
        update ( 2 * where + 1 , mid + 1, IR , CURL , CURR ) ;
        tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    node query ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( IL > IR || CURL > CURR ) { return node ( ) ; }
        if ( CURR < IL || IR < CURL ) { return node ( ) ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return merge ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};
Tree w ;

void input ( ) {
    cin >> n >> m >> q ;
    lim = ( 1 << m ) - 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        long long x ; cin >> x ;
        a[ i ] = ( x % 2 ) ;
    }
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    while ( q -- ) {
        int t ;
        int l , r ;
        long long val ;
        cin >> t >> l >> r ;
        if ( t == 1 ) {
            cin >> val ;
            if ( ( val % 2 ) == 1 ) {
                w.update ( 1 , 1 , n , l , r ) ;
            }
        }
        else {
            node ret = w.query ( 1 , 1 , n , l , r ) ;
            cout << ( ( ret.f[ ret.id ][ lim ] % 2 ) ^ 1 ) + 1 << "\n" ;
        }
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
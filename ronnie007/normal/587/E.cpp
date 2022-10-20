#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n , q ;
int a[ MAXN ] ;
int b[ MAXN ] ;

struct node {
    int sz ;
    vector < int > v ;
    void add ( int x ) {
        for ( int i = 0 ; i < sz ; ++ i ) {
            int bit = v[ i ] - ( v[ i ] & ( v[ i ] - 1 ) ) ;
            if ( ( x & bit ) > 0 ) {
                x ^= v[ i ] ;
            }
        }
        if ( x != 0 ) {
            ++ sz ;
            v.push_back ( x ) ;
            int bit = ( x - ( x & ( x - 1 ) ) ) ;
            for ( int i = 0 ; i < sz - 1 ; ++ i ) {
                if ( ( v[ i ] & bit ) > 0 ) {
                    v[ i ] ^= x ;
                }
            }
        }
    }
};

node unite ( node &p1 , node &p2 ) {
    node ret ;
    ret.sz = 0 ; ret.v.clear ( ) ;
    for ( int i = 0 ; i < p1.sz ; ++ i ) {
        ret.add ( p1.v[ i ] ) ;
    }
    for ( int i = 0 ; i < p2.sz ; ++ i ) {
        ret.add ( p2.v[ i ] ) ;
    }
    return ret ;
}

node ans ;

class BasisTree {
public :
    node tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            tr[ where ].add ( b[ IL ] ) ; 
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = unite ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    void update ( int where , int IL , int IR , int pos , int val ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            b[ IL ] ^= val ;
            tr[ where ].sz = 0 ;
            tr[ where ].v.clear ( ) ;
            tr[ where ].add ( b[ IL ] ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , val ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
        }
        tr[ where ] = unite ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    void query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            ans = unite ( ans , tr[ where ] ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        query ( 2 * where , IL , mid , CURL , CURR ) ;
        query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
    }
};
BasisTree w ;

class ValueTree {
public :
    int tr[ 4 * MAXN ] ;
    int lazy[ 4 * MAXN ] ;
    void push_lazy ( int where , int IL , int IR ) {
        if ( lazy[ where ] == 0 ) { return ; }
        if ( IL == IR ) { tr[ where ] ^= lazy[ where ] ; }
        else {
            lazy[ 2 * where ] ^= lazy[ where ] ;
            lazy[ 2 * where + 1 ] ^= lazy[ where ] ;
        }
        lazy[ where ] = 0 ;
    }
    void init ( int where , int IL , int IR ) {
        lazy[ where ] = tr[ where ] = 0 ;
        if ( IL == IR ) {
            tr[ where ] = a[ IL ] ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR , int val ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazy[ where ] ^= val ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR , val ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
    }
    int query ( int where , int IL , int IR , int pos ) {
        push_lazy ( where , IL , IR ) ;
        if ( IL == IR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            return query ( 2 * where , IL , mid , pos ) ;
        }
        else {
            return query ( 2 * where + 1 , mid + 1 , IR , pos ) ;
        }
    }
};
ValueTree aux ;

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        b[ i ] = ( a[ i ] ^ a[ i - 1 ] ) ;
    }
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    aux.init ( 1 , 1 , n ) ;
    int type , l , r , val ;
    while ( q -- ) {
        scanf ( "%d" , &type ) ;
        if ( type == 1 ) {
            scanf ( "%d%d%d" , &l , &r , &val ) ;
            aux.update ( 1 , 1 , n , l , r , val ) ;
            w.update ( 1 , 1 , n , l , val ) ;
            w.update ( 1 , 1 , n , r + 1 , val ) ;
        }
        else {
            scanf ( "%d%d" , &l , &r ) ;
            ans.sz = 0 ;
            ans.v.clear ( ) ;
            w.query ( 1 , 1 , n , l + 1 , r ) ;
            ans.add ( aux.query ( 1 , 1 , n , l ) ) ;
            printf ( "%d\n" , (1<<(ans.v.size ( ) ) ) ) ;
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
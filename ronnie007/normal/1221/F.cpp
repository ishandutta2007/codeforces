#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007

int n ;
struct tuhla {
    int x , y ;
    int c ;
};

tuhla a[ MAXN ] ;
long long inf ;
map < int , int > hh ;
int rev[ MAXN ] ;

vector < int > l_end[ MAXN ] ;

int MAXVAL ;

class Tree {
public :
    pair < long long , int > tr[ 4 * MAXN ] ;
    long long lazy[ 4 * MAXN ] ;
    void push_lazy ( int where , int IL , int IR ) {
        if ( lazy[ where ] == 0 ) { return ; }
        tr[ where ].first += lazy[ where ] ;
        if ( IL != IR ) {
            lazy[ 2 * where ] += lazy[ where ] ;
            lazy[ 2 * where + 1 ] += lazy[ where ] ;
        }
        lazy[ where ] = 0 ;
    }
    void unite ( int where ) {
        tr[ where ] = max ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            tr[ where ] = { - rev[ IL ] , IL } ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        unite ( where ) ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR , int add ) {
        push_lazy ( where , IL , IR ) ;
        if ( IL > IR || CURL > CURR ) { return ; }
        if ( CURR < IL || IR < CURL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazy[ where ] += add ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR , add ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , add ) ;
        unite ( where ) ;
    }
    pair < long long , int > query ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( IL > IR || CURL > CURR ) { return { - inf , 0 } ; }
        if ( CURR < IL || IR < CURL ) { return { - inf , 0 } ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return max ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};
Tree w ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    set < int > s ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d%d%d" , &a[ i ].x , &a[ i ].y , &a[ i ].c ) ;
        if ( a[ i ].x > a[ i ].y ) { swap ( a[ i ].x , a[ i ].y ) ; }
        s.insert ( a[ i ].x ) ; s.insert ( a[ i ].y ) ;
    }
    int id = 1 ;
    for ( auto it = s.begin ( ) ; it != s.end ( ) ; ++ it ) {
        hh[ (*it) ] = id ;
        rev[ id ++ ] = (*it) ;
    }
    MAXVAL = id - 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        a[ i ].x = hh[ a[ i ].x ] ;
        a[ i ].y = hh[ a[ i ].y ] ;
        l_end[ a[ i ].x ].push_back ( i ) ;
    }
    inf = 1 ;
    for ( int i = 1 ; i <= 15 ; ++ i ) { inf *= 10 ; }
}

void solve ( ) {
    w.init ( 1 , 1 , MAXVAL ) ;
    long long ans = -inf ;
    int pos1 , pos2 ;
    for ( int i = MAXVAL ; i >= 0 ; -- i ) {
        int sz = l_end[ i ].size ( ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            int id = l_end[ i ][ j ] ;
            w.update ( 1 , 1 , MAXVAL , a[ id ].y , MAXVAL , a[ id ].c ) ;
        }
        pair < long long , int > ret = w.query ( 1 , 1 , MAXVAL , i , MAXVAL ) ;
        ret.first += rev[ i ] ;
        if ( ans < ret.first ) {
            ans = ret.first ;
            pos1 = rev[ i ] ; pos2 = rev[ ret.second ] ;
        }
    }
    if ( ans < 0 ) {
        ans = 0 ;
        pos1 = pos2 = 1e9 + 5 ;
    }
    printf ( "%lld\n" , ans ) ;
    printf ( "%d %d %d %d\n" , pos1 , pos1 , pos2 , pos2 ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007
#define LOG 20

int n , q ;
vector < int > v[ MAXN ] ;

int LCA[ MAXN ][ LOG ] ;
int lvl[ MAXN ] ;

int tpsz ;
int st[ MAXN ] ;
int en[ MAXN ] ;

int rv[ MAXN ] ;

void add_fst ( pair < int , int > &aux , int sr ) {
    if ( sr == 0 ) { return ; }
    if ( aux.first == 0 || aux.first > sr ) {
        aux.second = aux.first ;
        aux.first = sr ;
    }
    else if ( aux.second == 0 || aux.second > sr ) {
        aux.second = sr ;
    }
}

void add_lst ( pair < int , int > &aux , int sr ) {
    if ( sr == 0 ) { return ; }
    if ( aux.first == 0 || aux.first < sr ) {
        aux.second = aux.first ;
        aux.first = sr ;
    }
    else if ( aux.second == 0 || aux.second < sr ) {
        aux.second = sr ; 
    }
}

pair < int , int > total_min , total_max ;

class Tree {
public :
    pair < int , int > tr_min[ 4 * MAXN ] ;
    pair < int , int > tr_max[ 4 * MAXN ] ;

    void unite ( int where ) {
        int l = 2 * where , r = 2 * where + 1 ; 
        tr_min[ where ] = tr_min[ l ] ;
        add_fst ( tr_min[ where ] , tr_min[ r ].first ) ;
        add_fst ( tr_min[ where ] , tr_min[ r ].second ) ;

        tr_max[ where ] = tr_max[ l ] ;
        add_lst ( tr_max[ where ] , tr_max[ r ].first ) ;
        add_lst ( tr_max[ where ] , tr_max[ r ].second ) ;
    }
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            tr_min[ where ] = { st[ IL ] , 0 } ;
            tr_max[ where ] = { st[ IL ] , 0 } ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        unite ( where ) ;
    }
    void query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( CURL > CURR ) { return ; }
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            add_fst ( total_min , tr_min[ where ].first ) ;
            add_fst ( total_min , tr_min[ where ].second ) ;

            add_lst ( total_max , tr_max[ where ].first ) ;
            add_lst ( total_max , tr_max[ where ].second ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        query ( 2 * where , IL , mid , CURL , CURR ) ;
        query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
    }
};
Tree w ;

void dfs ( int vertex ) {
    st[ vertex ] = ++ tpsz ;
    rv[ tpsz ] = vertex ;
    for ( int i = 1 ; i < LOG ; ++ i ) {
        LCA[ vertex ][ i ] = LCA[ LCA[ vertex ][ i - 1 ] ][ i - 1 ] ;
    }
    
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        LCA[ v[ vertex ][ i ] ][ 0 ] = vertex ;
        lvl[ v[ vertex ][ i ] ] = lvl[ vertex ] + 1 ;
        dfs ( v[ vertex ][ i ] ) ;
    }
    en[ vertex ] = tpsz ;
}

bool check ( int vertex , int l , int r ) {
    if ( vertex == 0 ) { return true ; }
    if ( st[ vertex ] <= l && r <= en[ vertex ] ) { return true ; }
    return false ;
}

int get ( int vertex , int l , int r ) {
    for ( int i = LOG - 1 ; i >= 0 ; -- i ) {
        if ( check ( LCA[ vertex ][ i ] , l , r ) == false ) {
            vertex = LCA[ vertex ][ i ] ;
        }
    }
    if ( check ( vertex , l , r ) == true ) { return vertex ; }
    return LCA[ vertex ][ 0 ] ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        int x ;
        scanf ( "%d" , &x ) ;
        v[ x ].push_back ( i ) ;
    }
}

void solve ( ) {
    lvl[ 1 ] = 0 ;
    dfs ( 1 ) ;
    w.init ( 1 , 1 , n ) ;
    while ( q -- ) {
        int l , r ;
        scanf ( "%d%d" , &l , &r ) ;
        total_min = total_max = { 0 , 0 } ;
        w.query ( 1 , 1 , n , l , r ) ;

        int ans1 = get ( rv[ total_min.second ] , total_min.second , total_max.first ) ;
        int ans2 = get ( rv[ total_max.second ] , total_min.first , total_max.second ) ;
        
        if ( lvl[ ans1 ] >= lvl[ ans2 ] ) {
            printf ( "%d %d\n" , rv[ total_min.first ] , lvl[ ans1 ] ) ;
        }
        else {
            printf ( "%d %d\n" , rv[ total_max.first ] , lvl[ ans2 ] ) ;
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
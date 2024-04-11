#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007
#define inf 10000007

int n , q , sr ;
int a[ MAXN ] ;

struct node {
    long long sm ;
    vector < pair < int , int > > pref ;
    vector < pair < int , int > > suff ;
    node ( ) {
        sm = 0 ;
        pref.clear ( ) ;
        suff.clear ( ) ;
    }
};

node merge ( node &p1 , node &p2 ) {
    if ( p1.pref.empty ( ) == true ) { return p2 ; }
    if ( p2.pref.empty ( ) == true ) { return p1 ; }
    node ret ;
    ret.sm = p1.sm + p2.sm ;
    int sz1 = p1.suff.size ( ) ;
    int sz2 = p2.pref.size ( ) ;
    int id = sz1 - 1 ;
    for ( int i = 0 ; i < sz2 - 1 ; ++ i ) {
        int len = ( p2.pref[ i + 1 ].first - p2.pref[ i ].first ) ;
        while ( id > 0 && ( p1.suff[ id - 1 ].second | p2.pref[ i ].second ) >= sr ) { -- id ; }
        if ( p1.suff[ id ].second | p2.pref[ i ].second >= sr ) {
            ret.sm += 1LL * len * ( p1.suff[ id ].first - p1.suff.back ( ).first ) ;
        }
    }
    ret.pref = p1.pref ;
    ret.suff = p2.suff ;
    
    ret.pref.pop_back ( ) ;
    ret.suff.pop_back ( ) ;
    
    int aux = p2.pref.size ( ) ;
    int hh = p1.pref[ p1.pref.size ( ) - 2 ].second ;
    for ( int i = 0 ; i < aux - 1 ; ++ i ) {
        if ( ( hh | p2.pref[ i ].second ) > hh ) {
            hh |= p2.pref[ i ].second ;
            ret.pref.push_back ( { p2.pref[ i ].first , hh } ) ;
        }
    }
    aux = p1.suff.size ( ) ;
    hh = p2.suff[ p2.suff.size ( ) - 2 ].second ;
    for ( int i = 0 ; i < aux - 1 ; ++ i ) {
        if ( ( hh | p1.suff[ i ].second ) > hh ) {
            hh |= p1.suff[ i ].second ;
            ret.suff.push_back ( { p1.suff[ i ].first , hh } ) ;
        }
    }
    ret.pref.push_back ( p2.pref.back ( ) ) ;
    ret.suff.push_back ( p1.suff.back ( ) ) ;
    return ret ;
}

node ans ;

class Tree {
public :
    node tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            tr[ where ].sm = ( a[ IL ] >= sr ) ;
            tr[ where ].pref.push_back ( { IL , a[ IL ] } ) ;
            tr[ where ].pref.push_back ( { IL + 1 , inf } ) ;
            tr[ where ].suff.push_back ( { IL , a[ IL ] } ) ;
            tr[ where ].suff.push_back ( { IL - 1 , inf } ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    void update ( int where , int IL , int IR , int pos ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ].sm = ( a[ IL ] >= sr ) ;
            tr[ where ].pref.clear ( ) ; tr[ where ].suff.clear ( ) ;
            tr[ where ].pref.push_back ( { IL , a[ IL ] } ) ;
            tr[ where ].pref.push_back ( { IL + 1 , inf } ) ;
            tr[ where ].suff.push_back ( { IL , a[ IL ] } ) ;
            tr[ where ].suff.push_back ( { IL - 1 , inf } ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos ) ;
        }
        tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    void query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IR < CURL || CURR < IL ) { return ; }
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
    cin >> n >> q >> sr ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    int type , x , y ;
    while ( q -- ) {
        cin >> type >> x >> y ;
        if ( type == 1 ) {
            a[ x ] = y ;
            w.update ( 1 , 1 , n , x ) ;
        }
        else {
            ans = node ( ) ;
            w.query ( 1 , 1 , n , x , y ) ;
            cout << ans.sm << "\n" ;
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
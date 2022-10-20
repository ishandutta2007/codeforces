#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int MAXN = 2e5 + 7 ;
const ll MAXVAL = 1e9 ;
const ll inf = 1e15 ;

ll n , lim ;
ll pos[ MAXN ] , len[ MAXN ] ;


struct node {
    ll sm , coef ;
    ll mxval , mx_plus1 , mx_minus1 ;
    int to[ 2 ] ;
    node ( ) {
        sm = coef = 0 ;
        mxval = mx_plus1 = mx_minus1 = 0 ;
        to[ 0 ] = to[ 1 ] = 0 ;
    }
};

int tp ;
node tr[ 12 * MAXN ] ;

set < int > s ;
map < int , int > w ;
ll rval[ 10 * MAXN ] ;


ll eval ( ll pos , ll sm , ll coef , ll mod ) {
    ll ret = sm ;
    ret += ( coef + mod ) * pos ;
    return ret ;
}

void init ( int where , int IL , int IR ) {
    tr[ where ] = node ( ) ;
    if ( IL == IR ) { return ; }
    int mid = ( IL + IR ) / 2 ;
    init ( 2 * where , IL , mid ) ;
    init ( 2 * where + 1 , mid + 1 , IR ) ;
}

void update ( int where , int IL , int IR , int CURL , int CURR , int add_sm , int add_coef ) {
    if ( IL > IR || CURL > CURR ) { return ; }
    if ( IR < CURL || CURR < IL ) { return ; }
    if ( CURL <= IL && IR <= CURR ) {
        tr[ where ].sm += add_sm ;
        tr[ where ].coef += add_coef ;
        return ;
    }
    int mid = ( IL + IR ) / 2 ;
    update ( 2 * where , IL , mid , CURL , CURR , add_sm , add_coef ) ;
    update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , add_sm , add_coef ) ;
}

ll query ( int where , int IL , int IR , int CURL , int CURR , int type ) {
    if ( IL > IR || CURL > CURR ) { return -inf ; }
    if ( IR < CURL || CURR < IL ) { return -inf ; }
    if ( CURL <= IL && IR <= CURR ) {
        if ( type == -1 ) { return tr[ where ].mx_minus1 ; }
        if ( type == 0 ) { return tr[ where ].mxval ; }
        if ( type == 1 ) { return tr[ where ].mx_plus1 ; }
        return -inf ;
    }
    int mid = ( IL + IR ) / 2 ;
    ll ret = -inf ;
    ret = max ( ret , query ( 2 * where , IL , mid , CURL , CURR , type ) ) ;
    ret = max ( ret , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , type ) ) ;
    return ret ;
}

void push_down ( int i , int IL , int IR ) {
    if ( IL != IR ) {
        tr[ 2 * i ].sm += tr[ i ].sm ;
        tr[ 2 * i ].coef += tr[ i ].coef ;

        tr[ 2 * i + 1 ].sm += tr[ i ].sm ;
        tr[ 2 * i + 1 ].coef += tr[ i ].coef ;
    }
    else {
        tr[ i ].mxval = max ( eval ( rval[ IL ] , tr[ i ].sm , tr[ i ].coef , 0 ) , eval ( rval[ IR ] , tr[ i ].sm , tr[ i ].coef , 0 ) ) ;
        tr[ i ].mx_plus1 = max ( eval ( rval[ IL ] , tr[ i ].sm , tr[ i ].coef , 1 ) , eval ( rval[ IR ] , tr[ i ].sm , tr[ i ].coef , 1 ) ) ;
        tr[ i ].mx_minus1 = max ( eval ( rval[ IL ] , tr[ i ].sm , tr[ i ].coef , -1 ) , eval ( rval[ IR ] , tr[ i ].sm , tr[ i ].coef , -1 ) ) ;
        return ;
    }
    int mid = ( IL + IR ) / 2 ;
    push_down ( 2 * i , IL , mid ) ;
    push_down ( 2 * i + 1 , mid + 1 , IR ) ;
    int l = 2 * i , r = 2 * i + 1 ;
    tr[ i ].mxval = max ( tr[ l ].mxval , tr[ r ].mxval ) ;
    tr[ i ].mx_plus1 = max ( tr[ l ].mx_plus1 , tr[ r ].mx_plus1 ) ;
    tr[ i ].mx_minus1 = max ( tr[ l ].mx_minus1 , tr[ r ].mx_minus1 ) ;

}


bool good[ MAXN ] ;


void solve ( ) {
    cin >> n >> lim ;
    s.clear ( ) ; w.clear ( ) ;
    s.insert ( 1 ) ;
    s.insert ( MAXVAL ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> pos[ i ] >> len[ i ] ;
        ll st = max ( 1LL , pos[ i ] - len[ i ] ) ;
        ll en = min ( MAXVAL , pos[ i ] + len[ i ] ) ;
        s.insert ( pos[ i ] ) ;
        s.insert ( pos[ i ] + 1 ) ;
        s.insert ( st ) ;
        s.insert ( en ) ;
    }
    int tp = 0 ;
    for ( auto x : s ) {
        w[ x ] = ++ tp ;
        rval[ tp ] = x ;
    }
    init ( 1 , 1 , tp ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        ll st = max ( 1LL , pos[ i ] - len[ i ] ) ;
        update ( 1 , 1 , tp , w[ st ] , w[ pos[ i ] ] , len[ i ] - pos[ i ] , 1 ) ;
        ll en = min ( MAXVAL , pos[ i ] + len[ i ] ) ;
        update ( 1 , 1 , tp , w[ pos[ i ] + 1 ] , w[ en ] , len[ i ] + pos[ i ] , -1 ) ;
    }
    push_down ( 1 , 1 , tp ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        good[ i ] = false ;
        ll st = max ( 1LL , pos[ i ] - len[ i ] ) ;
        ll en = min ( MAXVAL , pos[ i ] + len[ i ] ) ;
        
        ll aux1 = query ( 1 , 1 , tp , 1 , w[ st ] - 1 , 0 ) ;
        if ( aux1 > lim ) { continue ; }
        ll aux2 = query ( 1 , 1 , tp , w[ en ] + 1 , w[ MAXVAL ] , 0 ) ;
        if ( aux2 > lim ) { continue ; }
        ll aux3 = query ( 1 , 1 , tp , w[ st ] , w[ pos[ i ] ] , -1 ) - ( len[ i ] - pos[ i ] ) ;
        if ( aux3 > lim ) { continue ; }
        ll aux4 = query ( 1 , 1 , tp , w[ pos[ i ] + 1 ] , w[ en ] , 1 ) - ( len[ i ] + pos[ i ] ) ;
        if ( aux4 > lim ) { continue ; }

        good[ i ] = true ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( good[ i ] == true ) { cout << "1" ; }
        else { cout << "0" ; }
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}
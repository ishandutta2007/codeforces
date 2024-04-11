#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 200007

int n , k ;
vector < int > v[ MAXN ] ;

long long ans = -1 ;

vector < int > ord ;
int st[ MAXN ] ;
int rv[ MAXN ] ;
int lst[ MAXN ] ;
int en[ MAXN ] ;
int d[ MAXN ] ;

void dfs ( int vertex , int prv ) {
    ord.push_back ( vertex ) ;
    st[ vertex ] = ord.size ( ) ;
    rv[ ord.size ( ) ] = vertex ;
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        d[ x ] = d[ vertex ] + 1 ;
        lst[ x ] = vertex ;
        dfs ( x , vertex ) ;
    }
    en[ vertex ] = ord.size ( ) ;
}

class Tree {
public :
    pair < int , int > tr[ 4 * MAXN ] ;
    int lazy[ 4 * MAXN ] ;
    void push_lazy ( int where , int IL , int IR ) {
        if ( lazy[ where ] == 0 ) { return ; }
        tr[ where ].first -= lazy[ where ] ;
        if ( IL != IR ) {
            lazy[ 2 * where ] += lazy[ where ] ;
            lazy[ 2 * where + 1 ] += lazy[ where ] ;
        }
        lazy[ where ] = 0 ; 
    }
    void unite ( int where ) {
        if ( tr[ 2 * where ].first > tr[ 2 * where + 1 ].first ) {
            tr[ where ] = tr[ 2 * where ] ;
        }
        else {
            tr[ where ] = tr[ 2 * where + 1 ] ;
        }
    }
    void init ( int where , int IL , int IR ) {
        lazy[ where ] = 0 ;
        tr[ where ] = { 0 , 0 } ;
        if ( IL == IR ) {
            tr[ where ] = { d[ rv[ IL ] ] , rv[ IL ] } ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        unite ( where ) ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR , int diff ) {
        push_lazy ( where , IL , IR ) ;
        if ( IL > IR || CURL > CURR ) { return ; }
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazy[ where ] += diff ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR , diff ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , diff ) ;
        unite ( where ) ;
    }
    int query ( ) { return tr[ 1 ].second ; } 
};
Tree w ;

bool used[ MAXN ] ;

void input ( ) {
    cin >> n >> k ;
    for ( int i = 1 , x , y ; i < n ; ++ i ) {
        cin >> x >> y ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= 13 ; ++ i ) { ans *= 10 ; }
    d[ 1 ] = 1 ;
    dfs ( 1 , -1 ) ;

    w.init ( 1 , 1 , n ) ;
    int lft = n ;
    for ( int i = 1 ; i <= k ; ++ i ) {
        int x = w.query ( ) ;
        while ( used[ x ] == false && x > 0 ) {
            used[ x ] = true ;
            w.update ( 1 , 1 , n , st[ x ] , en[ x ] , 1 ) ;
            -- lft ;
            x = lst[ x ] ;
        }
        int h = min ( lft , n / 2 ) ;
        long long aux = 1LL * ( i - h ) * ( n - i - h ) ;
        ans = max ( ans , aux ) ;
    }
    cout << ans << "\n" ;
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
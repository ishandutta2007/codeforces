#include<bits/stdc++.h>
using namespace std ;

#define lim 300000


namespace dsu {
    int prv[ 2 * lim + 7 ] ;
    int rnk[ 2 * lim + 7 ] ;
    pair < int , int > cnt[ 2 * lim + 7 ] ;
    long long ans ;
    struct change {
        long long sm ;
        int v1 , v2 ;
        int prv1 , prv2 ;
        int rnk1 , rnk2 ;
        pair < int , int > cnt1 , cnt2 ;
        change ( ) {
            sm = 0 ;
            v1 = v2 = prv1 = prv2 = rnk1 = rnk2 = 0 ;
            cnt1 = cnt2 = { 0 , 0 } ;
        }
        change ( int _v1 , int _v2 , long long _ans ) {
            sm = _ans ;
            v1 = _v1 ;
            v2 = _v2 ;
            prv1 = prv[ v1 ] ; prv2 = prv[ v2 ] ;
            rnk1 = rnk[ v1 ] ; rnk2 = rnk[ v2 ] ;
            cnt1 = cnt[ v1 ] ; cnt2 = cnt[ v2 ] ;
        }
    };
    stack < change > hh ;
    void init ( ) {
        ans = 0 ;
        for ( int i = 1 ; i <= lim ; ++ i ) {
            prv[ i ] = prv[ i + lim ] = -1 ;
            rnk[ i ] = rnk[ i + lim ] = 0 ;
            cnt[ i ] = { 1 , 0 } ;
            cnt[ i + lim ] = { 0 , 1 } ;
        }
    }
    int find ( int x ) {
        if ( prv[ x ] == -1 ) { return x ; }
        return find ( prv[ x ] ) ;
    }
    bool unite ( int x , int y ) {
        int k1 = find ( x ) ;
        int k2 = find ( y ) ;
        if ( k1 == k2 ) { return false ; }

        hh.push ( change ( k1 , k2 , ans ) ) ;
        
        ans -= 1LL * cnt[ k1 ].first * cnt[ k1 ].second ;
        ans -= 1LL * cnt[ k2 ].first * cnt[ k2 ].second ;
        
        if ( rnk[ k1 ] >= rnk[ k2 ] ) {
            rnk[ k1 ] += ( rnk[ k1 ] == rnk[ k2 ] ) ;
            prv[ k2 ] = k1 ;
            cnt[ k1 ].first += cnt[ k2 ].first ;
            cnt[ k1 ].second += cnt[ k2 ].second ;

            ans += 1LL * cnt[ k1 ].first * cnt[ k1 ].second ;
        }
        else {
            prv[ k1 ] = k2 ;
            cnt[ k2 ].first += cnt[ k1 ].first ;
            cnt[ k2 ].second += cnt[ k1 ].second ;

            ans += 1LL * cnt[ k2 ].first * cnt[ k2 ].second ;
        }
        return true ;
    }
    void undo ( ) {
        if ( hh.empty ( ) == true ) { return ; }
        change aux = hh.top ( ) ;
        hh.pop ( ) ;
        ans = aux.sm ;
        prv[ aux.v1 ] = aux.prv1 ; prv[ aux.v2 ] = aux.prv2 ;
        rnk[ aux.v1 ] = aux.rnk1 ; rnk[ aux.v2 ] = aux.rnk2 ;
        cnt[ aux.v1 ] = aux.cnt1 ; cnt[ aux.v2 ] = aux.cnt2 ;
    }
};

int q ;
long long ret[ lim + 1 ] ;

vector < pair < int , int > > v[ 8 * lim + 1 ] ;
map < pair < int , int > , int > zx ;

void update ( int where , int IL , int IR , int CURL , int CURR , int x , int y ) {
    if ( IR < CURL || CURR < IL ) { return ; }
    if ( CURL <= IL && IR <= CURR ) {
        v[ where ].push_back ( { x , y } ) ;
        return ;
    }
    int mid = ( IL + IR ) / 2 ;
    update ( 2 * where , IL , mid , CURL , CURR , x , y ) ;
    update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , x , y ) ;
}

void calc ( int where , int IL , int IR ) {
    int cnt = 0 ;
    int sz = v[ where ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        cnt += dsu :: unite ( v[ where ][ i ].first , v[ where ][ i ].second ) ;
    }
    if ( IL == IR ) {
        ret[ IL ] = dsu :: ans ;
    }
    else {
        int mid = ( IL + IR ) / 2 ;
        calc ( 2 * where , IL , mid ) ;
        calc ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    for ( int i = 0 ; i < cnt ; ++ i ) {
        dsu :: undo ( ) ;
    }    
}

void input ( ) {
    scanf ( "%d" , &q ) ;
}

void solve ( ) {
    for ( int i = 1 ; i <= q ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        if ( zx.find ( { x , y } ) == zx.end ( ) ) {
            zx[ { x , y } ] = i ;
        }
        else {
            int st = zx[ { x , y } ] ;
            update ( 1 , 1 , q , st , i - 1 , x , y + lim ) ;
            zx.erase ( { x , y } ) ;
        }
    }
    for ( auto it = zx.begin ( ) ; it != zx.end ( ) ; ++ it ) {
        update ( 1 , 1 , q , it->second , q , it->first.first , it->first.second + lim ) ;
    }
    dsu :: init ( ) ;
    calc ( 1 , 1 , q ) ;
    for ( int i = 1 ; i <= q ; ++ i ) {
        printf ( "%I64d\n" , ret[ i ] ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007
int n , q ;

namespace DSU {
    int prv[ MAXN ] ;
    int rnk[ MAXN ] ;
    bool bad ;
    struct change {
        int x , y ;
        pair < int , int > vals_x ;
        pair < int , int > vals_y ;
        bool fl ;
        change ( ) {
            x = y = 0 ;
            vals_x = vals_y = { 0 , 0 } ;
            fl = false ;
        }
        change ( int _x , int _y ) {
            x = _x ; y = _y ;
            vals_x = { prv[ _x ] , rnk[ _x ] } ;
            vals_y = { prv[ _y ] , rnk[ _y ] } ;
            fl = bad ;
        }
    };
    stack < change > h ;
    void init ( ) {
        for ( int i = 1 ; i <= 2 * n ; ++ i ) {
            prv[ i ] = -1 ;
            rnk[ i ] = 0 ;
        }
    }
    int find ( int x ) {
        if ( prv[ x ] == -1 ) { return x ; }
        return find ( prv[ x ] ) ;
    }
    bool unite ( int x , int y ) {
        int k1 = find ( x ) ;
        int k2 = find ( y ) ;
        if ( k1 != k2 ) {
            h.push ( change ( k1 , k2 ) ) ;
            if ( rnk[ k1 ] >= rnk[ k2 ] ) {
                rnk[ k1 ] += ( rnk[ k1 ] == rnk[ k2 ] ) ;
                prv[ k2 ] = k1 ;
            }
            else {
                prv[ k1 ] = k2 ;
            }
            if ( bad == false ) {
                int id = k1 ;
                if ( id > n ) { id -= n ; }
                else { id += n ; }
                if ( find ( k1 ) == find ( id ) ) { bad = true ; }
            }
            return true ;
        }
        return false ;
    }
    void undo ( ) {
        change aux = h.top ( ) ;
        h.pop ( ) ;
        prv[ aux.x ] = aux.vals_x.first ;
        rnk[ aux.x ] = aux.vals_x.second ;

        prv[ aux.y ] = aux.vals_y.first ;
        rnk[ aux.y ] = aux.vals_y.second ;

        bad = aux.fl ;
    }
};


bool ans[ MAXN ] ;

vector < pair < int , int > > v[ 4 * MAXN ] ;

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

void rec ( int where , int IL , int IR ) {
    int sz = v[ where ].size ( ) ;
    int act = 0 ;
    if ( DSU :: bad == false ) {
        for ( int i = 0 ; i < sz ; ++ i ) {
            int x = v[ where ][ i ].first ;
            int y = v[ where ][ i ].second ;
        
            act += DSU :: unite ( x , n + y ) ;
            act += DSU :: unite ( n + x , y ) ;
        }
    }
    if ( IL == IR ) {
        ans[ IL ] = DSU :: bad ;
    }
    else {
        int mid = ( IL + IR ) / 2 ;
        rec ( 2 * where , IL , mid ) ;
        rec ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    
    for ( int i = 0 ; i < act ; ++ i ) {
        DSU :: undo ( ) ;
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
}

void solve ( ) {
    DSU :: init ( ) ;
    for ( int i = 1 ; i <= q ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        if ( zx.find ( { x , y } ) == zx.end ( ) ) {
            zx[ { x , y } ] = i ;
        }
        else {
            update ( 1 , 1 , q , zx[ { x , y } ] , i - 1 , x , y ) ;
            zx.erase ( { x , y } ) ;
        }
    }
    for ( auto it = zx.begin ( ) ; it != zx.end ( ) ; ++ it ) {
        update ( 1 , 1 , q , it->second , q , it->first.first , it->first.second ) ;
    }
    rec ( 1 , 1 , q ) ;
    for ( int i = 1 ; i <= q ; ++ i ) {
        if ( ans[ i ] == false ) { printf ( "YES\n" ) ; }
        else { printf ( "NO\n" ) ; }
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
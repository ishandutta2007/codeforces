#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , k ;
int a[ MAXN ] ;
int nxt[ MAXN ] ;

queue < int > q[ MAXN ] ;

vector < int > merge ( vector < int > v1 , vector < int > v2 ) {
    vector < int > ret ;
    ret.clear ( ) ;
    int sz1 = v1.size ( ) ;
    int sz2 = v2.size ( ) ;

    int pos1 = 0 , pos2 = 0 ;
    while ( pos1 < sz1 || pos2 < sz2 ) {
        if ( pos1 == sz1 ) {
            ret.push_back ( v2[ pos2 ++ ] ) ;
        }
        else if ( pos2 == sz2 ) {
            ret.push_back ( v1[ pos1 ++ ] ) ;
        }
        else {
            if ( v1[ pos1 ] < v2[ pos2 ] ) {
                ret.push_back ( v1[ pos1 ++ ] ) ;
            }
            else {
                ret.push_back ( v2[ pos2 ++ ] ) ;
            }
        }
    }
    return ret ;
}

class Tree {
public :
    vector < int > tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            tr[ where ].push_back ( nxt[ IL ] ) ;
            return ; 
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    int f ( int where , int sr ) {
        int l , r , mid ;
        int sz = tr[ where ].size ( ) ;
        l = 0 ;
        r = sz - 1 ;
        while ( r - l > 3 ) {
            mid = ( l + r ) / 2 ;
            if ( tr[ where ][ mid ] <= sr ) { l = mid ; }
            else { r = mid ; }
        }
        while ( l < sz && tr[ where ][ l ] <= sr ) { ++ l ; }
        return ( sz - l ) ;
    }
    int query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IR < CURL || CURR < IL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) {
            return f ( where , CURR ) ;
        }
        int mid = ( IL + IR ) / 2 ;
        return query ( 2 * where , IL , mid , CURL , CURR ) + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
    }
};
Tree w ;

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    for ( int i = n ; i >= 1 ; -- i ) {
        if ( q[ a[ i ] ].size ( ) < k ) {
            nxt[ i ] = n + 1 ;
        }
        else {
            nxt[ i ] = q[ a[ i ] ].front ( ) ;
            q[ a[ i ] ].pop ( ) ;
        }
        q[ a[ i ] ].push ( i ) ;
    }
    w.init ( 1 , 1 , n ) ;
    int hh ;
    scanf ( "%d" , &hh ) ;
    int lst = 0 ;
    while ( hh -- ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        x = ( x + lst ) % n + 1 ;
        y = ( y + lst ) % n + 1 ;
        if ( x > y ) { swap ( x , y ) ; }
        lst = w.query ( 1 , 1 , n , x , y ) ;
        printf ( "%d\n" , lst ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
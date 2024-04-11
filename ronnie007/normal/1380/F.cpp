#include<bits/stdc++.h>
using namespace std ;

#define MAXN 500007
#define MOD 998244353

int n , q ;
int a[ MAXN ] ;

int cnt[ 222 ] ;

class Tree {
public :
    long long tr[ 4 * MAXN ][ 2 ][ 2 ] ;
    void unite ( int where , int IL , int IR ) {
        int l = 2 * where ;
        int r = 2 * where + 1 ;
        int mid = ( IL + IR ) / 2 ;
        for ( int i = 0 ; i < 2 ; ++ i ) {
            for ( int j = 0 ; j < 2 ; ++ j ) {
                tr[ where ][ i ][ j ] = ( tr[ l ][ i ][ 0 ] * tr[ r ][ 0 ][ j ] ) % MOD ;
                if ( a[ mid ] > 0 ) {
                    long long aux = ( tr[ l ][ i ][ 1 ] * tr[ r ][ 1 ][ j ] ) % MOD ;
                    aux = ( aux * cnt[ 10 * a[ mid ] + a[ mid + 1 ] ] ) % MOD ;
                    tr[ where ][ i ][ j ] = ( tr[ where ][ i ][ j ] + aux ) % MOD ;
                }
            }
        }
    }
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            tr[ where ][ 0 ][ 0 ] = cnt[ a[ IL ] ] ;
            tr[ where ][ 0 ][ 1 ] = 1 ;
            tr[ where ][ 1 ][ 0 ] = 1 ;
            tr[ where ][ 1 ][ 1 ] = 0 ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        unite ( where , IL , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ][ 0 ][ 0 ] = cnt[ a[ IL ] ] ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos ) ;
        }
        unite ( where , IL , IR ) ;
    }
};
Tree w ;

void input ( ) {
    cin >> n >> q ;
    string s ;
    cin >> s ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        a[ i ] = ( s[ i - 1 ] - '0' ) ;
    }
    for ( int i = 0 ; i <= 9 ; ++ i ) {
        cnt[ i ] = i + 1 ;
    }
    for ( int i = 10 ; i <= 18 ; ++ i ) {
        cnt[ i ] = 19 - i ;
    }
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    while ( q -- ) {
        int pos , x ;
        cin >> pos >> x ;
        a[ pos ] = x ;
        w.update ( 1 , 1 , n , pos ) ;
        cout << w.tr[ 1 ][ 0 ][ 0 ] << "\n" ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
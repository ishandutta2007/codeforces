#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
long long val[ MAXN ] ;
long long a[ MAXN ] ;

long long f ( long long x , long long y ) {
    if ( x < y ) { swap ( x , y ) ; }
    while ( y != 0 ) {
        x %= y ;
        swap ( x , y ) ;
    }
    return x ;
}

class Tree {
public :
    long long tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            tr[ where ] = a[ IL ] ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = f ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    long long query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IL > IR || CURL > CURR ) { return 0 ; }
        if ( CURR < IL || IR < CURL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return f ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};

Tree w ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> val[ i ] ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        a[ i ] = val[ i + 1 ] - val[ i ] ;
        if ( a[ i ] < 0 ) { a[ i ] = -a[ i ] ; }
    }
}

void solve ( ) {
    if ( n == 1 ) {
        cout << "1\n" ;
        return ;
    }
    w.init ( 1 , 1 , n - 1 ) ;
    int l = 1 ;
    int ans = 0 ;
    for ( int r = 1 ; r <= n ; ++ r ) {
        while ( l < r ) {
            long long aux = w.query ( 1 , 1 , n - 1 , l , r - 1 ) ;
            if ( aux > 1 ) { break ; }
            ++ l ;
        }
        ans = max ( ans , r - l + 1 ) ;
    }
    cout << ans << "\n" ;
}

int main ( ) {
    //freopen ( "dictionary.in" , "r" , stdin ) ;
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
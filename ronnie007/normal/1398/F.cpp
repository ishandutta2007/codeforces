#include<bits/stdc++.h>
using namespace std ;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 1000007

int n ;
string a ;

int mxsuff[ MAXN ] ;


class Tree {
public :
    int tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            tr[ where ] = mxsuff[ IL ] ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = max ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    int query ( int where , int IL , int IR , int pos , int len ) {
        if ( IR < pos ) { return -1 ; }
        if ( tr[ where ] < len ) { return -1 ; }
        if ( IL == IR ) { return IL ; }
        int mid = ( IL + IR ) / 2 ;
        int ret = -1 ;
        if ( pos <= mid ) { ret = query ( 2 * where , IL , mid , pos , len ) ; }
        if ( ret > -1 ) { return ret ; }
        return query ( 2 * where + 1 , mid + 1 , IR , pos , len ) ;
    }
};
Tree w ;

void input ( ) {
    cin >> n ;
    cin >> a ;
    a = '#' + a ;
    int cnt[ 2 ] ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ] == '?' ) {
            ++ cnt[ 0 ] ; ++ cnt[ 1 ] ;
        }
        else if ( a[ i ] == '0' ) {
            ++ cnt[ 0 ] ;
            cnt[ 1 ] = 0 ;
        }
        else {
            cnt[ 0 ] = 0 ;
            ++ cnt[ 1 ] ; 
        }
        mxsuff[ i ] = max ( cnt[ 0 ] , cnt[ 1 ] ) ;
    }
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    cout << n ;
    for ( int len = 2 ; len <= n ; ++ len ) {
        int pos = 1 ;
        int cnt = 0 ;
        while ( pos + len - 1 <= n ) {
            int ret = w.query ( 1 , 1 , n , pos + len - 1 , len ) ;
            if ( ret == -1 ) { break ; }
            ++ cnt ;
            pos = ret + 1 ;
        }
        cout << " " << cnt ;
        if ( cnt == 0 ) {
            for ( int i = len + 1 ; i <= n ; ++ i ) {
                cout << " 0" ;
            }
            break ;
        }
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
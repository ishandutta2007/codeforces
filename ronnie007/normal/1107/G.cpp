#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007

int n , coef ;
int diff[ MAXN ] ;
int cost[ MAXN ] ;

pair < long long , int > srt[ MAXN ] ;

class Tree {
public :
    long long tr[ 4 * MAXN ] ;
    long long sm[ 4 * MAXN ] ;
    long long mxpref[ 4 * MAXN ] ;
    long long mxsuff[ 4 * MAXN ] ;
    bool block[ 4 * MAXN ] ;

    bool open[ 4 * MAXN ] ;

    void unite ( int where , int IL , int IR ) {
        int l = 2 * where , r = 2 * where + 1 ;
        
        block[ where ] = block[ l ] ;
        
        tr[ where ] = max ( tr[ l ] , tr[ r ] ) ;
        if ( block[ r ] == false ) {
            tr[ where ] = max ( tr[ where ] , mxsuff[ l ] + mxpref[ r ] ) ;
        }

        mxpref[ where ] = mxpref[ l ] ;
        mxsuff[ where ] = mxsuff[ r ] ;
        if ( block[ r ] == false ) {
            if ( open[ l ] == true ) {
                mxpref[ where ] = max ( mxpref[ where ] , sm[ l ] + mxpref[ r ] ) ;
            }
            if ( open[ r ] == true ) {
                mxsuff[ where ] = max ( mxsuff[ where ] , sm[ r ] + mxsuff[ l ] ) ;
            }
        }
        if ( block[ r ] == false && open[ r ] == true && open[ l ] == true ) {
            open[ where ] = true ;
        }
        else { open[ where ] = false ; }
    }
    void init ( int where , int IL , int IR ) {
        block[ where ] = true ;
        open[ where ] = false ;
        if ( IL == IR ) {
            long long aux = coef - cost[ IL ] ;
            open[ where ] = true ;
            tr[ where ] = mxpref[ where ] = mxsuff[ where ] = max ( aux , 0LL ) ;
            sm[ where ] = aux ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        sm[ where ] = sm[ 2 * where ] + sm[ 2 * where + 1 ] ;
        unite ( where , IL , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            block[ where ] = false ;
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
    cin >> n >> coef ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> diff[ i ] >> cost[ i ] ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        long long aux = ( diff[ i + 1 ] - diff[ i ] ) ;
        srt[ i ] = { aux * aux , i } ;
    }
    sort ( srt + 1 , srt + n ) ;
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    long long ans = w.tr[ 1 ] ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int id = srt[ i ].second ;
        w.update ( 1 , 1 , n , id + 1 ) ;
        ans = max ( ans , w.tr[ 1 ] - srt[ i ].first ) ;
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
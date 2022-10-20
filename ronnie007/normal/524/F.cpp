#include<bits/stdc++.h>
using namespace std ;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 1000007

class suffix_array {
public :
    int n ;
    int p[ MAXN ] , c[ MAXN ] ;
    int rv[ MAXN ] ;
    int mxclass ;

    int aux[ MAXN ] , nw[ MAXN ] ;
    int cnt[ MAXN ] ;
    const int lim = 256 ;
    void init ( string a ) {
        n = a.size ( ) ;
        for ( int i = 0 ; i < lim ; ++ i ) {
            cnt[ i ] = 0 ;
        }
        for ( int i = 0 ; i < n ; ++ i ) {
            ++ cnt[ (int)a[ i ] ] ;
        }
        for ( int i = 1 ; i < lim ; ++ i ) {
            cnt[ i ] += cnt[ i - 1 ] ;
        }
        for ( int i = 0 ; i < n ; ++ i ) {
            p[ -- cnt[ (int)a[ i ] ] ] = i ;
        }
        mxclass = c[ p[ 0 ] ] = 1 ;
        for ( int i = 1 ; i < n ; ++ i ) {
            if ( a[ p[ i ] ] == a[ p[ i - 1 ] ] ) {
                c[ p[ i ] ] = c[ p[ i - 1 ] ] ;
            }
            else {
                c[ p[ i ] ] = ++ mxclass ;
            }
        }
        for ( int len = 1 ; len < n ; len *= 2 ) {
            for ( int i = 1 ; i <= mxclass ; ++ i ) {
                cnt[ i ] = 0 ;
            }
            for ( int i = 0 ; i < n ; ++ i ) {
                aux[ i ] = ( p[ i ] - len + n ) % n ;
                ++ cnt[ c[ aux[ i ] ] ] ;
            }
            for ( int i = 1 ; i <= mxclass ; ++ i ) {
                cnt[ i ] += cnt[ i - 1 ] ;
            }
            for ( int i = n - 1 ; i >= 0 ; -- i ) {
                p[ -- cnt[ c[ aux[ i ] ] ] ] = aux[ i ] ;
            }
            int tp = 1 ;
            nw[ p[ 0 ] ] = 1 ;
            for ( int i = 1 ; i < n ; ++ i ) {
                if ( c[ p[ i - 1 ] ] != c[ p[ i ] ] ) {
                    nw[ p[ i ] ] = ++ tp ;
                }
                else {
                    if ( c[ ( p[ i - 1 ] + len ) % n ] != c[ ( p[ i ] + len ) % n ] ) {
                        nw[ p[ i ] ] = ++ tp ;
                    }
                    else {
                        nw[ p[ i ] ] = tp ;
                    }
                }
            }
            mxclass = tp ;
            for ( int i = 0 ; i < n ; ++ i ) {
                c[ p[ i ] ] = nw[ p[ i ] ] ;
            }
        }
        for ( int i = 0 ; i < n ; ++ i ) {
            rv[ p[ i ] ] = i ;
        }
    }
};

suffix_array w ;

int n ;
string a ;
int pref[ MAXN ] ;

class Tree {
public :
    int tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            tr[ where ] = pref[ IL ] ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = min ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    int query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IL > IR || CURL > CURR ) { return 3 * MAXN ; }
        if ( CURR < IL || IR < CURL ) { return 3 * MAXN ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return min ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};
Tree tr ;


void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    w.init ( a ) ;
    pref[ 0 ] = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        pref[ i ] = pref[ i - 1 ] ;
        if ( a[ i - 1 ] == '(' ) { ++ pref[ i ] ; }
        else { -- pref[ i ] ; }
    }
    tr.init ( 1 , 1 , n ) ;
    int sr = MAXN , ans = -1 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        /// start at i
        int aux1 = tr.query ( 1 , 1 , n , i + 1 , n ) ;
        int aux2 = pref[ n ] + tr.query ( 1 , 1 , n , 1 , i ) ;
        int hh = min ( pref[ i ] , pref[ n ] + pref[ i ] ) ;
        if ( hh <= aux1 && hh <= aux2 ) {
            if ( sr > w.rv[ i ] ) {
                sr = w.rv[ i ] ;
                ans = i ;
            }
        }
    }
    while ( pref[ n ] < 0 ) {
        ++ pref[ n ] ;
        cout << "(" ;
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        cout << a[ ( ans + i ) % n ] ;
    }
    while ( pref[ n ] > 0 ) {
        -- pref[ n ] ;
        cout << ")" ;
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    /// cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
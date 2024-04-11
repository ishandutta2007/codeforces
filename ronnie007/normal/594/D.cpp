#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007
#define MAXVAL 1000007
#define MOD 1000000007

int n ;
int a[ MAXN ] ;

vector < int > v[ MAXVAL ] ;

int lstpos[ MAXVAL ] ;
long long inv[ MAXVAL ] ;


int q ;
vector < pair < int , int > > qlist[ MAXN ] ;

int ans[ MAXN ] ;

class Tree {
public :
    long long tr[ 5 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            tr[ where ] = a[ IL ] ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = ( tr[ 2 * where ] * tr[ 2 * where + 1 ] ) % MOD ;
    }
    void update ( int where , int IL , int IR , int pos , long long coef ) {
        if ( IR < pos || pos < IL ) { return ; }
        tr[ where ] = ( tr[ where ] * coef ) % MOD ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , coef ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , coef ) ;
        }
    }
    long long query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( CURL > CURR ) { return 1 ; }
        if ( IR < CURL || CURR < IL ) { return 1 ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        long long ret = query ( 2 * where , IL , mid , CURL , CURR ) ;
        ret = ( ret * query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) % MOD ;
        return ret ;
    }
};
Tree w ;



long long fastpow ( long long x , long long pw ) {
    long long ret = 1 ;
    while ( pw > 0 ) {
        if ( ( pw % 2 ) == 0 ) {
            x = ( x * x ) % MOD ;
            pw /= 2 ;
        }
        else {
            ret = ( ret * x ) % MOD ;
            -- pw ;
        }
    }
    return ret ;
}

void init ( ) {
    for ( int i = 2 ; i < MAXVAL ; ++ i ) {
        if ( v[ i ].size ( ) > 0 ) { continue ; }
        for ( int j = i ; j < MAXVAL ; j += i ) {
            v[ j ].push_back ( i ) ;
        }
    }
    w.init ( 1 , 1 , n ) ;
    for ( int i = 1 ; i < MAXVAL ; ++ i ) {
        inv[ i ] = fastpow ( i , MOD - 2 ) ;
    }
}


void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    scanf ( "%d" , &q ) ;
    for ( int i = 1 ; i <= q ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        qlist[ x ].push_back ( { y , i } ) ;
    }
}

void solve ( ) {
    for ( int i = n ; i >= 1 ; -- i ) {
        int sz = v[ a[ i ] ].size ( ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            long long coef = v[ a[ i ] ][ j ] - 1 ;
            coef = ( coef * inv[ v[ a[ i ] ][ j ] ] ) % MOD ;
            w.update ( 1 , 1 , n , i , coef ) ;
            if ( lstpos[ v[ a[ i ] ][ j ] ] != 0 ) {
                coef = v[ a[ i ] ][ j ] ;
                coef = ( coef * inv[ v[ a[ i ] ][ j ] - 1 ] ) % MOD ;
                w.update ( 1 , 1 , n , lstpos[ v[ a[ i ] ][ j ] ] , coef ) ;
            }
            lstpos[ v[ a[ i ] ][ j ] ] = i ;
        }
        sz = qlist[ i ].size ( ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            ans[ qlist[ i ][ j ].second ] = w.query ( 1 , 1 , n , i , qlist[ i ][ j ].first ) ;
        }
    }
    for ( int i = 1 ; i <= q ; ++ i ) {
        printf ( "%d\n" , ans[ i ] ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    init ( ) ;
    solve ( ) ;
    return 0 ;
}
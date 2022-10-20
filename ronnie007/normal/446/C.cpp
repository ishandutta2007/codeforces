#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007
#define MOD 1000000009

int n , m ;
long long a[ MAXN ] ;

pair < long long , long long > coef[ MAXN ] ;
pair < long long , long long > pref[ MAXN ] ;

class Tree {
public :
    long long tr[ 4 * MAXN ] ;
    pair < long long , long long > lazy[ 4 * MAXN ] ;

    void push_lazy ( int where , int IL , int IR ) {
        if ( lazy[ where ].first == 0 && lazy[ where ].second == 0 ) { return ; }
        long long fst = lazy[ where ].first ;
        long long scd = lazy[ where ].second ;
        lazy[ where ] = { 0 , 0 } ;
        tr[ where ] += ( fst * pref[ IR - IL + 1 ].first ) % MOD ;
        tr[ where ] += ( scd * pref[ IR - IL + 1 ].second ) % MOD ;
        tr[ where ] %= MOD ;

        if ( IL != IR ) {
            int mid = ( IL + IR ) / 2 + 1 ;
            lazy[ 2 * where ].first = ( lazy[ 2 * where ].first + fst ) % MOD ;
            lazy[ 2 * where ].second = ( lazy[ 2 * where ].second + scd ) % MOD ;

            long long aux1 = ( fst * coef[ mid - IL + 1 ].first ) % MOD ;
            aux1 += ( scd * coef[ mid - IL + 1 ].second ) % MOD ;
            aux1 %= MOD ;

            long long aux2 = ( fst * coef[ mid - IL + 2 ].first ) % MOD ;
            aux2 += ( scd * coef[ mid - IL + 2 ].second ) % MOD ;
            aux2 %= MOD ;

            lazy[ 2 * where + 1 ].first = ( lazy[ 2 * where + 1 ].first + aux1 ) % MOD ;
            lazy[ 2 * where + 1 ].second = ( lazy[ 2 * where + 1 ].second + aux2 ) % MOD ;
        }
    }
    
    void init ( int where , int IL , int IR ) {
        lazy[ where ] = { 0 , 0 } ;
        if ( IL == IR ) {
            tr[ where ] = a[ IL ] ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = ( tr[ 2 * where ] + tr[ 2 * where + 1 ] ) % MOD ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( CURR < IL || IR < CURL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            int pos = ( IL - CURL + 1 ) ;
            lazy[ where ].first = ( coef[ pos ].first + coef[ pos ].second ) % MOD ;
            lazy[ where ].second = ( coef[ pos + 1 ].first + coef[ pos + 1 ].second ) % MOD ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
        tr[ where ] = ( tr[ 2 * where ] + tr[ 2 * where + 1 ] ) % MOD ;
    }
    long long query ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( CURL > CURR ) { return 0 ; }
        if ( IR < CURL || CURR < IL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return ( ( query ( 2 * where , IL , mid , CURL , CURR ) + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) % MOD ) ;
    }
};
Tree w ;

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%I64d" , &a[ i ] ) ;
    }
    coef[ 1 ] = { 1 , 0 } ;
    coef[ 2 ] = { 0 , 1 } ;
    for ( int i = 3 ; i <= n ; ++ i ) {
        coef[ i ].first = ( coef[ i - 1 ].first + coef[ i - 2 ].first ) % MOD ;
        coef[ i ].second = ( coef[ i - 1 ].second + coef[ i  - 2 ].second ) % MOD ;
    }

    for ( int i = 1 ; i <= n ; ++ i ) {
        pref[ i ].first = ( pref[ i - 1 ].first + coef[ i ].first ) % MOD ;
        pref[ i ].second = ( pref[ i - 1 ].second + coef[ i ].second ) % MOD ;
    }
    w.init ( 1 , 1 , n ) ;
}

void solve ( ) {
    int type , l , r ;
    while ( m -- ) {
        scanf ( "%d%d%d" , &type , &l , &r ) ;
        if ( type == 1 ) {
            w.update ( 1 , 1 , n , l , r ) ;
        }
        else {
            printf ( "%d\n" , w.query ( 1 , 1 , n , l , r ) ) ;
        }
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n , q ;
int a[ MAXN ] ;

class Tree {
public :
    long long tr[ 4 * MAXN ] ;
    long long mn[ 4 * MAXN ] ;
    long long mx[ 4 * MAXN ] ;
    long long lazy[ 4 * MAXN ] ;
    void push_lazy ( int where , int IL , int IR ) {
        if ( lazy[ where ] == 0 ) { return ; }
        tr[ where ] = lazy[ where ] * ( IR - IL + 1 ) ;
        mn[ where ] = mx[ where ] = lazy[ where ] ;
        if ( IL != IR ) {
            lazy[ 2 * where ] = max ( lazy[ 2 * where ] , lazy[ where ] ) ;
            lazy[ 2 * where + 1 ] = max ( lazy[ 2 * where + 1 ] , lazy[ where ] ) ;
        }
        lazy[ where ] = 0 ;
    }
    void unite ( int where , int IL , int IR ) {
        tr[ where ] = ( tr[ 2 * where ] + tr[ 2 * where + 1 ] ) ;
        mn[ where ] = min ( mn[ 2 * where ] , mn[ 2 * where + 1 ] ) ;
        mx[ where ] = max ( mx[ 2 * where ] , mx[ 2 * where + 1 ] ) ;
    }
    void init ( int where , int IL , int IR ) {
        lazy[ where ] = 0 ;
        if ( IL == IR ) {
            tr[ where ] = mn[ where ] = mx[ where ] = a[ IL ] ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        unite ( where , IL , IR ) ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR , int val ) {
        push_lazy ( where , IL , IR ) ;
        if ( CURL > CURR || IL > IR ) { return ; }
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( mn[ where ] >= val ) { return ; }
        if ( CURL <= IL && IR <= CURR && mx[ where ] <= val ) {
            lazy[ where ] = val ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR , val ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
        unite ( where , IL , IR ) ;
    }
    int get_fst ( int where , int IL , int IR , int pos , int sr ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < pos ) { return MAXN ; }
        if ( mn[ where ] > sr ) { return MAXN ; }
        if ( IL == IR ) { return IL ; }
        int mid = ( IL + IR ) / 2 ;
        int ret = get_fst ( 2 * where , IL , mid , pos , sr ) ;
        if ( ret != MAXN ) { push_lazy ( 2 * where + 1 , mid + 1 , IR ) ; return ret ; }
        return get_fst ( 2 * where + 1 , mid + 1 , IR , pos , sr ) ;
    }
    pair < long long , int > get_sm ( int where , int IL , int IR , int pos , long long sr ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < pos ) { return { 0 , 0 } ; }
        if ( pos <= IL && tr[ where ] <= sr ) { return { tr[ where ] , IR - IL + 1 } ; }
        if ( mn[ where ] > sr ) { return { 0 , 0 } ; }
        int mid = ( IL + IR ) / 2 ;
        pair < long long , int > ret1 = get_sm ( 2 * where , IL , mid , pos , sr ) ;
        pair < long long , int > ret2 = { 0 , 0 } ;
        if ( ret1.second >= mid - pos + 1 ) { ret2 = get_sm ( 2 * where + 1 , mid + 1 , IR , pos , sr - ret1.first ) ; }
        return { ret1.first + ret2.first , ret1.second + ret2.second } ;
    }
};
Tree w ;

int calc ( int st , long long lft ) {
    int ret = 0 ;
    st = w.get_fst ( 1 , 1 , n , st , lft ) ;
    while ( st <= n ) {
        pair < long long , int > h = w.get_sm ( 1 , 1 , n , st , lft ) ;
        ret += h.second ;
        st += h.second ;
        lft -= h.first ;
        st = max ( st , w.get_fst ( 1 , 1 , n , st , lft ) ) ;
    }
    return ret ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    int cnt = 0 ;
    while ( q -- ) {
        int type , x , y ;
        scanf ( "%d%d%d" , &type , &x , &y ) ;
        if ( type == 1 ) {
            w.update ( 1 , 1 , n , 1 , x , y ) ;
        }
        else {
            printf ( "%d\n" , calc ( x , y ) ) ;
        }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    /// cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
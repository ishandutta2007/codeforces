#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , m , q ;
long long a[ MAXN ] ;
long long b[ MAXN ] ;
long long diff[ MAXN ] ;

class Tree {
public :
    long long mx[ 4 * MAXN ] ;
    long long lazy[ 4 * MAXN ] ;
    long long tr[ 4 * MAXN ] ;
    long long sm[ 4 * MAXN ] ;
    int len[ 4 * MAXN ] ;
    void push_lazy ( int where ) {
        if ( lazy[ where ] == 0 ) { return ; }
        mx[ where ] += lazy[ where ] ;
        tr[ where ] += lazy[ where ] * len[ where ] * ( len[ where ] + 1 ) / 2 ;
        sm[ where ] += lazy[ where ] * len[ where ] ;
        
        if ( len[ where ] > 1 ) {
            lazy[ 2 * where ] += lazy[ where ] ;
            lazy[ 2 * where + 1 ] += lazy[ where ] ;
        }
        lazy[ where ] = 0 ;
    }
    void init ( int where , int IL , int IR ) {
        lazy[ where ] = 0 ;
        if ( IL == IR ) {
            mx[ where ] = tr[ where ] = sm[ where ] = diff[ IL ] ;
            len[ where ] = 1 ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;

        sm[ where ] = sm[ 2 * where ] + sm[ 2 * where + 1 ] ;
        tr[ where ] = tr[ 2 * where + 1 ] + tr[ 2 * where ] + sm[ 2 * where ] * len[ 2 * where + 1 ] ;
        mx[ where ] = mx[ 2 * where + 1 ] ;
        len[ where ] = len[ 2 * where ] + len[ 2 * where + 1 ] ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR , int add ) {
        push_lazy ( where ) ;
        if ( IL > IR || CURL > CURR ) { return ; }
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazy[ where ] += add ;
            push_lazy ( where ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR , add ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , add ) ;

        sm[ where ] = sm[ 2 * where ] + sm[ 2 * where + 1 ] ;
        tr[ where ] = tr[ 2 * where + 1 ] + tr[ 2 * where ] + sm[ 2 * where ] * len[ 2 * where + 1 ] ;
        mx[ where ] = mx[ 2 * where + 1 ] ;
    }

    int get_fst ( int where , int IL , int IR , long long sr ) {
        push_lazy ( where ) ;
        if ( mx[ where ] <= sr ) { return -1 ; }
        if ( IL == IR ) { return IL ; }
        int mid = ( IL + IR ) / 2 ;
        int ret = get_fst ( 2 * where , IL , mid , sr ) ;
        if ( ret != -1 ) { return ret ; }
        return get_fst ( 2 * where + 1 , mid + 1 , IR , sr ) ;
    }
    int aux_len ;
    long long ret ;
    long long tot_sm ;
    void f ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where ) ;
        if ( IL > IR || CURL > CURR ) { return ; }
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            ret += aux_len * sm[ where ] + tr[ where ] ;
            tot_sm += sm[ where ] ;
            aux_len += len[ where ] ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        f ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
        f ( 2 * where , IL , mid , CURL , CURR ) ;
    }
};

Tree w ;

long long calc ( ) {
    int lst_taken = 0 ;
    long long ret = 0 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        int nw = w.get_fst ( 1 , 1 , m - 1 , a[ i ] - a[ i - 1 ] ) ;
        w.aux_len = 0 ;
        w.tot_sm = 0 ;
        w.ret = 0 ;
        if ( nw != -1 ) {
            w.f ( 1 , 1 , m - 1 , lst_taken + 1 , nw - 1 ) ;
            ret += w.ret ;
            ret += w.tot_sm * ( n - i + 1 + m - nw ) ;
            lst_taken = nw - 1 ;
        }
        else {
            if ( lst_taken < m - 1 ) {
                w.f ( 1 , 1 , m - 1 , lst_taken + 1 , m - 1 ) ;
                ret += w.ret ;
                ret += w.tot_sm * ( n - i + 1 ) ;
                lst_taken = m - 1 ;
            }
        }
        ret += a[ i ] - a[ i - 1 ] ;
        ret += ( a[ i ] - a[ i - 1 ] ) * ( m - 1 - lst_taken + n - i ) ;
    }
    if ( lst_taken < m - 1 ) {
        w.aux_len = 0 ;
        w.tot_sm = 0 ;
        w.ret = 0 ;
        w.f ( 1 , 1 , m - 1 , lst_taken + 1 , m - 1 ) ;
        ret += w.ret ;
    }
    return ret ;
}

void input ( ) {
    cin >> n >> m >> q ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        cin >> b[ i ] ;
    }
}

void solve ( ) {
    long long init = ( a[ 1 ] + b[ 1 ] ) * ( n + m - 1 ) ;
    for ( int i = 1 ; i < m ; ++ i ) {
        diff[ i ] = b[ i + 1 ] - b[ i ] ;
    }
    w.init ( 1 , 1 , m - 1 ) ;
    while ( q -- ) {
        int type , st , add ;
        cin >> type >> st >> add ;
        if ( type == 1 ) {
            st = n - st + 1 ;
        }
        else {
            st = m - st + 1 ;
        }
        if ( st == 1 ) {
            init += add * ( n + m - 1 ) ;
        }
        if ( type == 1 ) {
            for ( int i = st ; i <= n ; ++ i ) {
                a[ i ] += ( i - st + 1 ) * add ;
            }
        }
        else {
            if ( st == 1 ) { ++ st ; }
            w.update ( 1 , 1 , m - 1 , st - 1 , m - 1 , add ) ;
        }
        cout << init + calc ( ) << "\n" ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
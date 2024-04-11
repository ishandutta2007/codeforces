#include<bits/stdc++.h>
using namespace std ;

#define MOD 1000000007
#define MAXN 400007

int n , q ;
int a[ MAXN ] ;

long long bit_mask[ 307 ] ;
int rv[ 67 ] ;
int cnt_nums ;
long long inv[ 307 ] ;


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

long long prod , total_mask ;

class Tree {
public : 
    int tr[ 4 * MAXN ] ;
    int lazy_mul[ 4 * MAXN ] ;

    long long mask[ 4 * MAXN ] ;
    long long lazy_mask[ 4 * MAXN ] ;

    void unite ( int where ) {
        int l = 2 * where , r = 2 * where + 1 ;
        tr[ where ] = ( 1LL * tr[ l ] * tr[ r ] ) % MOD ;
        mask[ where ] = ( mask[ l ] | mask[ r ] ) ;
    }

    void push_lazy ( int where , int IL , int IR ) {
        if ( lazy_mul[ where ] == 1 ) { return ; }
        long long aux = fastpow ( lazy_mul[ where ] , ( IR - IL + 1 ) ) ;
        tr[ where ] = ( 1LL * tr[ where ] * aux ) % MOD ;
        if ( IL != IR ) {
            lazy_mul[ 2 * where ] = ( 1LL * lazy_mul[ 2 * where ] * lazy_mul[ where ] ) % MOD ;
            lazy_mul[ 2 * where + 1 ] = ( 1LL * lazy_mul[ 2 * where + 1 ] * lazy_mul[ where ] ) % MOD ;
        }
        lazy_mul[ where ] = 1 ;
        
        mask[ where ] |= lazy_mask[ where ] ;
        if ( IL != IR ) {
            lazy_mask[ 2 * where ] |= lazy_mask[ where ] ;
            lazy_mask[ 2 * where + 1 ] |= lazy_mask[ where ] ;
        }
        lazy_mask[ where ] = 0 ;
    }
    
    void init ( int where , int IL , int IR ) {
        lazy_mul[ where ] = 1 ;
        lazy_mask[ where ] = 0 ;
        if ( IL == IR ) {
            tr[ where ] = a[ IL ] ;
            mask[ where ] = bit_mask[ a[ IL ] ] ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        unite ( where ) ;
    }

    void update ( int where , int IL , int IR , int CURL , int CURR , int val ) {
        push_lazy ( where , IL , IR ) ;
        if ( CURR < IL || IR < CURL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazy_mul[ where ] = val ;
            lazy_mask[ where ] = bit_mask[ val ] ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR , val ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
        unite ( where ) ;
    }
    void query ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( CURR < IL || IR < CURL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            prod = ( prod * tr[ where ] ) % MOD ;
            total_mask |= mask[ where ] ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        query ( 2 * where , IL , mid , CURL , CURR ) ;
        query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
    }
};

Tree w ;



void init ( ) {
    bit_mask[ 1 ] = 0 ;
    long long aux = 1 ;
    cnt_nums = 0 ;
    for ( int i = 2 ; i <= 300 ; ++ i ) {
        int j ;
        for ( j = 2 ; j * j <= i ; ++ j ) {
            if ( ( i % j ) == 0 ) { break ; }
        }
        if ( ( j * j ) > i ) {
            rv[ cnt_nums ++ ] = i ;
            for ( j = i ; j <= 300 ; j += i ) {
                bit_mask[ j ] |= aux ;
            }
            aux *= 2 ;
        }
    }
    for ( int i = 0 ; i <= 300 ; ++ i ) {
        inv[ i ] = fastpow ( i , MOD - 2 ) ;
    }
}

void input ( ) {
    cin >> n >> q ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    string cmd ;
    int l , r , val ;
    while ( q -- ) {
        cin >> cmd ;
        if ( cmd == "MULTIPLY" ) {
            cin >> l >> r >> val ;
            w.update ( 1 , 1 , n , l , r , val ) ;
        }
        else {
            cin >> l >> r ;
            prod = 1 ;
            total_mask = 0 ;
            w.query ( 1 , 1 , n , l , r ) ;
            long long hh = 1 ;
            for ( int i = 0 ; i < cnt_nums ; ++ i ) {
                if ( ( total_mask & hh ) > 0 ) {
                    prod = ( prod * inv[ rv[ i ] ] ) % MOD ;
                    prod = ( prod * ( rv[ i ] - 1 ) ) % MOD ;
                }
                hh *= 2 ;
            }
            cout << prod << "\n" ;
        }
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    init ( ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
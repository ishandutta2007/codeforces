#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
using namespace std ;

#define MAXN 100007
int n , MOD ;
int a[ MAXN ] ;

int cnt_divs ;
vector < int > divs ;

long long pw[ 11 ][ 18 * MAXN ] ;

struct node {
    long long sm ;
    int mul[ 11 ] ;
    long long lazy ;
    node ( ) {
        sm = 0 ; lazy = 1 ;
        for ( int i = 0 ; i < cnt_divs ; ++ i ) {
            mul[ i ] = 0 ;
        }
    }
};

long long upd_lazy ;
int add_mul[ 11 ] ;

class Tree {
public :
    node tr[ 5 * MAXN ] ;
    void push_lazy ( int where , int IL , int IR ) {
        if ( tr[ where ].lazy > 1 ) {
            tr[ where ].sm = ( tr[ where ].sm * tr[ where ].lazy ) % MOD ;
            if ( IL != IR ) {
                tr[ 2 * where ].lazy = ( tr[ 2 * where ].lazy * tr[ where ].lazy ) % MOD ;
                tr[ 2 * where + 1 ].lazy = ( tr[ 2 * where + 1 ].lazy * tr[ where ].lazy ) % MOD ;
            }
        }
        tr[ where ].lazy = 1 ;
        if ( IL != IR ) {
            for ( int i = 0 ; i < cnt_divs ; ++ i ) {
                tr[ where ].sm = ( tr[ where ].sm * pw[ i ][ tr[ where ].mul[ i ] ] ) % MOD ;
                tr[ 2 * where ].mul[ i ] += tr[ where ].mul[ i ] ;
                tr[ 2 * where + 1 ].mul[ i ] += tr[ where ].mul[ i ] ;
                tr[ where ].mul[ i ] = 0 ;
            }
        }
    }
    void merge ( int where ) {
        int l = 2 * where ;
        int r = l + 1 ;
        tr[ where ].sm = 0 ;
        for ( int i = l ; i <= r ; ++ i ) {
            long long aux = tr[ i ].sm ;
            aux = ( aux * tr[ i ].lazy ) % MOD ;
            for ( int j = 0 ; j < cnt_divs ; ++ j ) {
                aux = ( aux * pw[ j ][ tr[ i ].mul[ j ] ] ) % MOD ;
            }
            tr[ where ].sm = ( tr[ where ].sm + aux ) % MOD ;
        }
    }
    void init ( int where , int IL , int IR ) {
        tr[ where ] = node ( ) ;
        if ( IL == IR ) {
            for ( int i = 0 ; i < cnt_divs ; ++ i ) {
                while ( ( a[ IL ] % divs[ i ] ) == 0 ) {
                    ++ tr[ where ].mul[ i ] ;
                    a[ IL ] /= divs[ i ] ;
                }
            }
            tr[ where ].sm = ( a[ IL ] % MOD ) ;
            return ; 
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        merge ( where ) ;
    }
    void update_interval ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( CURL > CURR ) { return ; }
        if ( CURR < IL || IR < CURL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            tr[ where ].lazy = ( tr[ where ].lazy * upd_lazy ) % MOD ;
            for ( int i = 0 ; i < cnt_divs ; ++ i ) {
                tr[ where ].mul[ i ] += add_mul[ i ] ;
            }
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( CURL <= mid ) {
            update_interval ( 2 * where , IL , mid , CURL , CURR ) ;
        }
        if ( mid < CURR ) {
            update_interval ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
        }
        merge ( where ) ;
    }
    void update_position ( int where , int IL , int IR , int pos ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ].lazy = ( tr[ where ].lazy * upd_lazy ) % MOD ;
            for ( int i = 0 ; i < cnt_divs ; ++ i ) {
                tr[ where ].mul[ i ] += add_mul[ i ] ;
            }
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update_position ( 2 * where , IL , mid , pos ) ;
        }
        else {
            update_position ( 2 * where + 1 , mid + 1 , IR , pos ) ;
        }
        merge ( where ) ;
    }
    long long query ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < CURL || CURR < IL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) {
            long long ret = tr[ where ].sm ;
            for ( int i = 0 ; i < cnt_divs ; ++ i ) {
                ret = ( ret * pw[ i ][ tr[ where ].mul[ i ] ] ) % MOD ;
            }
            return ret ;
        }
        int mid = ( IL + IR ) / 2 ;
        long long ret = query ( 2 * where , IL , mid , CURL , CURR ) ;
        ret = ( ret + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) % MOD ;
        return ret ;
    }
};

Tree w ;

void init ( ) {
    int i = 2 ;
    int aux = MOD ;
    while ( i * i < aux ) {
        if ( ( aux % i ) == 0 ) {
            while ( ( aux % i ) == 0 ) {
                aux /= i ;
            }
            divs.push_back ( i ) ;
        }
        ++ i ;
    }
    if ( aux > 1 ) {
        divs.push_back ( aux ) ;
    }
    cnt_divs = divs.size ( ) ;
    for ( int i = 0 ; i < cnt_divs ; ++ i ) {
        pw[ i ][ 0 ] = 1 ;
        for ( int j = 1 ; j < 18 * MAXN ; ++ j ) {
            pw[ i ][ j ] = ( pw[ i ][ j - 1 ] * divs[ i ] ) % MOD ;
        }
    }
    w.init ( 1 , 1 , n ) ;
}

long long get_inv ( long long x ) {
    long long y = MOD ;
    pair < long long , long long > coef1 , coef2 ;
    coef1 = { 1 , 0 } ;
    coef2 = { 0 , 1 } ;
    while ( 1 ) {
        if ( x < y ) { swap ( x , y ) ; swap ( coef1 , coef2 ) ; }
        if ( y == 0 ) { return coef1.first ; }
        long long diff = ( x / y ) ;
        coef1.first -= ( diff * coef2.first ) % MOD ;
        coef1.second -= ( diff * coef2.second ) % MOD ;
        coef1.first = ( coef1.first + MOD ) % MOD ;
        coef1.second = ( coef1.second + MOD ) % MOD ;
        x %= y ;
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &MOD ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    init ( ) ;
    int q ;
    scanf ( "%d" , &q ) ;
    while ( q -- ) {
        int type ;
        scanf ( "%d" , &type ) ;
        if ( type == 1 ) {
            int l , r , x ;
            scanf ( "%d%d%d" , &l , &r , &x ) ;
            for ( int i = 0 ; i < cnt_divs ; ++ i ) {
                add_mul[ i ] = 0 ;
                while ( ( x % divs[ i ] ) == 0 ) {
                    x /= divs[ i ] ;
                    ++ add_mul[ i ] ;
                }
            }
            x %= MOD ;
            upd_lazy = x ;
            w.update_interval ( 1 , 1 , n , l , r ) ;
        }
        else if ( type == 2 ) {
            int pos , x ;
            scanf ( "%d%d" , &pos , &x ) ;
            for ( int i = 0 ; i < cnt_divs ; ++ i ) {
                add_mul[ i ] = 0 ;
                while ( ( x % divs[ i ] ) == 0 ) {
                    x /= divs[ i ] ;
                    -- add_mul[ i ] ;
                }
            }
            x %= MOD ;
            upd_lazy = get_inv ( x ) ;
            w.update_position ( 1 , 1 , n , pos ) ;
        }
        else {
            int l , r ;
            scanf ( "%d%d" , &l , &r ) ;
            printf ( "%I64d\n" , w.query ( 1 , 1 , n , l , r ) ) ;
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
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
#include<random>
using namespace std ;

#define MAXN 100007
#define MOD 998244353

int n ;
struct tuhla {
    int x , speed , pr[ 2 ] ;
};
struct event {
    int id ;
    int dir[ 2 ] ;
    double tm ;
    int dv1 , dv2 ;
    event ( ) {
        id = dir[ 0 ] = dir[ 1 ] = tm = 0 ;
    }
    event ( int _id , int _val0 , int _val1 , double _tm , int _dv1 , int _dv2 ) {
        id = _id ;
        dir[ 0 ] = _val0 ;
        dir[ 1 ] = _val1 ;
        tm = _tm ;
        dv1 = _dv1 ;
        dv2 = _dv2 ;
    }
    bool operator < ( event other ) const {
        return ( tm < other.tm ) ;
    }
};

tuhla a[ MAXN ] ;
long long inv[ 107 ] ;

long long fastpow ( long long x , long long st ) {
    long long ret = 1 ;
    while ( st > 0 ) {
        if ( ( st & 1 ) != 0 ) {
            ret = ( ret * x ) % MOD ;
            -- st ;
        }
        else {
            x = ( x * x ) % MOD ;
            st >>= 1 ;
        }
    }
    return ret ;
}


class Tree {
public :
    long long f[ 5 * MAXN ][ 2 ][ 2 ] ;
    void merge ( int where , int sr ) {
        int l = where << 1 ;
        int r = l + 1 ;
        for ( int i = 0 ; i < 2 ; ++ i ) {
            for ( int j = 0 ; j < 2 ; ++ j ) {
                f[ where ][ i ][ j ] = 0 ;
                for ( int t = 0 ; t < 2 ; ++ t ) {
                    long long aux = ( f[ l ][ i ][ t ] * f[ r ][ t ][ j ] ) % MOD ;
                    f[ where ][ i ][ j ] = ( f[ where ][ i ][ j ] + aux * inv[ a[ sr + 1 ].pr[ t ] ] ) % MOD ;
                }
            }
        }
    }
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            for ( int i = 0 ; i < 2 ; ++ i ) {
                for ( int j = 0 ; j < 2 ; ++ j ) {
                    f[ where ][ i ][ j ] = a[ IL ].pr[ i ] ;
                    f[ where ][ i ][ j ] = ( f[ where ][ i ][ j ] * a[ IL + 1 ].pr[ j ] ) % MOD ;
                }
            }
            return ;
        }
        int mid = ( IL + IR ) >> 1 ;
        init ( where << 1 , IL , mid ) ;
        init ( ( where << 1 ) + 1 , mid + 1 , IR ) ;
        merge ( where , mid ) ;
    }
    void update ( int where , int IL , int IR , int pos , int ban1 , int ban2 ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            f[ where ][ ban1 ][ ban2 ] = 0 ;
            return ;
        }
        int mid = ( IL + IR ) >> 1 ;
        if ( pos <= mid ) {
            update ( where << 1 , IL , mid , pos , ban1 , ban2 ) ;
        }
        else {
            update ( ( where << 1 ) + 1 , mid + 1 , IR , pos , ban1 , ban2 ) ;
        }
        merge ( where , mid ) ;
    }
    long long query ( ) {
        long long ret = 0 ;
        for ( int i = 0 ; i < 2 ; ++ i ) {
            for ( int j = 0 ; j < 2 ; ++ j ) {
                ret = ( ret + f[ 1 ][ i ][ j ] ) % MOD ;
            }
        }
        return ret ;
    }
};

Tree w ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d%d%d" , &a[ i ].x , &a[ i ].speed , &a[ i ].pr[ 1 ] ) ;
        a[ i ].pr[ 0 ] = ( 100 - a[ i ].pr[ 1 ] ) ;
    }
}

void solve ( ) {
    if ( n == 1 ) { printf ( "0\n" ) ; return ; }
    for ( int i = 0 ; i <= 100 ; ++ i ) {
        inv[ i ] = fastpow ( i , MOD - 2 ) ;
    }
    vector < event > srt ;
    for ( int i = 1 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < 2 ; ++ j ) {
            for ( int t = 0 ; t < 2 ; ++ t ) {
                if ( j == 0 && t == 1 ) { continue ; }
                int dist = a[ i + 1 ].x - a[ i ].x ;
                int h = j * a[ i ].speed + ( j - 1 ) * a[ i ].speed ;
                h += - ( t - 1 ) * a[ i + 1 ].speed - t * a[ i + 1 ].speed ;
                if ( h <= 0 ) { continue ; }
                srt.push_back ( event ( i , j , t , ( 1.00 * dist ) / h , dist , h ) ) ;
            }
        }
    }
    sort ( srt.begin ( ) , srt.end ( ) ) ;
    int sz = srt.size ( ) ;
    w.init ( 1 , 1 , n - 1 ) ;
    long long ans = 0 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        long long aux = w.query ( ) ;
        w.update ( 1 , 1 , n - 1 , srt[ i ].id , srt[ i ].dir[ 0 ] , srt[ i ].dir[ 1 ] ) ;
        aux = ( aux - w.query ( ) + MOD ) % MOD ;
        aux = ( aux * srt[ i ].dv1 ) % MOD ;
        aux = ( aux * fastpow ( srt[ i ].dv2 , MOD - 2 ) ) % MOD ;
        ans = ( ans + aux ) % MOD ;
    }
    ans = ( ans * fastpow ( inv[ 100 ] , n ) ) % MOD ;
    printf ( "%I64d\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
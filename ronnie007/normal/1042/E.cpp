#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<queue>
using namespace std ;

#define MAXN 1007

#define MOD 998244353

int n , m ;
int a[ MAXN ][ MAXN ] ;

int stx , sty ;

long long dp[ MAXN ][ MAXN ] ;

long long w[ MAXN ][ MAXN ] ;

struct tuhla {
    int val ;
    int x , y ;
    tuhla ( ) { val = x = y = 0 ; }
    tuhla ( int _val , int _x , int _y ) {
        val = _val ;
        x = _x ;
        y = _y ;
    }
};
vector < tuhla > v ;

long long fastpow ( long long aux , long long st ) {
    long long ret = 1 ;
    while ( st != 0 ) {
        if ( ( st % 2 ) == 0 ) {
            aux = ( aux * aux ) % MOD ;
            st /= 2 ;
        }
        else {
            ret = ( ret * aux ) % MOD ;
            st -- ;
        }
    }
    return ret ;
}


bool cmp ( tuhla p1 , tuhla p2 ) {
    return ( p1.val < p2.val ) ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 1 ; j <= m ; j ++ ) {
            scanf ( "%d" , &a[ i ][ j ] ) ;
            v.push_back ( tuhla ( a[ i ][ j ] , i , j ) ) ;
        }
    }
    scanf ( "%d%d" , &stx , &sty ) ;
    sort ( v.begin ( ) , v.end ( ) , cmp ) ;
}

void solve ( ) {
    int i , j ;
    long long w_sm = 0 ;
    long long x_1 = 0 ;
    long long x_2 = 0 ;
    long long y_1 = 0 ;
    long long y_2 = 0 ;
    int sz = v.size ( ) ;
    for ( j = 0 ; j < sz ; j ++ ) {
        if ( v[ j ].val != v[ 0 ].val ) { break ; }
        w[ v[ j ].x ][ v[ j ].y ] = 0 ;

        x_1 += v[ j ].x ;
        if ( x_1 >= MOD ) { x_1 -= MOD ; }
        x_2 += ( v[ j ].x * v[ j ].x ) ;
        if ( x_2 >= MOD ) { x_2 -= MOD ; }

        y_1 += v[ j ].y ;
        if ( y_1 >= MOD ) { y_1 -= MOD ; }
        y_2 += ( v[ j ].y * v[ j ].y ) ;
        if ( y_2 >= MOD ) { y_2 -= MOD ; }
    }
    for ( i = j ; i < sz ; i ++ ) {
        while ( v[ j ].val < v[ i ].val ) {
            w_sm += w[ v[ j ].x ][ v[ j ].y ] ;
            if ( w_sm >= MOD ) { w_sm -= MOD ; }

            x_1 += v[ j ].x ;
            if ( x_1 >= MOD ) { x_1 -= MOD ; }
            x_2 += ( v[ j ].x * v[ j ].x ) ;
            if ( x_2 >= MOD ) { x_2 -= MOD ; }

            y_1 += v[ j ].y ;
            if ( y_1 >= MOD ) { y_1 -= MOD ; }
            y_2 += ( v[ j ].y * v[ j ].y ) ;
            if ( y_2 >= MOD ) { y_2 -= MOD ; }

            j ++ ;
        }
        long long aux = w_sm % MOD ;
        long long p1 , p2 ;
        p1 = ( v[ i ].x * v[ i ].x ) ;
        p2 = ( v[ i ].y * v[ i ].y ) ;
        aux += p1 * j + p2 * j ;
        aux += x_2 + y_2 ;
        long long qq1 = ( x_1 * 2 * v[ i ].x ) ;
        qq1 %= MOD ;
        long long qq2 = ( y_1 * 2 * v[ i ].y ) ;
        qq2 %= MOD ;
        aux = ( aux % MOD ) ;
        aux = ( aux - qq1 + MOD ) % MOD ;
        aux = ( aux - qq2 + MOD ) % MOD ;
        aux = ( aux * fastpow ( j , MOD - 2 ) ) % MOD ;
        w[ v[ i ].x ][ v[ i ].y ] = aux ;
        if ( v[ i ].x == stx && v[ i ].y == sty ) { break ; }
    }
    printf ( "%I64d\n" , w[ stx ][ sty ] ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
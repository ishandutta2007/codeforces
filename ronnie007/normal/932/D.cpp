#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<stack>
using namespace std ;

#define MAXN 400007
#define LOG 20

long long n , q ;

long long dirprv[ MAXN ] ;
long long val[ MAXN ] ;

long long LCA[ MAXN ][ LOG ] ;
long long sm[ MAXN ][ LOG ] ;

long long lst ;

void add_vertex ( long long x , long long y ) {
    n ++ ;
    dirprv[ n ] = x ;
    val[ n ] = y ;
    long long cur = x ;
    long long i ;
    for ( i = LOG - 1 ; i >= 0 ; i -- ) {
        long long nw = LCA[ cur ][ i ] ;
        if ( nw == 0 ) { continue ; }
        if ( val[ nw ] < val[ n ] ) {
            cur = nw ;
        }
    }
    if ( val[ cur ] < val[ n ] ) {
        cur = LCA[ cur ][ 0 ] ;
    }
    LCA[ n ][ 0 ] = cur ;
    sm[ n ][ 0 ] = val[ n ] ;
    for ( i = 1 ; i < LOG ; i ++ ) {
        LCA[ n ][ i ] = LCA[ LCA[ n ][ i - 1 ] ][ i - 1 ] ;
        sm[ n ][ i ] = sm[ n ][ i - 1 ] + sm[ LCA[ n ][ i - 1 ] ][ i - 1 ] ;
    }
}

void calc ( long long x , long long y ) {
    lst = 0 ;
    if ( val[ x ] > y ) { printf ( "0\n" ) ; return ; }
    long long i ;
    long long cur = 0 ;
    for ( i = LOG - 1 ; i >= 0 ; i -- ) {
        long long nw = LCA[ x ][ i ] ;
        if ( nw == 0 ) { continue ; }
        if ( cur + sm[ x ][ i ] <= y ) {
            cur += sm[ x ][ i ] ;
            x = LCA[ x ][ i ] ;
            lst += (1<<i) ;
        }
    }
    if ( cur + val[ x ] <= y ) {
        cur += val[ x ] ;
        x = LCA[ x ][ 0 ] ;
        lst ++ ;
    }
    printf ( "%d\n" , lst ) ;
}

void input ( ) {
    scanf ( "%I64d" , &q ) ;
    n = 1 ;
    dirprv[ 1 ] = 0 ;
    val[ 1 ] = 0 ;
    lst = 0 ;
}

void solve ( ) {
    long long type ;
    long long x , y ;
    while ( q != 0 ) {
        q -- ;
        scanf ( "%I64d%I64d%I64d" , &type , &x , &y ) ;
        x ^= lst ;
        y ^= lst ;
        if ( type == 1 ) {
            add_vertex ( x , y ) ;
        }
        else {
            calc ( x , y ) ;
        }
    }
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
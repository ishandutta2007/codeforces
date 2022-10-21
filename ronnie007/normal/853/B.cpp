#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std ;

#define MAXN 1000007

int n , m , k ;

long long ans = 0 ;

long long cur ;

long long incost[ MAXN ] ;
long long outcost[ MAXN ] ;

int inlft[ MAXN ] ;
long long pref[ MAXN ] ;
int outlft[ MAXN ] ;
long long suff[ MAXN ] ;

bool used[ MAXN ] ;

int X[ MAXN ] ;
int Y[ MAXN ] ;
int Z[ MAXN ] ;
int T[ MAXN ] ;

struct tuhla {
    int vertex ;
    int tm ;
    int cost ;
    int id ;
    tuhla ( ) { vertex = tm = cost = id = 0 ; }
    tuhla ( int _vertex , int _tm , int _cost , int _id ) {
        vertex = _vertex ;
        tm = _tm ;
        cost = _cost ;
    }
};
vector < tuhla > ar[ MAXN ] ;
vector < tuhla > dep[ MAXN ] ;


void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &k ) ;
    int i ;
    for ( i = 1 ; i <= m ; i ++ ) {
        int x , y , z , t ;
        scanf ( "%d%d%d%d" , &x , &y , &z , &t ) ;
        X[ i ] = x ;
        Y[ i ] = y ;
        Z[ i ] = z ;
        T[ i ] = t ;
        if ( y == 0 ) {
            dep[ x ].push_back ( tuhla ( z , x , t , i ) ) ;
        }
        else {
            ar[ x ].push_back ( tuhla ( y , x , t , i ) ) ;
        }
    }
}

void solve ( ) {
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        used[ i ] = false ;
    }
    inlft[ 0 ] = n ;
    long long cur = 0 ;
    int lim = 1000000 ;
    for ( i = 1 ; i <= lim ; i ++ ) {
        int sz = ar[ i ].size ( ) ;
        inlft[ i ] = inlft[ i - 1 ] ;
        for ( j = 0 ; j < sz ; j ++ ) {
            if ( used[ ar[ i ][ j ].vertex ] == false ) {
                used[ ar[ i ][ j ].vertex ] = true ;
                inlft[ i ] -- ;
                incost[ ar[ i ][ j ].vertex ] = ar[ i ][ j ].cost ;
                cur += ar[ i ][ j ].cost ;
            }
            if ( ar[ i ][ j ].cost < incost[ ar[ i ][ j ].vertex ] ) {
                cur = ( cur - incost[ ar[ i ][ j ].vertex ] + ar[ i ][ j ].cost ) ;
                incost[ ar[ i ][ j ].vertex ] = ar[ i ][ j ].cost ;
            }
        }
        pref[ i ] = cur ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        used[ i ] = false ;
    }
    outlft[ lim + 1 ] = n ;
    cur = 0 ;
    for ( i = lim ; i >= 1 ; i -- ) {
        int sz = dep[ i ].size ( ) ;
        outlft[ i ] = outlft[ i + 1 ] ;
        for ( j = 0 ; j < sz ; j ++ ) {
            if ( used[ dep[ i ][ j ].vertex ] == false ) {
                used[ dep[ i ][ j ].vertex ] = true ;
                outlft[ i ] -- ;
                outcost[ dep[ i ][ j ].vertex ] = dep[ i ][ j ].cost ;
                cur += dep[ i ][ j ].cost ;
            }
            if ( dep[ i ][ j ].cost < outcost[ dep[ i ][ j ].vertex ] ) {
                cur = ( cur - outcost[ dep[ i ][ j ].vertex ] + dep[ i ][ j ].cost ) ;
                outcost[ dep[ i ][ j ].vertex ] = dep[ i ][ j ].cost ;
            }
        }
        suff[ i ] = cur ;
    }
    long long ans = -1 ;
    for ( i = 1 ; i + k + 1 <= lim ; i ++ ) {
        if ( inlft[ i ] == 0 && outlft[ i + k + 1 ] == 0 ) {
            long long cur = pref[ i ] + suff[ i + k + 1 ] ;
            if ( ans == -1 ) { ans = cur ; }
            if ( ans > cur ) { ans = cur ; }
        }
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
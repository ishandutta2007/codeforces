#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std ;

#define MAXN 107

int n , m ;
int a[ MAXN ][ MAXN ] ;
int cl[ MAXN ] ;
int rw[ MAXN ] ;

vector < pair < int , int > > v ;

vector < pair < int , int > > calc ( int x ) {
    int i , j ;
    vector < pair < int , int > > ret ;
    for ( i = 1 ; i <= m ; i ++ ) {
        cl[ i ] = a[ 1 ][ i ] - x ;
        if ( cl[ i ] < 0 ) { return ret ; }
    }
    rw[ 1 ] = x ;
    for ( i = 2 ; i <= n ; i ++ ) {
        rw[ i ] = a[ i ][ 1 ] - cl[ 1 ] ;
        if ( rw[ i ] < 0 ) { return ret ; }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 1 ; j <= m ; j ++ ) {
            if ( rw[ i ] + cl[ j ] != a[ i ][ j ] ) { return ret ; }
        }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        while ( rw[ i ] != 0 ) {
            rw[ i ] -- ;
            ret.push_back ( make_pair ( 0 , i ) ) ;
        }
    }
    for ( i= 1 ; i <= m ; i ++ ) {
        while ( cl[ i ] != 0 ) {
            cl[ i ] -- ;
            ret.push_back ( make_pair ( 1 , i ) ) ;
        }
    }
    return ret ;
}

void input ( ) {
    scanf ( "%d%d", &n , &m ) ;
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 1 ; j <= m ; j ++ ) {
            scanf ( "%d" , &a[ i ][ j ] ) ;
        }
    }
}

void solve ( ) {
    int i , j ;
    int sm = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 1 ; j <= m ; j ++ ) {
            sm += a[ i ][ j ] ;
        }
    }
    if ( sm == 0 ) { printf ( "0\n" ) ; return ; }
    v.clear ( ) ;
    for ( i = 0 ; i <= 500 ; i ++ ) {
        vector < pair < int , int > > ret = calc ( i ) ;
        if ( ret.size ( ) == 0 ) { continue ; }
        if ( v.size ( ) == 0 || v.size ( ) > ret.size ( ) ) {
            v.clear ( ) ;
            int sz = ret.size ( ) ;
            for ( j = 0 ; j < sz ; j ++ ) {
                v.push_back ( ret[ j ] ) ;
            }
        }
    }
    int sz = v.size ( ) ;
    if ( sz == 0 ) { printf ( "-1\n" ) ; return ; }
    printf ( "%d\n" , sz ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ i ].first == 0 ) { printf ( "row " ) ; }
        else { printf ( "col " ) ; }
        printf ( "%d\n" , v[ i ].second ) ;
    }
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
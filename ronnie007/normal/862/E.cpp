#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

#define MAXN 100007

int n , m , q ;
int a[ MAXN ] ;
int b[ MAXN ] ;

int totlen ;

long long init[ MAXN ] ;

long long pref1[ MAXN ] ;
long long pref2[ MAXN ] ;
long long offset = 0 ;

long long getl ( long long sr ) {
    int l , r , mid ;
    l = 0 ;
    r = ( m - n ) ;
    if ( init[ 0 ] > sr ) { return ( sr + 1 ) ; }
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( init[ mid ] <= sr ) { l = mid ; }
        else { r = mid ; }
    }
    while ( init[ r ] > sr ) { r -- ; }
    return init[ r ] ;
}

long long getr ( long long sr ) {
    int l , r , mid ;
    l = 0 ;
    r = ( m - n ) ;
    if ( init[ m - n ] < sr ) { return ( sr - 1 ) ; }
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( init[ mid ] >= sr ) { r = mid ; }
        else { l = mid ; }
    }
    while ( init[ l ] < sr ) { l ++ ; }
    return init[ l ] ;
}

long long get_ans ( long long offset ) {
    long long h1 = getl ( offset ) ;
    long long h2 = getr ( offset ) ;
    long long ret = -1 ;
    if ( h1 <= offset ) {
        ret = offset - h1 ;
    }
    if ( h2 >= offset ) {
        if ( ret == -1 ) {
            ret = h2 - offset ;
        }
        if ( ret > ( h2 - offset ) ) {
            ret = ( h2 - offset ) ;
        }
    }
    return ret ;
}

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &q ) ;
    int i ;
    pref1[ 0 ] = pref2[ 0 ] = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        pref1[ i ] = pref1[ i - 1 ] ;
        pref2[ i ] = pref2[ i - 1 ] ;
        if ( ( i % 2 ) == 1 ) {
            pref1[ i ] = ( pref1[ i ] + a[ i ] ) ;
            pref2[ i ] = ( pref2[ i ] - a[ i ] ) ;
        }
        else {
            pref1[ i ] = ( pref1[ i ] - a[ i ] ) ;
            pref2[ i ] = ( pref2[ i ] + a[ i ] ) ;
        }
    }
    offset = -pref1[ n ] ;
    for ( i = 1 ; i <= m ; i ++ ) {
        scanf ( "%d" , &b[ i ] ) ;
        pref1[ i ] = pref1[ i - 1 ] ;
        pref2[ i ] = pref2[ i - 1 ] ;
        if ( ( i % 2 ) == 1 ) {
            pref1[ i ] = ( pref1[ i ] + b[ i ] ) ;
            pref2[ i ] = ( pref2[ i ] - b[ i ] ) ;
        }
        else {
            pref1[ i ] = ( pref1[ i ] - b[ i ] ) ;
            pref2[ i ] = ( pref2[ i ] + b[ i ] ) ;
        }
    }
    for ( i = 0 ; i <= m - n ; i ++ ) {
        int st = ( i + 1 ) ;
        if ( ( st % 2 ) == 0 ) {
            init[ i ] += pref1[ n + st - 1 ] - pref1[ st - 1 ] ;
        }
        else {
            init[ i ] += pref2[ n + st - 1 ] - pref2[ st - 1 ] ;
        }
    }
    sort ( init , init + ( m - n ) + 1 ) ;
}

void solve ( ) {
    int i ;

    printf ( "%I64d\n" , get_ans ( offset ) ) ;
    for ( i = 1 ; i <= q ; i ++ ) {
        int x , y , z ;
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        if ( ( ( y - x + 1 ) % 2 ) == 1 ) {
            if ( ( x % 2 ) == 0 ) { offset += z ; }
            else { offset -= z ; }
        }
        printf ( "%I64d\n" , get_ans ( offset ) ) ;
    }
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
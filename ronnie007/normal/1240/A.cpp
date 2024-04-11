#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 200007

int n ;
long long a[ MAXN ] ;

long long x , p1 ;
long long y , p2 ;
long long comb ;
long long sr ;


bool f ( int pos ) {
    long long sm = 0 ;
    int cnt1 = pos / comb ;
    int cnt2 = pos / p1 - cnt1 ;
    int cnt3 = pos / p2 - cnt1 ;
    for ( int i = 1 ; i <= cnt1 ; ++ i ) {
        sm += ( a[ i ] / 100 ) * ( x + y ) ;
    }
    for ( int i = 1 ; i <= cnt2 ; ++ i ) {
        sm += ( a[ cnt1 + i ] / 100 ) * x ;
    }
    for ( int i = 1 ; i <= cnt3 ; ++ i ) {
        sm += ( a[ cnt1 + cnt2 + i ] / 100 ) * y ;
    }
    return ( sm >= sr ) ;
}

long long w ( long long x , long long y ) {
    if ( x < y ) { swap ( x , y ) ; }
    if ( y == 0 ) { return x ; }
    return w ( y , ( x % y ) ) ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%I64d" , &a[ i ] ) ;
        a[ i ] = -a[ i ] ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        a[ i ] = -a[ i ] ;
    }
    scanf ( "%I64d%I64d" , &x , &p1 ) ;
    scanf ( "%I64d%I64d" , &y , &p2 ) ;
    if ( x < y ) { swap ( x , y ) , swap ( p1 , p2 ) ; }
    comb = ( p1 * p2 ) / w ( p1 , p2 ) ;
    scanf ( "%I64d" , &sr ) ;
}

void solve ( ) {
    int l , r , mid ;
    l = 1 ;
    r = n ;
    if ( f ( n ) == false ) { printf ( "-1\n" ) ; return ; }
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( f ( mid ) == true ) { r = mid ; }
        else { l = mid ; }
    }
    while ( f ( l ) == false ) { ++ l ; }
    printf ( "%d\n" , l ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int q ;
    scanf ( "%d" , &q ) ;
    while ( q -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
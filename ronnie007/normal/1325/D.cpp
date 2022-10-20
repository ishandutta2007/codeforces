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

long long sm , xr ;

long long a[ 17 ] ;

void input ( ) {
    scanf ( "%I64d%I64d" , &xr , &sm ) ;
    a[ 1 ] = xr ;
}

void solve ( ) {
    if ( xr > sm ) { printf ( "-1\n" ) ; return ; }
    for ( int i = 60 ; i >= 0 ; -- i ) {
        long long x = (1LL<<i) ;
        int st = 1 ;
        if ( sm - xr >= 2LL * x ) {
            if ( (a[ 1 ]&x) > 0 ) { ++ st ; }
            while ( sm - xr >= 2LL * x ) {
                a[ st ] += x ;
                ++ st ;
                a[ st ] += x ;
                ++ st ;
                sm -= 2 * x ;
            }
        }
    }
    if ( sm > xr ) { printf ( "-1\n" ) ; return ; }
    int sz = 0 ;
    for ( int i = 1 ; i <= 15 ; ++ i ) {
        if ( a[ i ] > 0 ) { sz = i ; }
    }
    printf ( "%d\n" , sz ) ;
    for ( int i = 1 ; i <= sz ; ++ i ) {
        printf ( "%I64d\n" , a[ i ] ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
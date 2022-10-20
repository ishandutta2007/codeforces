#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 100007

int n , q ;
int a[ 2 * MAXN ] ;
int mx ;

pair < int , int >  ans[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        mx = ( mx < a[ i ] ) ? a[ i ] : mx ;
    }
}

void solve ( ) {
    int period = 0 ;
    while ( a[ period + 1 ] != mx ) {
        ++ period ;
        ans[ period ] = { a[ period ] , a[ period + 1 ] } ;
        int f1 = ( a[ period ] > a[ period + 1 ] ) ? a[ period ] : a[ period + 1 ] ;
        int f2 = ( a[ period ] < a[ period + 1 ] ) ? a[ period ] : a[ period + 1 ] ;
        a[ period + 1 ] = f1 , a[ period + n ] = f2 ;

    }
    while ( q != 0 ) {
        -- q ;
        long long x ; scanf ( "%I64d" , &x ) ;
        if ( x <= period ) {
            printf ( "%d %d\n" , ans[ x ].first , ans[ x ].second ) ;
        }
        else {
            x = ( x - period - 1 ) % ( n - 1 ) ;
            printf ( "%d %d\n" , mx , a[ period + 2 + x ] ) ;
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
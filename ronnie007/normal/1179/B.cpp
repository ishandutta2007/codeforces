#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std ;

int n , m ;

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
}

void solve ( ) {
    int x , y , p , q ;
    x = y = 1 ; p = n , q = m ;
    int upch = 1 , downch = -1 ;
    long long steps = ( 1LL * n * m ) / 2 ;
    while ( steps > 0 ) {
        printf ( "%d %d\n" , x , y ) ;
        if ( p != x || q != y ) {
            printf ( "%d %d\n" , p , q ) ;
        }
        -- steps ;
        y += upch ;
        if ( y == ( m + 1 ) ) {
            -- y , ++ x ;
            upch = ( 0 - upch ) ;
        }
        else if ( y == 0 ) {
            ++ y , ++ x ;
            upch = ( 0 - upch ) ;
        }


        q += downch ;
        if ( q == ( m + 1 ) ) {
            -- q , -- p ;
            downch = ( 0 - downch ) ;
        }
        else if ( q == 0 ) {
            ++ q , -- p ;
            downch = ( 0 - downch ) ;
        }
    }
    if ( (1LL * n * m ) % 2 == 1 ) {
        printf ( "%d %d\n" , ( ( n + 1 ) / 2 ) , ( ( m + 1 ) / 2 ) ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
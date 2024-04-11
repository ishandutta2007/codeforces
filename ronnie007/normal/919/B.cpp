#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std ;

int k ;

int f ( int x ) {
    int ret = 0 ;
    while ( x != 0 ) {
        ret += ( x % 10 ) ;
        x /= 10 ;
    }
    return ret ;
}

void input ( ) {
    scanf ( "%d" , &k ) ;
}

void solve ( ) {
    int x = 1 ;
    while ( 1 ) {
        if ( f ( x ) == 10 ) {
            k -- ;
            if ( k == 0 ) { printf ( "%d\n" , x ) ; return ; }
        }
        x ++ ;
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
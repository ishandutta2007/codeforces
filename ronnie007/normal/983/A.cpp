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

int64_t p , q , b ;

int64_t f ( int64_t x , int64_t y ) {
    if ( x < y ) { swap ( x , y ) ; }
    if ( y == 0 ) { return x ; }
    return f ( y , ( x % y ) ) ;
}

void input ( ) {
    scanf ( "%I64d%I64d%I64d" , &p , &q , &b ) ;
}

void solve ( ) {
    int64_t w = f ( p , q ) ;
    q /= w ;
    while ( q > 1 ) {
        long long aux = f ( q , b ) ;
        if ( aux == 1 ) {
            printf ( "Infinite\n" ) ;
            return ;
        }
        else {
            while ( q % aux == 0 ) {
                q /= aux ;
            }
            if ( q == 1 ) {
                break ;
            }
        }
    }
    printf ( "Finite\n" ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
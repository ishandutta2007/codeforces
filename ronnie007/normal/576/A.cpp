#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std ;

#define MAXN 1007

int n ;
vector < int > ans ;

bool f[ MAXN ] ;

void input ( ) {
    scanf ( "%d", &n ) ;
}

void solve ( ) {
    int i , j ;
    for ( i = 2 ; i <= n ; i ++ ) {
        if ( f[ i ] == true ) { continue ; }
        for ( j = 2 * i ; j <= n ; j += i ) {
            f[ j ] = true ;
        }
        int x = i ;
        while ( x <= n ) {
            ans.push_back ( x ) ;
            x *= i ;
        }
    }
    int sz = ans.size ( ) ;
    printf ( "%d\n", sz ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        printf ( "%d", ans[ i ] ) ;
        if ( i == ( sz - 1 ) ) { printf ( "\n" ) ; }
        else { printf ( " " ) ; }
    }
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
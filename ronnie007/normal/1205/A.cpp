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
int a[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
}

void solve ( ) {
    if ( ( n % 2 ) == 0 ) { printf ( "NO\n" ) ; }
    else {
        int p = 1 ;
        int q = n + 1 ;
        int val = 1 ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            a[ p ] = val ++ ;
            a[ q ] = val ++ ;
            swap ( p , q ) , ++ p , ++ q ;
        }
        printf ( "YES\n" ) ;
        for ( int i = 1 ; i <= 2 * n ; ++ i ) {
            printf ( "%d " , a[ i ] ) ;
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
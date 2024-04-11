#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<cstdlib>
using namespace std ;

#define MAXN 300007

int n ;
long long a[ MAXN ] ;

vector < long long > divs[ MAXN ] ;

void init ( ) {
    int i , j ;
    for ( i = 1 ; i < MAXN ; i ++ ) {
        for ( j = i ; j < MAXN ; j += i ) {
            divs[ j ].push_back ( i ) ;
        }
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 2 ; i <= n ; i += 2 ) {
        scanf ( "%I64d" , &a[ i ] ) ;
    }
    init ( ) ;
}

void solve ( ) {
    int i , j ;
    a[ 0 ] = 1 ;
    long long lst = 0 ;
    long long pref = 0 ;
    for ( i = 2 ; i <= n ; i += 2 ) {
        int sz = divs[ a[ i ] ].size ( ) ;
        for ( j = sz - 1 ; j >= 0 ; j -- ) {
            if ( divs[ a[ i ] ][ j ] > divs[ a[ i ] ][ sz - j - 1 ] ) { continue ; }
            long long x = divs[ a[ i ] ][ j ] ;
            long long y = divs[ a[ i ] ][ sz - j - 1 ] ;
            if ( ( x + y ) % 2 != 0 ) { continue ; }
            long long p , q ;
            p = ( x + y ) / 2 ;
            q = ( y - x ) / 2 ;
            if ( lst >= q ) { continue ; }
            a[ i - 1 ] = ( q * q - pref ) ;
            pref += a[ i - 1 ] ;
            pref += a[ i ] ;
            lst = p ;
            break ;
        }
        if ( j < 0 ) { printf ( "No\n" ) ; return ; }
    }
    printf ( "Yes\n" ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
        printf ( "%I64d " , a[ i ] ) ;
    }
    printf ( "\n" ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
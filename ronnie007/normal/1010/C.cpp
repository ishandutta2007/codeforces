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
using namespace std ;

#define MAXN 100007

int n , k ;
int a[ MAXN ] ;

bool fl[ MAXN ] ;

int w ( int x , int y ) {
    if ( x < y ) { swap ( x , y ) ; }
    if ( y == 0 ) { return x ; }
    return w ( y , ( x % y ) ) ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int h = 0 ;
    bool zero = false ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        int aux = ( a[ i ] % k ) ;
        if ( aux != 0 ) {
            if ( h == 0 ) { h = aux ; }
            h = w ( h , aux ) ;
        }
        else { zero = true ; }
    }
    if ( h != 0 ) {
        int cur = h ;
        while ( 1 ) {
            if ( fl[ cur ] == true ) { break ; }
            fl[ cur ] = true ;
            cur += h ;
            if ( cur >= k ) { cur -= k ; }
        }
    }
    if ( zero == true ) { fl[ 0 ] = true ; }
    vector < int > v ;
    for ( i = 0 ; i < k ; i ++ ) {
        if ( fl[ i ] == true ) { v.push_back ( i ) ; }
    }
    int sz = v.size ( ) ;
    printf ( "%d\n" , sz ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        printf ( "%d" , v[ i ] ) ;
        if ( i == ( sz - 1 ) ) { printf ( "\n" ) ; }
        else { printf ( " " ) ; }
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std ;

#define MAXN 2007

long long p ;
int k ;

int a[ MAXN ] ;


void input ( ) {
    cin >> p >> k ;
}

void solve ( ) {
    int n = 0 ;
    while ( p != 0 ) {
        a[ n ] = ( p % k ) ;
        n ++ ;
        p /= k ;
    }
    int i , j ;
    for ( i = 0 ; i < n ; i ++ ) {
        while ( a[ i ] >= k ) {
            a[ i ] -= k ;
            a[ i + 1 ] ++ ;
            if ( i == ( n - 1 ) ) { n ++ ; }
        }
        if ( ( i % 2 ) == 1 ) {
            if ( a[ i ] != 0 ) {
                a[ i ] = ( k - a[ i ] ) ;
                a[ i + 1 ] ++ ;
                if ( i == ( n - 1 ) ) { n ++ ; }
            }
        }
        while ( a[ i ] >= k ) {
            a[ i ] -= k ;
            a[ i + 1 ] ++ ;
            if ( i == ( n - 1 ) ) { n ++ ; }
        }
    }
    cout << n << "\n" ;
    for ( i = 0 ; i < n ; i ++ ) {
        cout << a[ i ] ;
        if ( i == ( n - 1 ) ) { cout << "\n" ; }
        else { cout << " " ; }
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
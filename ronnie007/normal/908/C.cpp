#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
using namespace std ;

#define MAXN 1007

int n ;
double r ;
int a[ MAXN ] ;

double h[ MAXN ] ;

double ans[ MAXN ] ;

void input ( ) {
    cin >> n >> r ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    int i , j ;
    for ( i = 1 ; i <= 1000 ; i ++ ) {
        h[ i ] = 0.0000000 ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        double mx = 0.000000 ;
        for ( j = 1 ; j <= 1000 ; j ++ ) {
            double dist = ( a[ i ] - j ) ;
            if ( dist < 0 ) { dist = 0 - dist ; }
            double k = ( 4*r*r - dist * dist ) ;
            if ( k < 0 ) { continue ; }
            k = sqrt ( k ) + h[ j ] - r ;
            if ( mx < k ) { mx = k ; }
        }
        ans[ i ] = mx ;
        h[ a[ i ] ] = mx + r ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        printf ( "%.12lf " , ans[ i ] ) ;
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 19

int n ;
double a[ MAXN ][ MAXN ] ;
double dp[ (1<<MAXN) ] ;


void input ( ) {
    scanf ( "%d" , &n ) ;
    int i , j ;
    for ( i = 0 ; i < n ; i ++ ) {
        for ( j = 0 ; j < n ; j ++ ) {
            scanf ( "%lf" , &a[ i ][ j ] ) ;
        }
    }
}

void solve ( ) {
    int i , j , t ;
    dp[ (1<<n) - 1 ] = 1.000000 ;
    vector < int > v ;
    for ( i = (1<<n) - 1 ; i >= 1 ; i -- ) {
        v.clear ( ) ;
        for ( j = 0 ; j < n ; j ++ ) {
            if ( (i&(1<<j)) != 0 ) { v.push_back ( j ) ; }
        }
        int sz = v.size ( ) ;
        for ( j = 0 ; j < sz ; j ++ ) {
            for ( t = j + 1 ; t < sz ; t ++ ) {
                dp[ ( i - (1<<v[ t ]) ) ] += ( 1.00 / ( sz * ( sz - 1 ) / 2 ) ) * dp[ i ] * a[ v[ j ] ][ v[ t ] ] ;
                dp[ ( i - (1<<v[ j ]) ) ] += ( 1.00 / ( sz * ( sz - 1 ) / 2 ) ) * dp[ i ] * a[ v[ t ] ][ v[ j ] ] ;
            }
        }
    }
    for ( i = 0 ; i < n ; i ++ ) {
        printf ( "%.12Lf" , dp[ (1<<i) ] ) ;
        if ( i == ( n - 1 ) ) { printf ( "\n" ) ; }
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
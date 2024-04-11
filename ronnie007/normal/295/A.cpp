#include<iostream>
#include<stdio.h>
using namespace std ;

int n , m , k ;
int a[ 100007 ] ;
long long cnt[ 100007 ] ;
long long add[ 100007 ] ;
int l[ 100007 ] ;
int r[ 100007 ] ;
int d[ 100007 ] ;

int main ( ) {
    scanf ( "%d%d%d" , &n , &m , &k ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( i = 0 ; i < m ; i ++ ) {
        scanf ( "%d%d%d" , &l[ i ] , &r[ i ] , &d[ i ] ) ;
        l[ i ] -- ;
        r[ i ] -- ;
    }
    int x , y ;
    for ( i = 0 ; i < k ; i ++ ) {
        scanf ( "%d%d" , &x , &y ) ;
        x -- ;
        y -- ;
        cnt[ x ] ++ ;
        cnt[ y + 1 ] -- ;
    }
    for ( i = 0 ; i < m ; i ++ ) {
        cnt[ i + 1 ] += cnt[ i ] ;
    }
    for ( i = 0 ; i < m ; i ++ ) {
        add[ l[ i ] ] += cnt[ i ] * d[ i ] ;
        add[ r[ i ] + 1 ] -= cnt[ i ] * d[ i ] ;
    }
    for ( i = 0 ; i < n ; i ++ ) {
        add[ i + 1 ] += add[ i ] ;
    }
    for ( i = 0 ; i < n ; i ++ ) {
        printf ( "%I64d " , a[ i ] + add[ i ] ) ;
    }
    printf ( "\n" ) ;
    return 0 ;
}
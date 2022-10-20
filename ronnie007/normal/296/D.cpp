#include<iostream>
#include<stdio.h>
using namespace std ;

int n ;
int a[ 507 ][ 507 ] ;
int dist[ 507 ][ 507 ] ;
int x[ 507 ] ;
bool used[ 507 ] ;
long long ans[ 507 ] ;


int main ( ) {
    int i , j , t ;
    scanf ( "%d" , &n ) ;
    for ( i = 0 ; i < n ; i ++ ) {
        for ( j = 0 ; j < n ; j ++ ) {
            scanf ( "%d" , &a[ i ][ j ] ) ;
            dist[ i ][ j ] = a[ i ][ j ] ;
        }
    }
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &x[ i ] ) ;
        x[ i ] -- ;
    }
    for ( i = n - 1 ; i >= 0 ; i -- ) {
        ans[ i ] = 0 ;
        used[ x[ i ] ] = true ;
        for ( j = 0 ; j < n ; j ++ ) {
            for ( t = 0 ; t < n ; t ++ ) {
                dist[ j ][ t ] = min ( dist[ j ][ t ] , dist[ j ][ x[ i ] ] + dist[ x[ i ] ][ t ] ) ;
            }
        }
        for ( j = 0 ; j < n ; j ++ ) {
            for ( t = 0 ; t < n ; t ++ ) {
                if ( used[ j ] == true && used[ t ] == true ) ans[ i ] += dist[ j ][ t ] ;
            }
        }
    }
    for ( i = 0 ; i < n ; i ++ ) {
        printf ( "%I64d " , ans[ i ] ) ;
    }
    printf ( "\n" ) ;
    return 0 ;
}
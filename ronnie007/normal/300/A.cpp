#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std ;

int n ;
int a[ 1007 ] ;
int brmin = 0 ;

int main ( )
    {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &a[ i ] ) ;
        }
    sort ( a , a + n ) ;
    printf ( "1 %d\n" , a[ 0 ] ) ;
    int br = 0 ;

    for ( i = 1 ; i < n ; i ++ )
        {
        if ( a[ i ] != 0 ) br ++ ;
        if ( a[ i ] < 0 ) brmin ++ ;
        }
    if ( brmin % 2 == 1 ) { brmin -- ; br -- ; }
    printf ( "%d " , br ) ;
    for ( i = 1 ; i < n ; i ++ )
        {
        if ( a[ i ] < 0 && brmin > 0  )
            {
            brmin -- ;
            printf ( "%d " , a[ i ] ) ;
            }
        if ( a[ i ] > 0 )
            {
            printf ( "%d " , a[ i ] ) ;
            }
        }
    printf ( "\n" ) ;
    int p = 1 ;
    if ( br + 2 != n ) p ++ ;
    for ( i = 1 ; i < n ; i ++ )
        {
        if ( a[ i ] == 0 )
            {
            if ( p == 2 ) printf ( "2 %d %d " , a[ i - 1 ] , a[ i ] ) ;
            else printf ( "1 %d\n" , a[ i ] ) ;
            }
        }

    return 0 ;
    }
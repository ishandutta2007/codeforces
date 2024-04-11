#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std ;

int n ;
int a[ 107 ] ;

int main ( )
    {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &a[ i ] ) ;
        }
    sort ( a , a + n ) ;
    swap ( a[ 0 ] , a[ n - 1 ] ) ;
    for ( i = 0 ; i < n ; i ++ )
        {
        printf ( "%d " , a[ i ] ) ;
        }
    printf ( "\n" ) ;
    return 0 ;
    }
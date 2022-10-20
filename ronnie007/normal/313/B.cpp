#include<iostream>
#include<stdio.h>
#include<string>
using namespace std ;

int f[ 200007 ] ;

int main ( )
    {
    string a ;
    cin >> a ;
    int i ;
    f[ 0 ] = 0 ;
    int n = a.size ( ) ;
    for ( i = 0 ; i < n ; i ++ )
        {
        if ( a[ i ] == a[ i - 1 ] ) f[ i ] = f[ i - 1 ] + 1 ;
        else f[ i ] = f[ i - 1 ] ;
        }
    int k ;
    int x , y ;
    scanf ( "%d" , &k ) ;
    for ( i = 0 ; i < k ; i ++ )
        {
        scanf ( "%d%d" , &x , &y ) ;
        printf( "%d\n" , f[ y - 1 ] - f[ x - 1 ] ) ;
        }
    return 0 ;
    }
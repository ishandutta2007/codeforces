#include<iostream>
#include<stdio.h>
using namespace std ;


int a[ 107 ] ;

int main ( )
    {
    int n , k , t ;
    cin >> n >> k >> t ;
    int i , j ;
    int x = ( n * k * t ) / 100 ;
    for ( i = 0 ; i <= 100 ; i ++ )
        {
        a[ i ] = 0 ;
        }
    for ( i = 1 ; i <= 100 ; i ++ )
        {
        for ( j = 1 ; j <= k ; j ++ )
            {
            if ( x == 0 )
            break ;

            a[ i ] ++ ;
            x -- ;
            }
        if ( x == 0 )break;
        }
    for ( i = 1 ; i <= n ; i ++ )
        {
        cout << a[ i ] << " " ;
        }
    cout << "\n" ;
    return 0 ;
    }
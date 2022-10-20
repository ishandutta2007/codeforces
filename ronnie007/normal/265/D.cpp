#include<iostream>
#include<stdio.h>
using namespace std ;

int n ;
int a[ 100007 ] ;
int lst[ 100007 ] ;
int dp[ 100007 ] ;

int main ( )
    {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ )
        {
        scanf ( "%d" , &a[ i ] ) ;
        }
    int p ;
    int ans = 0 ;
    int mx = 0 ;
    for ( i = 1 ; i <= n ; i ++ )
        {
        p = 2 ;
        ans = 1 ;
        while ( a[ i ] != 1 )
            {
            if ( p * p > a[ i ] ) break ;
            if ( a[ i ] % p == 0 )
                {
                if ( ans < dp[ lst[ p ] ] + 1 && lst[ p ] != i ) ans = dp[ lst[ p ] ] + 1 ;
                lst[ p ] = i ;
                a[ i ] = a[ i ] / p ;
                }
            else p ++ ;
            }
        if ( a[ i ] != 1 )
            {
            if ( ans < dp[ lst[ a[ i ] ] ] + 1 && lst[ a[ i ] ] != i ) ans = dp[ lst[ a[ i ] ] ] + 1 ;
            lst[ a[ i ] ] = i ;
            a[ i ] = a[ i ] / a[ i ] ;
            }

        dp[ i ] = ans ;
        if ( mx < ans ) mx = ans ;
        }
    printf ( "%d\n" , mx ) ;
    return 0 ;
    }
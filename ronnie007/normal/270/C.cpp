#include<iostream>
#include<stdio.h>
using namespace std ;

int n ;
int a , k ;


int main ( )
    {
    scanf ( "%d" , &n ) ;
    int i ;
    int p = 0 , mx = 0 ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d%d" , &k , &a ) ;
        if ( mx < k ) mx = k ;
        int m = 0 , s = 1 ;
        while ( s < a )
            {
            s = s * 4 ;
            m ++ ;
            }
        if ( p < k + m ) p = k + m ;
        }
    if ( p == mx ) p ++ ;
    printf ( "%d\n" , p ) ;
    return 0 ;
    }
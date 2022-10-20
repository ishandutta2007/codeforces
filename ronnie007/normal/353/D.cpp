#include<iostream>
#include<stdio.h>
using namespace std ;

int n ;
string a ;

int main ( )
    {
    cin >> a ;
    n = a.size ( ) ;
    int i ;
    int br = 0 ;
    int ans = 0 ;
    int w = 0 ;
    for ( i = 0 ; i < n ; i ++  )
        {
        if ( a[ i ] == 'F' )
            {
            ans = max ( ans , i - br + w ) ;
            if ( i - br + w  != 0 ) w ++ ;
            br ++ ;
            }
        else
            {
            w -- ;
            if ( w < 0 ) w = 0 ;
            }
        }
    printf ( "%d\n" , ans ) ;
    return 0 ;
    }
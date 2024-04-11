#include<iostream>
#include<stdio.h>
#include<set>
using namespace std ;


bool ispr ( int x )
    {
    int i ;
    for ( i = 2 ; i * i <= x ; i ++ )
        {
        if ( x % i == 0 ) return false ;
        }
    return true ;
    }

bool f ( int x )
    {
    int i , j ;
    i = 2 ;
    set < int > s ;
    while ( x != 1 )
        {
        if ( x % i == 0 )
            {
            x /= i ;
            if ( ispr ( i ) == true ) s.insert ( i ) ;
            }
        else i ++ ;
        }
    if ( s.size ( ) == 2 ) return true ;
    return false ;
    }


int main ( )
    {
    int n ;
    int i ;
    int ans = 0 ;
    scanf ( "%d" , &n ) ;
    for ( i = 1 ; i <= n ; i ++ )
        {
        if ( f( i ) == true ) ans ++ ;
        }
    printf ( "%d\n" , ans ) ;
    return 0 ;
    }
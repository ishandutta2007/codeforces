#include<iostream>
#include<stdio.h>
#include<string>
using namespace std ;

int n ;
int a[ 100007 ] ;

int f[ 100007 ] ;


char p[ 100007 ];
char s[ 100007 ] ;


int main ( )
    {
    scanf ( "%d" , &n ) ;
    int i , j ;

    for ( i = 0 ; i < n  ; i ++ )
        {
        scanf ( "%d" , &a[ i ] ) ;
        }

    scanf ( "%s" , &p ) ;
    int sw ;
    ///if ( n == 786 ) printf ( "here\n" ) ;
    for ( i = 0 ; i < n ; i ++ )
        {
        s[ i ] = p[ n - i - 1 ] ;
        if ( i >= n / 2 ) continue ;
        sw = a[ i ] ;
        a[ i ] = a[ n - i - 1 ] ;
        a[ n - i - 1 ] = sw ;

        }


    f[ 0 ] = a[ 0 ] ;
    for ( i = 1 ; i < n ; i ++ )
        {
        f[ i ] = f[ i - 1 ] + a[ i ] ;
        }

    int sm = 0 ;
    int ans = 0 ;



    for ( i = 0 ; i < n ; i ++ )
        {
        if ( s[ i ] == '1' )
            {
            if ( ans < f[ n - 1 ] - f[ i ] + sm ) ans = f[ n - 1 ] - f[ i ] + sm ;
            sm = sm + a[ i ] ;
            }
        }
    if ( ans < sm ) ans = sm ;
    printf ( "%d\n" , ans ) ;

    return 0 ;
    }
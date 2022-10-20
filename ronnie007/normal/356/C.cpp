#include<iostream>
#include<stdio.h>
using namespace std ;

int n ;
int a[ 7 ] ;
int ans = 0 ;

int main ( )
    {
    scanf ( "%d" , &n ) ;
    int i ;
    int x ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &x ) ;
        a[ x ] ++ ;
        }
    int t = a[ 1 ] ;
    if ( t > a[ 2 ] ) t = a[ 2 ] ;
    a[ 1 ] -= t ;
    a[ 2 ] -= t ;
    ans += t ;
    a[ 3 ] += t ;
    int k ;
    if ( a[ 1 ] != 0 )
        {
        t = a[ 1 ] / 3 ;
        a[ 1 ] %= 3 ;
        ans += t + t ;
        a[ 3 ] += t ;

        if ( a[ 1 ] != 0 )
            {
            if ( a[ 1 ] == 1 )
                {
                if ( a[ 3 ] >= 1 )
                    {
                    ans ++ ;
                    }
                else if ( a[ 4 ] >= 2 ) ans += 2 ;
                else ans = -1 ;
                }
            else
                {
                if ( a[ 3 ] >= 2 || a[ 4 ] >= 1 ) ans += 2 ;
                else ans = -1 ;
                }
            }
        }


    if ( a[ 2 ] != 0 )
        {
        t = a[ 2 ] / 3 ;
        a[ 2 ] %= 3 ;
        ans += t + t;
        a[ 3 ] += t + t ;

        if ( a[ 2 ] != 0 )
            {
            if ( a[ 2 ] == 1 )
                {
                if ( a[ 4 ] >= 1 )
                    {
                    ans ++ ;
                    }
                else if ( a[ 3 ] >= 2 ) ans += 2 ;
                else ans = -1 ;
                }
            else
                {
                ans += 2 ;
                }
            }
        }
    printf ( "%d\n" , ans ) ;
    return 0 ;
    }
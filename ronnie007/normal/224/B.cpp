#include<iostream>
#include<stdio.h>
using namespace std ;

int n , k ;
int a[ 100007 ] ;
int f[ 100007 ] ;

int main ( )
    {
    scanf ( "%d%d" , &n , &k ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &a[ i ] ) ;
        }
    int l = 0 ;
    int r = 0 ;
    int br = 1 ;
    f[ a[ 0 ] ] = 1 ;
    int bestl = -1 ;
    int bestr = -1 ;

    while ( l < n && r < n )
        {
        if ( br < k )
            {
            r ++ ;
            if ( f[ a[ r ] ] == 0 ) br ++ ;
            f[ a[ r ] ] ++ ;
            }
        else
            {
            if ( bestl == -1 || r - l + 1 < bestr - bestl + 1 )
                {
                bestl = l ;
                bestr = r ;
                }
            if ( f[ a[ l ] ] == 1 ) br -- ;
            f[ a[ l ] ] -- ;
            l ++ ;
            }
        }
    if ( bestl != -1 ) printf ( "%d %d\n" , bestl + 1 , bestr + 1 ) ;
    else printf ( "-1 -1\n" ) ;
    return 0 ;
    }
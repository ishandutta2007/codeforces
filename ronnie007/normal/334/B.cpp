#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std ;

struct point
    {
    int x , y ;
    };

struct point a[ 17 ];


bool f ( struct point p1 , struct point p2 )
    {
    if ( p1.y < p2.y ) return true ;
    if ( p2.y < p1.y ) return false ;
    if ( p1.x < p2.x ) return true ;
    return false ;
    }

int main ( )
    {
    int i ;
    for ( i = 0 ; i < 8 ; i ++ )
        {
        scanf ( "%d%d" , &a[ i ].x , &a[ i ].y ) ;
        }
    sort ( a , a + 8 , f ) ;
    ///horizontal
    if ( a[ 0 ].y != a[ 1 ].y || a[ 1 ].y != a[ 2 ].y )
        {
        printf ( "ugly\n" ) ;
        return 0 ;
        }

    if ( a[ 0 ].x >= a[ 1 ].x || a[ 1 ].x >= a[ 2 ].x )
        {
        printf ( "ugly\n" ) ;
        return 0 ;
        }


    if ( a[ 5 ].y != a[ 6 ].y || a[ 6 ].y != a[ 7 ].y )
        {
        printf ( "ugly\n" ) ;
        return 0 ;
        }

    if ( a[ 5 ].x >= a[ 6 ].x || a[ 6 ].x >= a[ 7 ].x )
        {
        printf ( "ugly\n" ) ;
        return 0 ;
        }

    ///vertical
    if ( a[ 0 ].x != a[ 3 ].x || a[ 3 ].x != a[ 5 ].x )
        {
        printf ( "ugly\n" ) ;
        return 0 ;
        }

    if ( a[ 0 ].y >= a[ 3 ].y || a[ 3 ].y >= a[ 5 ].y )
        {
        printf ( "ugly\n" ) ;
        return 0 ;
        }

    if ( a[ 2 ].x != a[ 4 ].x || a[ 4 ].x != a[ 7 ].x )
        {
        printf ( "ugly\n" ) ;
        return 0 ;
        }

    if ( a[ 2 ].y >= a[ 4 ].y || a[ 4 ].y >= a[ 7 ].y )
        {
        printf ( "ugly\n" ) ;
        return 0 ;
        }

    if ( a[ 3 ].y != a[ 4 ].y || a[ 6 ].x != a[ 1 ].x )
        {
        printf ( "ugly\n" ) ;
        return 0 ;
        }
    printf ( "respectable\n" );
    return 0 ;
    }
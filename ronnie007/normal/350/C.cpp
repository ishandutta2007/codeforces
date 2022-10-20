#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std ;



vector < int > cmd ;
vector < int > tim ;
vector < int > dir ;


struct tuhla
    {
    int x , y ;
    };

struct tuhla a[ 100007 ] ;

bool f ( struct tuhla p1 , struct tuhla p2 )
    {
    if ( abs( p1.x ) + abs( p1.y ) < abs( p2.x ) + abs( p2.y ) )
        {
        return true ;
        }
    return false ;
    }


int main ( )
    {
    int i ;
    int n ;
    scanf ( "%d" , &n ) ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf( "%d%d" , &a[ i ].x , &a[ i ].y ) ;
        }
    sort ( a , a + n , f ) ;

    for ( i = 0 ; i < n ; i ++ )
        {
        if ( a[ i ].x < 0 )
            {
            cmd.push_back ( 1 ) ;
            tim.push_back ( abs( a[ i ].x ) ) ;
            dir.push_back ( 3 ) ;
            }
        if ( a[ i ].x > 0 )
            {
            cmd.push_back ( 1 ) ;
            tim.push_back ( abs( a[ i ].x ) ) ;
            dir.push_back ( 1 ) ;
            }

        if ( a[ i ].y < 0 )
            {
            cmd.push_back ( 1 ) ;
            tim.push_back ( abs( a[ i ].y ) ) ;
            dir.push_back ( 4 ) ;
            }
        if ( a[ i ].y > 0 )
            {
            cmd.push_back ( 1 ) ;
            tim.push_back ( abs( a[ i ].y ) ) ;
            dir.push_back ( 2 ) ;
            }
        cmd.push_back ( 2 ) ;
        tim.push_back( -1 ) ;
        dir.push_back( -1 ) ;

        if ( a[ i ].x < 0 )
            {
            cmd.push_back ( 1 ) ;
            tim.push_back ( abs( a[ i ].x ) ) ;
            dir.push_back ( 1 ) ;
            }
        if ( a[ i ].x > 0 )
            {
            cmd.push_back ( 1 ) ;
            tim.push_back ( abs( a[ i ].x ) ) ;
            dir.push_back ( 3 ) ;
            }

        if ( a[ i ].y < 0 )
            {
            cmd.push_back ( 1 ) ;
            tim.push_back ( abs( a[ i ].y ) ) ;
            dir.push_back ( 2 ) ;
            }
        if ( a[ i ].y > 0 )
            {
            cmd.push_back ( 1 ) ;
            tim.push_back ( abs( a[ i ].y ) ) ;
            dir.push_back ( 4 ) ;
            }
        cmd.push_back ( 3 ) ;
        tim.push_back( -1 ) ;
        dir.push_back( -1 ) ;
        }
    int k = cmd.size ( ) ;
    printf ( "%d\n" , k ) ;
    for ( i = 0 ; i < k ; i ++ )
        {
        printf ( "%d " , cmd[ i ] ) ;
        if ( cmd[ i ] == 1 )
            {
            printf ( "%d " , tim[ i ] ) ;
            if ( dir[ i ] == 1 ) printf ( "R\n" ) ;
            if ( dir[ i ] == 2 ) printf ( "U\n" ) ;
            if ( dir[ i ] == 3 ) printf ( "L\n" ) ;
            if ( dir[ i ] == 4 ) printf ( "D\n" ) ;
            }
        else printf ( "\n" ) ;
        }
    return 0 ;
    }
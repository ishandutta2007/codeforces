#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
using namespace std ;

int n , m ;
int a[ 100007 ] ;

void input ( ) ;
void solve ( ) ;


int main ( )
    {
    input ( ) ;
    solve ( ) ;
    return 0 ;
    }


void input ( )
    {
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    int x , y , z ;
    for ( i = 0 ; i < m ; i ++ )
        {
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        if ( a[ x ] != 0 )
            {
            if ( a[ x ] == 1 )
                {
                a[ y ] = 2 ;
                a[ z ] = 3 ;
                }
            if ( a[ x ] == 2 )
                {
                a[ y ] = 1 ;
                a[ z ] = 3 ;
                }
            if ( a[ x ] == 3 )
                {
                a[ y ] = 1 ;
                a[ z ] = 2 ;
                }
            }
        else if ( a[ y ] != 0 )
            {
            if ( a[ y ] == 1 )
                {
                a[ x ] = 2 ;
                a[ z ] = 3 ;
                }
            if ( a[ y ] == 2 )
                {
                a[ x ] = 1 ;
                a[ z ] = 3 ;
                }
            if ( a[ y ] == 3 )
                {
                a[ x ] = 1 ;
                a[ z ] = 2 ;
                }
            }
        else if ( a[ z ] != 0 )
            {
            if ( a[ z ] == 1 )
                {
                a[ y ] = 2 ;
                a[ x ] = 3 ;
                }
            if ( a[ z ] == 2 )
                {
                a[ y ] = 1 ;
                a[ x ] = 3 ;
                }
            if ( a[ z ] == 3 )
                {
                a[ y ] = 1 ;
                a[ x ] = 2 ;
                }
            }
        else
            {
            a[ x ] = 1 ;
            a[ y ] = 2 ;
            a[ z ] = 3 ;
            }
        }
    }

void solve ( )
    {
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) printf ( "%d " , a[ i ] ) ;
    printf ( "\n" ) ;
    }
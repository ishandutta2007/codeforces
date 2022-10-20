#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;


int n ;
int m ;
int k ;
int a[ 500000 ] ;
int b[ 500000 ] ;


void input();

void add ( int where , int level ) ;





int main()
    {
    input();
    return 0;
    }


void input()
    {
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    int l = 1 ;
    for ( i = 0 ; i < n ; i ++ ) l = l * 2 ;
    n = l ;
    k = n ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &b[ i ] ) ;
        }
    n = n * 2 ;
    for ( i = 0 ; i < k ; i ++ )
        {
        a[ n + i ] = b[ i ] ;
        if( i % 2 == 1 ) add ( n + i , 0 ) ;
        }
    int x , y ;
    for ( i = 0 ; i < m ; i ++ )
        {
        scanf ( "%d%d" , &x , &y ) ;
        a[ n + ( x - 1 ) ] = y ;
        add ( n + ( x - 1 ) , 0 ) ;
        printf ( "%d\n" , a[ 1 ] ) ;
        }
    }


void add( int where , int level )
    {
    if ( level != 0 )
        {
        if ( level % 2 == 1 )
            {
            a[ where ] = ( a[ 2 * where ]|a[ 2 * where + 1 ] ) ;
            }
        else
            {
            a[ where ] = ( a[ 2 * where ]^a[ 2 * where + 1 ] ) ;
            }
        }
    if ( where != 1 ) add ( where / 2 , level + 1 ) ;
    }
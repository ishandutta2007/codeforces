#include<iostream>
#include<stdio.h>
using namespace std ;


int main ( )
    {
    int n , m ;
    int i , j ;
    int x ;
    int fl = 0 ;
    scanf ( "%d%d" , &n , &m ) ;
    for ( i = 0 ; i < n ; i ++ )
        {
        for ( j = 0 ; j < m ; j ++ )
            {
            scanf ( "%d" , &x ) ;
            if ( x == 1 )
                {
                if ( ( i == 0 || j == 0 || i == n - 1 || j == m- 1 ) && fl == 0 )
                    {
                    fl = 1 ;
                    }
                }
            }
        }
    if ( fl == 1 ) {printf ( "2\n" ) ;return 0 ; }
    printf ( "4\n" ) ;
    return 0 ;
    }
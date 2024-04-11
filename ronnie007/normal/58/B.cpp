#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std ;

int n ;
vector < int > v ;

int main ( )
    {
    scanf ( "%d" , &n ) ;
    int i , j ;
    for ( i = n ; i >= 1 ; i -- )
        {
        if ( i == n )
            {
            v.push_back( i ) ;
            printf ( "%d " , i ) ;
            }
        else
            {
            for ( j = 0 ; j < v.size ( ) ; j ++ )
                {
                if ( v[ j ] % i != 0 ) break ;
                }
            if ( j == v.size ( ) )
                {
                v.push_back ( i ) ;
                printf ( "%d " , i ) ;
                }
            }
        }
    printf ( "\n" ) ;
    return 0 ;
    }
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std ;

vector < int > ans ;

int main ( )
    {
    int n , m , k  ;
    int i , j ;
    scanf ( "%d%d%d" , &n , &m , &k ) ;
    if ( k == 1 )
        {
        for ( i = 1 ; i <= n + m ; i += n - 1 ) ans.push_back ( i ) ;
        }
    else
        {
        for ( i = 1 ; i <= k ; i ++ )
            {
            ans.push_back ( 1 ) ;
            }
        for ( i = n ; i <= n + m ; i += n )
            {
            ans.push_back ( i ) ;
            }
        for ( i = n + 1 ; i <= n + m ; i += n )
            {
            for ( j = 1 ; j < k ; j ++  )
                {
                ans.push_back ( i ) ;
                }
            }
        }
    printf ( "%d\n" , ans.size ( ) ) ;
    for ( i = 0 ; i < ans.size ( ) ; i ++ )
        {
        printf ( "%d " , ans[ i ] ) ;
        }
    printf ( "\n" ) ;
    return 0 ;
    }
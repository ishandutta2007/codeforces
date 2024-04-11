#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std ;

int n , k ;
int a[ 300007 ] ;

int main ( )
    {
    scanf ( "%d%d" , &n , &k ) ;
    int i , j ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &a[ i ] ) ;
        }
    sort ( a , a + n ) ;
    int ans = a[ 0 ] ;
    while ( ans > 1 )
        {
        for ( j = 0 ; j < n ; j ++ )
            {
            if ( a[ j ] % ans  > k )
                {
                ans = a[ j ]  / ( a[ j ] / ans + 1 ) ;
                break ;
                }
            }
        if ( j == n ) { break ; }
        }
    printf ( "%d\n" , ans ) ;
    return 0 ;
    }
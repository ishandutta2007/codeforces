#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std ;


vector < int > ans , cur ;

int main ( )
    {
    int n ;
    long long a[ 100007 ] ;
    int i , j ;
    long long  t = 0 ;
    scanf ( "%d" , &n ) ;

    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &a[ i ] ) ;
        }

    for ( i = 31 ; i >= 0 ; i-- )
        {
        t = ( 1 << 31 ) - 1 ;
        cur.clear ( ) ;
        for ( j = 0 ; j < n ; j ++ )
            {
            if ( ( a[ j ]&( 1 << i ) )  )
                {
                cur.push_back ( a[ j ] ) ;
                t =  t & a[ j ]  ;
                }
            }
        if ( ( t % ( 1 << i ) ) == 0 )
            {
            ///printf ( "%d\n" , i ) ;
            ans = cur ;
            break ;
            }
        }

    printf ( "%d\n" , ans.size( ) ) ;


    for ( i = 0 ; i < ans.size ( ) ; i ++ )
        {
        printf ( "%d " , ans[ i ] ) ;
        }
    printf ( "\n" ) ;
    return 0 ;
    }
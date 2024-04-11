#include<iostream>
#include<stdio.h>
#include<string>
using namespace std ;

int n , m ;
string a[ 37 ] ;
int doesexist[ 37 ] ;
int r[ 37 ] ;
int x ;
int q;
string p ;

int main ( )
    {
    int i , j , k , t ;
    int u , u1 ;
    int hasshift = 0 ;
    cin >> n >> m >> x ;
    for ( i = 0 ; i < n ; i ++ )
        {
        cin >> a[ i ] ;
        }
    for ( i = 0 ; i < n ; i ++ )
        {
        for ( j = 0 ; j < m ; j ++ )
            {
            if ( a[ i ][ j ] == 'S' ) hasshift = 1 ;
            }
        }
    for ( i = 0 ; i < n ; i ++ )
        {
        for ( j = 0 ; j < m ; j ++ )
            {
            if ( a[ i ][ j ] != 'S' ) doesexist[ a[ i ][ j ] - 'a' ] = 1 ;
            if ( r[ a[ i ][ j ] - 'a' ] == 1 ) continue ;
            for ( t = 0 ; t < n ; t ++ )
                {
                for ( k = 0 ; k < m ; k ++ )
                    {
                    if ( a[ t ][ k ] == 'S' )
                        {
                        u = i - t ;
                        u1 = j - k ;
                        if ( u * u + u1 * u1 <= x * x )  { r[ a[ i ][ j ] - 'a' ] = 1 ; break ; }
                        else r[ a[ i ][ j ] - 'a' ] = -1 ;
                        }
                    }
                if ( r[ a[ i ][ j ] - 'a' ] == 1 ) break ;
                }
            }
        }

    cin >> q ;
    cin >> p ;
    int ans = 0;
    for ( i = 0 ; i < q ; i ++ )
        {
        if ( ans == -1 ) break ;
        if ( p[ i ] >= 'A' && p[ i ] <= 'Z' )
            {
            if ( r[ p[ i ] - 'A' ] == -1 ) ans ++ ;
            if ( r[ p[ i ] - 'A' ] == 0 || doesexist[ p[ i ] - 'A' ] == 0 ) ans = -1 ;
            }
        else if ( doesexist[ p[ i ] - 'a' ] == 0 ) ans = -1 ;
        }
    printf ( "%d\n" , ans ) ;
    return 0 ;
    }
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std ;

int n , m ;
int used[ 17 ];
int used1[ 17 ];

string a[ 17 ] ;

int main ( )
    {
    cin >> n >> m ;
    int i , j ;
    for ( i = 0 ; i < n ; i ++ )
        {
        cin >> a[ i ] ;
        for ( j = 0 ; j < m ; j ++ )
            {
            if ( a[ i ][ j ] == 'S' ) { used[ i ] = 1 ; used1[ j ] = 1 ; }
            }
        }
    int ans = 0 ;
    for ( i = 0 ; i < n ; i ++ )
        {
        for ( j = 0 ; j < m ; j ++ )
            {
            if ( used[ i ] == 0 || used1[ j ] == 0 ) ans ++ ;
            }
        }
    printf ( "%d\n" , ans ) ;
    return 0 ;
    }
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std ;

int n ;
string a[ 107 ] ;
int deadr[ 107 ] ;
int deadc[ 107 ] ;



int main ( )
    {
    int i , j ;
    cin >> n ;
    for ( i = 0 ; i < n ; i ++ )
        {
        cin >> a[ i ] ;
        for ( j = 0 ; j < n ; j ++ )
            {
            if ( a[ i ][ j ] == '.' )
                {
                deadr[ i ] = 1 ;
                deadc[ j ] = 1 ;
                }
            }
        }
    int fl = 0 ;
    int fl1 = 0 ;
    for ( i = 0 ; i < n ; i ++ )
        {
        if ( deadr[ i ] == 0 ) fl = 1 ;
        if ( deadc[ i ] == 0 ) fl1 = 1 ;
        }
    if ( fl == 1 && fl1 == 1 )
        {
        printf ( "-1\n" ) ;
        return 0 ;
        }
    if( fl == 0 )
        {
        for ( i = 0 ; i < n ; i ++ )
            {
            for ( j = 0 ; j < n ; j ++ )
                {
                if( a[ i ][ j ] == '.' )break;
                }
            cout<< i + 1 <<" "<< j + 1 <<endl;
            }
        return 0;
        }

    if ( fl1 == 0 )
        {
        for ( j = 0 ; j < n ; j ++ )
            {
            for ( i = 0 ; i < n ; i ++ )
                {
                if( a[ i ][ j ] == '.' )break;
                }
            cout<< i + 1 <<" "<< j + 1 <<endl;
            }
        return 0;
        }
    return 0 ;
    }
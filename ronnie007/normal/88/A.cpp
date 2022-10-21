#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std ;



int dist (int x, int y)
    {
    if ( x < y ) return y - x;

    return 11 - x + y + 1;
    }
bool is_major ( int a , int b , int c )
    {
    return dist ( a , b ) == 4 and dist ( b , c ) == 3;
    }
bool is_minor (int a, int b, int c)
    {
    return dist (a, b) == 3 and dist (b, c) == 4;
    }


vector < string > v ;

int main ( )
    {
    string a[ 7 ];
    int b[ 7 ] ;
    cin >> a[ 0 ] >> a[ 1 ] >> a[ 2 ] ;
    string h ;
    h = "C" ;
    v.push_back( h ) ;
    h = "C#" ;
    v.push_back( h ) ;
    h = "D" ;
    v.push_back( h ) ;
    h = "D#" ;
    v.push_back( h ) ;
    h = "E" ;
    v.push_back( h ) ;
    h = "F" ;
    v.push_back( h ) ;
    h = "F#" ;
    v.push_back( h ) ;
    h = "G" ;
    v.push_back( h ) ;
    h = "G#" ;
    v.push_back( h ) ;
    h = "A" ;
    v.push_back( h ) ;
    h = "B" ;
    v.push_back( h ) ;
    h = "H" ;
    v.push_back( h ) ;
    int dist = 0 ;
    int dist1 = 0 ;
    int i , j , k ;
    int n = 12 ;
    for ( i = 0 ; i < 12 ; i ++ )
        {
        if ( v[ i ] == a[ 0 ] ) b[ 0 ] = i ;
        if ( v[ i ] == a[ 1 ] ) b[ 1 ] = i ;
        if ( v[ i ] == a[ 2 ] ) b[ 2 ] = i ;
        }
    for ( i = 0 ; i < 3 ; i ++ )
        {
        for ( j = 0 ; j < 3 ; j ++ )
            {
            if ( i != j )
                {
                for ( k = 0 ; k < 3 ; k ++ )
                    {
                    if ( k != i && k != j )
                        {
                        if (is_major ( b[ i ] , b[ j ], b[ k ] ) )
                            {
                            printf ( "major\n" ) ;
                            return 0;
                            }
                        if (is_minor ( b[ i ] ,  b[ j ] , b[ k ] ) )
                            {
                            printf ("minor\n");
                            return 0;
                            }
                        }
                    }
                }
            }
        }
    printf ("strange\n" ) ;
    return 0 ;
    }
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int rod( string s )
    {
    int len = s.length();
    if( len - 4 >= 0 && s[ len - 1 ] == 's' && s[ len - 2 ] == 'o' && s[ len - 3 ] == 'i' && s[ len - 4 ] == 'l' )return 1;
    if( len - 5 >= 0 && s[ len - 1 ] == 'a' && s[ len - 2 ] == 'l' && s[ len - 3 ] == 'a' && s[ len - 4 ] == 'i' && s[ len - 5 ] == 'l' )return 2;
    if( len - 3 >= 0 && s[ len - 1 ] == 'r' && s[ len - 2 ] == 't' && s[ len - 3 ] == 'e' )return 3;
    if( len - 4 >= 0 && s[ len - 1 ] == 'a' && s[ len - 2 ] == 'r' && s[ len - 3 ] == 't' && s[ len - 4 ] == 'e' )return 4;
    if( len - 6 >= 0 && s[ len - 1 ] == 's' && s[ len - 2 ] == 'i' && s[ len - 3 ] == 't' && s[ len - 4 ] == 'i' && s[ len - 5 ] == 'n' && s[ len - 6 ] == 'i' )return 5;
    if( len - 6 >= 0 && s[ len - 1 ] == 's' && s[ len - 2 ] == 'e' && s[ len - 3 ] == 't' && s[ len - 4 ] == 'i' && s[ len - 5 ] == 'n' && s[ len - 6 ] == 'i' )return 6;
    return 7;
    }

int main()
    {
    string s , mas[ 100001 ];
    int len = 0 , i , d[ 100001 ];
    while( cin >> s )
        {
        mas[ len ] = s;
        len ++;
        }
    if( len == 1 && rod( mas[ 0 ] ) != 7 )
    printf( "YES\n" );
    else
        {
        for( i = 0 ; i < len ; i++ )
            {
            d[ i ] = rod( mas[ i ] );
            if( d[ i ] == 7 )
                {
                printf( "NO\n" );
                return 0;
                }
            }
        for( i = 1 ; i < len ; i++ )
        if( (d[ i ] % 2) != (d[ i - 1 ] % 2) )
            {
            printf( "NO\n" );
            return 0;
            }
        bool pr = false , su = false , gl = false;
        for( i = 0 ; i < len ; i++ )
            {
            if( ( d[ i ] == 1 || d[ i ] == 2 ) && ( su || gl ) )
                {
                printf( "NO\n" );
                return 0;
                }
            if( ( d[ i ] == 4 || d[ i ] == 3 ) && ( su || gl ) )
                {
                printf( "NO\n" );
                return 0;
                }
            if( ( d[ i ] == 6 || d[ i ] == 5 ) && ( su == false ) )
                {
                printf( "NO\n" );
                return 0;
                }
            if( ( d[ i ] == 6 || d[ i ] == 5 ) )
                {
                gl = true;
                }
            if( ( d[ i ] == 1 || d[ i ] == 2 ) )
                {
                pr = true;
                }
            if( ( d[ i ] == 3 || d[ i ] == 4 ) )
                {
                su = true;
                }
            }
            if( su == false )
                {
                printf( "NO\n" );
                return 0;
                }
        printf( "YES\n" );
        }

    return 0;
    }
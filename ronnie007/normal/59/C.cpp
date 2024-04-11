#include<iostream>
#include<stdio.h>
#include<string>
using namespace std ;


int used[ 37 ] ;

int main ( )
    {
    int k ;
    int n ;
    string a ;
    cin >> k ;
    cin >> a ;
    n = a.size ( ) ;
    int i , j ;
    int x ;
    int br = 0 ;
    for ( i = 0 ; i < n / 2 ; i ++ )
        {
        x = n - i - 1 ;

        if ( a[ i ] != '?' )
            {
            if ( a[ x ] != '?' )
                {
                if ( a[ x ] != a[ i ] )
                    {
                    printf ( "IMPOSSIBLE\n" ) ;
                    return 0 ;
                    }
                }
            else a[ x ] = a[ i ] ;
            }

        if ( a[ x ] != '?' )
            {
            if ( a[ i ] != '?' )
                {
                if ( a[ i ] != a[ i ] )
                    {
                    printf ( "IMPOSSIBLE\n" ) ;
                    return 0 ;
                    }
                }
            else a[ i ] = a[ x ] ;
            }
        if ( a[ i ] == '?' && a[ x ] == '?' ) br ++ ;
        else used[ a[ i ] - 'a' ] = 1 ;
        }
    if ( n % 2 == 1 )
        {
        if ( a[ n / 2 ] == '?' ) br ++ ;
        else used[ a[ n / 2 ] - 'a' ] = 1 ;
        }
    int num = 0 ;
    for ( i = 0 ; i < k ; i ++ )
        {
        if ( used[ i ] == 0 ) num ++ ;
        }
    if ( br < num )
        {
        printf ( "IMPOSSIBLE\n" ) ;
        return 0 ;
        }
    int letter = 0 ;
    for ( i = 0 ; i < n / 2 ; i ++ )
        {
        if ( br == num ) break ;
        x = n - i - 1 ;
        if ( a[ i ] == a[ x ] && a[ i ] == '?' )
            {
            a[ i ] = 'a' ;
            a[ x ] = 'a' ;
            br -- ;
            }
        }
    if ( n % 2 == 1 && br > num )
        {
        a[ n / 2 ] = 'a' ;
        }
    for ( i = 0 ; i < k ; i ++ ) if ( used[ i ] == 0 ) break ;
    letter = i ;
    for ( i = 0 ; i < n / 2 ; i ++ )
        {
        x = n - i - 1 ;
        if ( a[ i ] == a[ x ] && a[ i ] == '?' )
            {
            a[ i ] = ( letter + 'a' ) ;
            a[ x ] = ( letter + 'a' ) ;
            for ( j = letter + 1 ; j < k ; j ++ ) if ( used[ j ] == 0 ) break ;
            letter = j ;
            }
        }
    if ( n % 2 == 1 && a[ n / 2 ] == '?' ) a[ n / 2 ] = ( letter + 'a' ) ;
    cout << a << "\n" ;
    return 0 ;
    }
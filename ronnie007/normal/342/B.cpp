#include<iostream>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

int n , m , s , f ;
int a[ 100007 ] ;
int l[ 100007 ] ;
int r[ 100007 ] ;


void input ( ) ;
void solve ( ) ;

int main ( )
    {
    input ( ) ;
    solve ( ) ;
    return 0 ;
    }


void input ( )
    {
    scanf  ( "%d%d%d%d" , &n , &m , &s , &f ) ;
    int i ;
    for ( i = 0 ; i < m ; i ++ )
        {
        scanf ( "%d%d%d" , &a[ i ] , &l[ i ] , &r[ i ] ) ;
        }
    }

void solve ( )
    {
    int i ;
    int k = 0 ;
    int pl = s ;
    for ( i = 1 ; ; i ++ )
        {
        if ( pl == f ) break ;
        if ( i == a[ k ] )
            {
            if ( pl >= l[ k ] && pl <= r[ k ] ) printf ( "X" ) ;
            else
                {
                if ( f < pl )
                    {
                    if ( r[ k ] != pl - 1 ) { printf ( "L" ) ; pl -- ; }
                    else printf ( "X" ) ;
                    }
                else
                    {
                    if ( l[ k ] != pl + 1 ) { printf ( "R" ) ; pl ++ ; }
                    else printf ( "X" ) ;
                    }
                }
            k ++ ;
            }
        else
            {
            if ( f < pl )
                {
                printf ( "L" ) ;
                pl -- ;
                }
            else
                {
                printf ( "R" ) ;
                pl ++ ;
                }
            }
        }
    printf ( "\n" ) ;
    }
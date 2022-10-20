#include<iostream>
#include<stdio.h>
using namespace std ;

int n ;
long long  a[ 100007 ] ;

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
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%I64d" , &a[ i ] ) ;
        }
    }
void solve ( )
    {
    int i , j ;
    i = 0 ;
    int ans = 2 ;
    if ( n == 1 ) ans = 1 ;
    int br = 2 ;
    for ( i = 2 ; i < n ; i ++ )
        {
        if ( a[ i ] == a[ i - 1 ] + a[ i - 2 ] ) br ++ ;
        else
            {
            if ( ans < br ) ans = br ;
            br = 2 ;
            }
        }
    if ( ans < br ) ans = br ;
    if ( n == 1 ) ans = 1 ;
    if ( n == 2 ) ans = 2 ;
    printf ( "%d\n" , ans ) ;
    }
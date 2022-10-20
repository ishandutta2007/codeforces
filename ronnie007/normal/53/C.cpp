#include<iostream>
#include<stdio.h>
using namespace std ;

int n ;
int ans[ 10007 ] ;

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
    }
void solve ( )
    {
    int i ;
    ans[ 1 ] = 1 ;
    ans[ 2 ] = n ;
    for ( i = 3 ; i <= n ; i ++ )
        {
        ans[ i ] = ans[ i - 2 ] ;
        if ( i % 2 == 1 ) ans[ i ] ++ ;
        else ans[ i ] -- ;
        }
    for ( i = 1 ; i <= n ; i ++ )
        {
        printf ( "%d " , ans[ i ] ) ;
        }
    printf ( "\n" ) ;
    }
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std ;


int s ( long long  x )
    {
    int ans = 0 ;
    while ( x != 0 )
        {
        ans += ( x % 10 ) ;
        x = x / 10 ;
        }
    return ans ;
    }

int main ( )
    {
    long long n ;
    scanf ( "%I64d" , &n ) ;
    int p = sqrt( n ) ;
    int i ;
    for ( i = p ; i >= p - 1000000 ; i -- )
        {
        if ( i == 0 ) break ;
        long long x = i ;
        if ( x * x + s( x ) * x == n )
            {
            printf ( "%d\n" , i ) ;
            return 0 ;
            }
        }
    printf ( "-1\n" ) ;
    return 0 ;
    }
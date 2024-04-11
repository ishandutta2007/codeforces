#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std ;

int main ( )
    {
    long long a , b ;
    scanf ( "%I64d%I64d", &a , &b ) ;
    long long t = ( a * b ) / __gcd( a , b ) ;

    long long d = t / a - 1;
    long long m = t / b - 1;

    if (a > b)
        {
        d++;
        }
    else if (b > a)
        {
        m++;
        }
   // printf ("%d %d\n", to_dasha, to_masha);

    if ( m < d ) printf ( "Dasha\n" );
    if ( m > d ) printf ( "Masha\n" );
    if ( m == d ) printf ( "Equal\n" );
    return 0 ;
    }
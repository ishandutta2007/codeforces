#include<iostream>
#include<stdio.h>
using namespace std ;

int main ( )
    {
    long long q ;
    scanf ( "%I64d" , &q ) ;
    long long i ;
    long long j ;
    long long ans = 1 ;
    long long br = 0 ;
    long long divisors = 0 ;
    for ( i = 2 ; i * i <= q ; i ++ )
        {
        while ( q % i == 0 )
            {
            q = q / i ;
            divisors ++ ;
            if ( br < 2 ) { br ++ ; ans = ans * i ; }
            }
        }
    if ( q > 1 )
        {
        if ( divisors > 0 )
        divisors ++;
        }

    if ( divisors < 2 )
        {
        printf("1\n0\n");
        return 0;
        }
    else if ( divisors == 2 )
        {
        printf ( "2\n" ) ;
        return 0;
        }
    else
        {
        printf ( "1\n%I64d\n" , ans ) ;
        return 0;
        }
    return 0 ;
    }
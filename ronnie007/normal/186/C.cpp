#include<iostream>
#include<stdio.h>
using namespace std ;

#define MOD 1000000007

long long fastmul ( long long t )
    {
    long long ans = 1 ;
    long long p = 2 ;
    while ( t != 0 )
        {
        if ( t % 2 == 0 )
            {
            p = ( p * p ) % MOD ;
            ///p = p % MOD ;
            t = t / 2 ;
            }
        else
            {
            ans = ans * p ;
            ans = ans % MOD ;
            t -- ;
            }
        }
    ///ans = ans * p ;
    return ans ;
    }

int main ( )
    {
    long long n ;
    scanf ( "%I64d" , &n ) ;
    if ( n == 0 ) printf ( "1\n" ) ;
    if ( n == 1 ) printf ( "3\n" ) ;
    if ( n == 2 ) printf ( "10\n" ) ;
    if ( n <= 2 ) return 0 ;
    printf ( "%I64d\n" , ( fastmul ( 2 * n - 1 ) + fastmul( n - 1 ) ) % MOD  ) ;
    return 0 ;
    }
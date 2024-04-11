#include<iostream>
#include<stdio.h>
using namespace std ;

#define MOD 1000000007

int main ( )
    {
    long long n , m , k ;
    scanf ( "%I64d%I64d%I64d" , &n , &m , &k ) ;
    long long ans = 1 ;
    int i ;
    if ( k == 1 || k > n )
        {
        for ( i = 0 ; i < n ; i ++ ) { ans = ( ans * m ) % MOD ; }
        }
    else if ( k == n )
        {
        for ( i = 0 ; i < ( n + 1 ) / 2 ; i ++ ) { ans = ( ans * m ) % MOD ; }
        }
    else if ( k % 2 == 1 ) ans = ( m * m ) % MOD ;
    else ans = m ;
    printf ( "%I64d\n" , ans ) ;
    return 0 ;
    }
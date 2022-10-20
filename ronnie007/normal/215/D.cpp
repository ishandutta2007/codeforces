#include<iostream>
#include<stdio.h>
using namespace std ;

int n , m ;
long long  t , T , x , y ;
long long ans ;


int main ( )
    {
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    long long best = 0 ;
    long long best1 = 0 ;
    int plc ;
    int d ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%I64d%I64d%I64d%I64d" , &t , &T , &x , &y ) ;
        if ( T <= t )
            {
            ans = ans + y + m * x ;
            continue ;
            }
        if ( t + m < t ) best = y ;
        else best = y + m * x ;
        plc = T - t ;
        best1 = m / plc ;
        if ( m % plc ) best1 ++ ;
        best1 = best1 * y ;
        if ( best > best1 ) ans = ans + best1 ;
        else ans = ans + best ;
        }
    printf ( "%I64d\n" , ans ) ;
    return 0 ;
    }
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std ;


int n , k ;
int a[ 107 ] ;
int ans1[ 107 ] ;
int ans2[ 107 ] ;

int main ( )
    {
    int i ;
    int ret = 0 ;
    scanf ( "%d%d" , &n , &k ) ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &a[ i ] ) ;
        if ( a[ i ] == 1 ) ans1[ i % k ] ++ ;
        else ans2[ i % k ] ++ ;
        }
    for ( i = 0 ; i < k ; i ++ )
        {
        ret += min ( ans1[ i ] , ans2[ i ] ) ;
        }
    printf ( "%d\n" , ret ) ;
    return 0 ;
    }
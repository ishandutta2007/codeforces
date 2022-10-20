#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std ;


int main ( )
    {
    int a[ 7 ] , br ;
    scanf ( "%d%d%d%d" , &a[ 0 ] , &a[ 1 ] , &a[ 2 ] , &br ) ;
    sort ( a , a + 3 ) ;
    long long p1 , p2 , p3 ;
    p1 = min ( br / 3 , a[ 0 ] - 1 ) ;
    br -= p1 ;
    p2 = min ( br / 2 , a[ 1 ] - 1 ) ;
    br -= p2 ;
    p3 = min ( br  , a[ 2 ] - 1 ) ;
    printf ( "%I64d\n" , ( p1 + 1 ) * ( p2 + 1 ) * ( p3 + 1 ) ) ;
    return 0 ;
    }
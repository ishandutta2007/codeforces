#include<iostream>
#include<stdio.h>
#include<string>
using namespace std ;

long long n , m ;

int gcd ( int x , int y )
    {
    if( y == 0 ) return x ;
    return gcd ( y , x % y ) ;
    }

int c[ 1000007 ][ 28 ] ;


int main ( )
    {
    string x , y ;
    cin >> n >> m ;
    cin >> x >> y ;
    long long ret = 0 ;
    long long k = gcd ( x.size ( ) , y.size ( ) ) ;
    long long times = ( x.size ( ) * n ) / ( x.size ( ) / k * y.size ( ) ) ;
    int i ;
    for ( i = 0 ; i < y.size ( ) ; i ++ )
        {
        c[ i % k ][ y[ i ] - 'a' ] ++ ;
        }
    ret = x.size ( ) / k * y.size ( ) ;
    for ( i = 0 ; i < x.size ( ) ; i ++ )
        {
        ret -= c[ i % k ][ x[ i ] - 'a' ] ;
        }
    ///printf ( "%I64d\n" , ret ) ;
    printf ( "%I64d\n" , times * ret ) ;
    return 0 ;
    }
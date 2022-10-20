#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std ;


#define MOD 1000000007

typedef vector < vector < long long > > V;

int n ;
V a ;


V mul ( V p1 , V p2 )
    {
    int i , j , t ;
    V ans ;
    vector < long long >  zero ;
    for ( i = 0 ; i < 4 ; i ++ )
        {
        zero.push_back ( 0 ) ;
        }
    for ( i = 0 ; i < 4 ; i ++ )
        {
        ans.push_back ( zero ) ;
        }
    long long p = 0 ;
    for ( i = 0 ; i < 4 ; i ++ )
        {
        for ( j = 0 ; j < 4 ; j ++ )
            {
            p = 0 ;
            for ( t = 0 ; t < 4 ; t ++ )
                {
                p += p1[ i ][ t ] * p2[ t ][ j ] ;
                p = p % MOD ;
                }
            ans[ i ][ j ] = p ;
            }
        }
    return ans ;
    }

V fastmul ( )
    {
    V r ;
    vector < long long >  zero ;
    int i ;
    for ( i = 0 ; i < 4 ; i ++ )
        {
        zero.push_back ( 0 ) ;
        }
    for ( i = 0 ; i < 4 ; i ++ )
        {
        r.push_back ( zero ) ;
        r[ i ][ i ] = 1 ;
        }
    while ( n != 0 )
        {
        if ( n % 2 == 0 )
            {
            n /= 2 ;
            a = mul ( a , a ) ;
            }
        else
            {
            n -- ;
            r = mul ( r , a ) ;
            }
        }
    return r ;
    }




void input ( )
    {
    scanf ( "%d" , &n ) ;
    }

void solve ( )
    {
    vector < long long >  zero ;
    int i ;
    for ( i = 0 ; i < 4 ; i ++ )
        {
        zero.push_back ( 1 ) ;
        }
    for ( i = 0 ; i < 4 ; i ++ ) a.push_back ( zero ) ;
    for ( i = 0 ; i < 4 ; i ++ ) a[ i ][ i ] = 0 ;
    a = fastmul ( ) ;
    printf ( "%I64d\n" , a[ 3 ][ 3 ] ) ;
    }



int main ( )
    {
    input ( ) ;
    solve ( ) ;
    return 0 ;
    }
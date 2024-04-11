#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;

#define MAX(x,y) (((x)>(y))?(x):(y))


long long l , r ;
long long p[ 67 ] ;


void input ( ) ;
void solve ( ) ;

int main()
    {
    input ( ) ;
    solve ( ) ;
    return 0 ;
    }


void input ( )
    {
    scanf ( "%I64d%I64d" , &l , &r ) ;
    }

void solve ( )
    {
    p[ 0 ] = 1 ;
    int i ;
    for ( i = 1 ; i <= 62 ; i ++ )
        {
        p[ i ] = p[ i - 1 ] * 2 ;
        }
    if ( l == r )
        {
        printf ( "0" ) ;
        return  ;
        }
    long long t = ( l ^ ( l + 1 ) ) ;
    ///cout << t << "\n" ;
    for ( i = 0 ; i <= 62 ; i ++ )
        {
        while ( ( l&( p[ i ] ) ) != 0 )
            {
            l -= p[ i ] ;
            i ++ ;
            }
        l += p[ i ] ;
        if ( l <= r ) t = MAX ( t , ( l^( l - 1 ) ) ) ;
        l -= p[ i ] ;
        }

    printf ( "%I64d\n" , t ) ;
    }
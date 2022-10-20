#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

#define MOD 1000000007


long long n ;

long long br[ 17 ] ;
long long  numwith[ 17 ] ;
int num[ 17 ] ;

long long small[ 17 ] ;
long long big[ 17 ] ;


int get ( long long x )
    {
    int ret = 0 ;
    while ( x != 0 )
        {
        if ( x % 10 == 4 || x % 10 == 7 ) ret ++ ;
        x = x / 10 ;
        }
    return ret ;
    }

long long choose ( long long x , long long y )
    {
    long long i ;
    long long ret = 1 ;
    for ( i = x ; i > x - y ; i -- ) ret = ( ret * i ) % MOD ;
    return ret ;
    }

int main ( )
    {
    scanf ( "%I64d" , &n ) ;
    int i , j ;
    int x ;
    for ( i = 0 ; i < 10000 ; i ++ )
        {
        if ( i > n ) break ;
        x = get ( i ) ;
        small[ x ] ++ ;
        }
    long long p = n / 10000 ;
    for ( i = 0 ; i < p ; i ++ )
        {
        x = get ( i ) ;
        for ( j = 0 ; j < 5 ; j ++ )
            {
            big[ x + j ] += small[ j ] ;
            }
        }

    for ( i = p * 10000 ; i <= n ; i ++ )
        {
        big [ get( i ) ] ++ ;
        }
    /**
    for ( i = 0 ; i < 10 ; i ++ )
        {
        printf ( "%I64d\n" , big[ i ] ) ;
        }
    **/
    big[ 0 ] -- ;
    int a , b , c , d , e , f , g ;
    long long ans = 0;
    long long subans ;
    for ( a = 0 ; a < 10 ; a ++ )
        {
        for ( b = 0 ; b < 10 ; b ++ )
            {
            for ( c = 0 ; c < 10 ; c ++ )
                {
                for ( d = 0 ; d < 10 ; d ++ )
                    {
                    for ( e = 0 ; e < 10 ; e ++ )
                        {
                        for ( f = 0 ; f < 10 ; f ++ )
                            {
                            for ( g = 0 ; g < 10 ; g ++ )
                                {
                                if ( a <= b + c + d + e + f + g ) continue ;
                                for ( i = 0 ; i < 10 ; i ++ ) numwith[ i ] = 0 ;
                                numwith[ a ] ++ ;
                                numwith[ b ] ++ ;
                                numwith[ c ] ++ ;
                                numwith[ d ] ++ ;
                                numwith[ e ] ++ ;
                                numwith[ f ] ++ ;
                                numwith[ g ] ++ ;
                                subans = 1 ;
                                for ( int q = 0 ; q < 10 ; q ++ )
                                    {
                                    subans = ( subans * choose ( big[ q ] ,numwith [ q ] ) )  % MOD;
                                    }
                                ans = ( ans + subans ) % MOD;
                                ///cout << ans << "\n" ;
                                }
                            }
                        }
                    }
                }
            }
        }
    printf ( "%I64d\n" , ans ) ;
    return 0 ;
    }
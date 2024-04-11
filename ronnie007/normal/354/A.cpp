#include<iostream>
#include<stdio.h>
using namespace std ;

int n ;
int a[ 100007 ] ;
int prefix[ 100007 ] ;
int l , r ;
int ql , qr ;


int main ( )
    {
    scanf ( "%d%d%d%d%d" , &n  ,&l , &r , &ql , &qr ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ )
        {
        scanf ( "%d" , &a[ i ] ) ;
        }
    prefix[ 0 ] = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) prefix[ i ] = prefix[ i - 1 ] + a[ i ] ;
    int L , R ;
    int ans = -1 ;
    int cur ;
    for ( i = 0 ; i <= n ; i ++ )
        {
        L = i ;
        R = n - i ;
        cur = prefix[ L ] * l ;
        cur += ( prefix[ n ] - prefix[ n - R ] ) * r ;
        if ( L != R )
            {
            if ( L > R )
                {
                cur = cur + ( L - R - 1 ) * ql ;
                }
            else
                {
                cur = cur + ( R - L - 1 ) * qr ;
                }
            }
        if ( ans == -1 || cur < ans ) ans = cur ;
        }
    printf ( "%d\n" , ans ) ;
    return 0 ;
    }
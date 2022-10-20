#include<iostream>
#include<stdio.h>
using namespace std ;

int n ;
int s1 = 0 ;
int s2 = 0 ;

int main ( )
    {
    int a , b , i ;
    bool f = false ;
    scanf ( "%d" , &n ) ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d%d" , &a , &b ) ;
        s1 = s1 + a ;
        s2 = s2 + b ;
        if ( a % 2 != b % 2 ) f = true ;
        }
    if ( s1 % 2 == 0 && s2 % 2 == 0 )
        {
        printf ( "0\n" ) ;
        }
    else if ( s1 % 2 == 1 && s2 % 2 == 1 )
        {
        if ( f == true ) printf ( "1\n" ) ;
        else printf ( "-1\n" ) ;
        }
    else printf ( "-1\n" ) ;
    return 0 ;
    }
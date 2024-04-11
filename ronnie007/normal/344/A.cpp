#include<iostream>
#include<stdio.h>
#include<string>
using namespace std ;


int main ( )
    {
    string a ;
    string b ;
    int i ;
    int n ;
    cin >> n ;
    cin >> a ;
    int ans = 1 ;
    for ( i = 1 ; i < n ; i ++ )
        {
        cin >> b ;
        if ( b[ 0 ] == a[ 1 ] ) ans ++ ;
        a = b ;
        }
    printf ( "%d\n" , ans ) ;
    return 0 ;
    }
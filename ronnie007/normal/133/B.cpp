#include<iostream>
#include<stdio.h>
#include<string>
using namespace std ;


#define MOD 1000003

int main ( )
    {
    string a ;
    string x ;
    int ans = 0 ;
    int i , j ;
    cin >> a ;
    int n = a.size ( ) ;
    x.clear ( ) ;
    for ( i = 0 ; i < n ; i ++ )
        {
        if ( a[ i ] == '>' ) x += "1000" ;
        if ( a[ i ] == '<' ) x += "1001" ;
        if ( a[ i ] == '+' ) x += "1010" ;
        if ( a[ i ] == '-' ) x += "1011" ;
        if ( a[ i ] == '.' ) x += "1100" ;
        if ( a[ i ] == ',' ) x += "1101" ;
        if ( a[ i ] == '[' ) x += "1110" ;
        if ( a[ i ] == ']' ) x += "1111" ;
        }
    int br = 0 ;
    int p = 1 ;
    n = x.size ( ) ;
    for ( i = n - 1 ; i >= 0 ; i -- )
        {
        if ( x[ i ] == '1' )
            {
            p = 1 ;
            for ( j = 0 ; j < br ; j ++ )
                {
                p = p * 2 ;
                p = p % MOD ;
                }
            ans = ( ans + p ) % MOD ;
            }
        br ++ ;
        }
    printf ( "%d\n" , ans ) ;
    return 0 ;
    }
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std ;

int main ( )
    {
    int n ;
    int ans = 0 ;
    int i ;
    string a ;
    cin >> n ;
    for ( i = 0 ; i < n ; i ++ )
        {
        cin >> a ;
        if ( a[ 0 ] >= '0' && a[ 0 ] <= '9' )
            {
            if ( a.size ( ) < 2 || ( a[ 0 ] == '1' && a[ 1 ] < '8' && a.size ( ) == 2 ) ) ans ++ ;
            }
        else
            {
            if ( a == "ABSINTH" || a == "BEER" || a == "BRANDY" || a == "CHAMPAGNE" || a == "GIN" || a == "RUM" || a == "SAKE" || a == "TEQUILA" || a == "VODKA" || a == "WHISKEY" || a == "WINE" ) ans ++ ;
            }
        }
    printf ( "%d\n" , ans ) ;
    return 0 ;
    }
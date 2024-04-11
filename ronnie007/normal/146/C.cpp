#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main ( )
    {
    string a;
    string b;
    int ans = 0 ;
    int inq4 = 0;
    int inq7 = 0;
    int i;
    cin >> a >> b;
    int n = a.size( ) ;
    for ( i = 0 ; i < n ; i ++ )
        {
        if ( a[ i ] != b[ i ] )
            {
            if ( a[ i ] == '4')
                {
                if ( inq7 != 0 ) { inq7 -- ; ans ++ ; }
                else inq4 ++ ;
                }
            if ( a[ i ] == '7')
                {
                if ( inq4 != 0 ) { inq4 -- ; ans ++ ; }
                else inq7 ++ ;
                }
            }
        ///printf ( "%d\n", ans );
        }
    printf ( "%d\n" , inq4 + inq7 + ans );
    return 0;
    }
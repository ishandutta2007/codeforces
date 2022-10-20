#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
using namespace std ;

int n ;

void input ( ) ;

int main ( )
    {
    input ( ) ;
    return 0 ;
    }


void input ( )
    {
    int i ;
    scanf ( "%d" , &n ) ;
    int br25 = 0 ;
    int br50 = 0 ;
    int fl = 0 ;
    int x ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &x ) ;
        if ( x == 25 ) br25 ++ ;
        if ( x == 50 )
            {
            if ( br25 == 0 ) fl = 1 ;
            br50 ++ ;
            br25 -- ;
            }
        if ( x == 100 )
            {
            if ( br25 == 0 || br50 * 50 + br25 * 25 < 75 ) fl = 1 ;
            if ( br50 > 0 ) br50 -- ;
            else br25 -= 2 ;
            br25 -- ;
            }
        }
    if ( fl == 0 ) printf ( "YES\n" ) ;
    else printf ( "NO\n" ) ;
    }
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
int x , y ;
int a[ 107 ] ;
int pr[ 107 ] ;

void input ( ) ;
void solve ( ) ;

int main ( )
    {
    input ( ) ;
    solve ( ) ;
    return 0 ;
    }


void input ( )
    {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &a[ i ] ) ;
        }
    scanf ( "%d%d" , &x , &y ) ;
    }


void solve ( )
    {
    int i ;
    pr[ 0 ] = a[ 0 ] ;
    for ( i = 1 ; i < n ; i ++ ) pr[ i ] = a[ i ] + pr[ i - 1 ] ;

    for ( i = 0 ; i < n - 1 ; i ++ )
        {
        if ( pr[ i ] >= x && pr[ i ] <= y )
            {
            int u = pr[ n - 1 ] - pr[ i ] ;
            if ( u >= x && u <= y )
                {
                printf ( "%d\n" ,  i + 2 ) ;
                return ;
                }
            }
        }
    printf ( "0\n" ) ;
    }
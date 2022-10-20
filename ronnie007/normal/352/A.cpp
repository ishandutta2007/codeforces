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
int br5 ;
int br0 ;

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
    int x ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &x ) ;
        if ( x == 5 ) br5 ++ ;
        else br0 ++ ;
        }
    }


void solve ( )
    {
    int p = br5 / 9 ;
    if ( p == 0 || br0 == 0 )
        {
        if ( br0 != 0 ) printf ( "0\n" ) ;
        else printf ( "-1\n" ) ;
        return  ;
        }
    else
        {
        int i ;
        for ( i = 0 ; i < p * 9 ; i ++ ) printf ( "5" ) ;
        for ( i = 0 ; i < br0 ; i ++ ) printf ( "0" ) ;
        printf ( "\n" ) ;
        }
    }
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


string a;
int n ;

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
    cin >> a ;
    n = a.size ( ) ;
    }

void solve ( )
    {
    int i ;
    stack < int > s ;
    while ( s.empty ( ) == false ) s.pop ( ) ;
    if ( a[ 0 ] == '+' ) s.push( 1 ) ;
    else s.push ( 0 ) ;
    int y ;
    for ( i = 1 ; i < n ; i ++ )
        {
        if ( a[ i ] == '+' ) y = 1 ;
        else y = 0 ;
        if ( s.size ( ) == 0 ) s.push( y ) ;
        else if ( y == s.top ( )  )
            {
            s.pop ( ) ;
            }
        else s.push( y ) ;
        }
    if ( s.size ( ) == 0 ) printf ( "Yes\n" ) ;
    else printf ( "No\n" ) ;

    /**
    string b ;
    b.resize ( n ) ;
    if ( n == 1 )
        {
        printf ( "No\n" ) ;
        return  ;
        }
    b[ 0 ] = a[ 0 ] ;
    for ( i = 1 ; i < n ; i ++ )
        {
        b[ i ] = a[ i ] ;
        if ( a[ i ] == a[ i - 1 ] && a[ i ] == '+' )
            {
            b[ i ] = '-' ;
            b[ i - 1 ] = '-' ;
            }
        }
    for ( i = 0 ; i < n ; i ++ )
        {
        if ( b[ i ] == '+' ) break ;
        }
    if ( i == n )
        {
        printf ( "Yes\n" ) ;
        return ;
        }
///
    b[ 0 ] = a[ 0 ] ;
    for ( i = 1 ; i < n ; i ++ )
        {
        if ( a[ i ] == a[ i - 1 ] && a[ i ] == '-' )
            {
            b[ i ] = '+' ;
            b[ i - 1 ] = '+' ;
            }
        }
    for ( i = 0 ; i < n ; i ++ )
        {
        if ( b[ i ] == '-' ) break ;
        }
    if ( i == n )
        {
        printf ( "Yes\n" ) ;
        return ;
        }
    printf ( "No\n" ) ;
    **/

    }
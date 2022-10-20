#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;


string a ;
string b ; 


void input ( ) ;
void solve ( ) ;
void print ( int x )
    {
    int i ;
    for ( i = 0 ; i < a.size ( ) ; i ++ ) 
        {
        if ( a[ i ] != '|' ) cout << a[ i ] ;
        else break ;
        } 
    for ( i = 0 ; i < x ; i ++ ) cout << b[ i ] ;
    cout << '|' ;
    for ( i = a.size ( ) - 1 ; i >= 0 ; i -- )
        {
        if ( a[ i ] == '|' ) break ;
        else cout << a[ i ] ;
        }
    for ( i = x ; i < b.size ( ) ; i ++ ) cout << b[ i ] ;
    cout << "\n" ;
    }

int main ( ) 
    {
    input ( ) ;
    solve ( ) ;
    return 0 ;
    }


void input ( ) 
    {
    cin >> a >> b ;
    }

void solve ( ) 
    {
    int i ;
    int br1 = 0 , br2 = 0 ;
    int br3 = 0 ;
    int n = a.size ( ) ;
    int fl = 0 ; 
    for ( i = 0 ; i < n ; i ++ ) 
        {
        if ( a[ i ] == '|' ) { fl = 1 ; continue ; }
        if ( fl == 0 ) br1 ++ ;
        else br2 ++ ;
        }
    br3 = b.size ( ) ;
    if ( ( br1 + br2 + br3 ) % 2 == 0 )
        {
        for ( i = 0 ; i <= br3 ; i ++ )
            {
            if ( br1 + i == br2 + ( br3 - i ) ) 
                {
                print ( i ) ;
                return ;
                }
            }
        }
    printf ( "Impossible\n" ) ;
    }
#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
using namespace std ;

char a[ 5007 ] ;
char b[ 5007 ] ; 


map < char , int > m ;

void input ( ) ;
void solve ( ) ;

int main ( )  {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( )  {
    gets ( a ) ;
    gets ( b ) ;
}

void solve ( )  {
    int n ;
    int i ;
    n = strlen ( a ) ;
    for ( i = 0 ; i < n ; i ++ ) {
        if ( a[ i ] != ' ' ) {
            m[ a[ i ] ] ++ ;
        }
    }
    n = strlen ( b ) ;
    for ( i = 0 ; i < n ; i ++ ) {
        if ( b[ i ] != ' ' ) {
            m[ b[ i ] ] -- ;
            if ( m[ b[ i ] ] < 0 ) {
                printf ( "NO\n" ) ;
                return ;
            }
        }
    }
    printf ( "YES\n" ) ;
    return ;
}
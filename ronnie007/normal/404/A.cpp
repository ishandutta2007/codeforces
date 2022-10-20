#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

int n ;

string a[ 307 ] ; 

void input ( ) ;
void solve ( ) ;


int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( )  {
    cin >> n ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        cin >> a[ i ] ; 
    }
}

void solve ( )  {
    int i , j ;
    int p = a[ 0 ][ 0 ] - 'a' ;
    int t = a[ 0 ][ 1 ] - 'a' ;
    for ( i = 0 ; i < n ; i ++ ) {
        for ( j = 0 ; j < n ; j ++ ) {
            if ( i == j || i + j + 1 == n ) {
                if ( a[ i ][ j ] - 'a' != p ) {
                    printf ( "NO\n" ) ;
                    return ;
                }
            }
            else {
                if ( a[ i ][ j ] - 'a' != t ) {
                    printf ( "NO\n" ) ;
                    return ;
                }
            }
        }
    }
    if ( p == t ) {
        printf ( "NO\n" ) ;
        return ;
    }
    printf ( "YES\n" ) ;
}
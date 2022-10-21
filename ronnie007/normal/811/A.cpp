#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

int a , b ;

void input ( ) {
    scanf ( "%d%d" , &a , &b ) ;
}

void solve ( ) {
    int x = 1 ;
    int fl = 0 ;
    while ( 1 ) {
        if ( fl == 0 ) { a -= x ; }
        else { b -= x ; }
        fl ^= 1 ;
        x ++ ;
        if ( a < 0 ) {
            printf ( "Vladik\n" ) ;
            return ;
        }
        if ( b < 0 ) {
            printf ( "Valera\n" ) ;
            return ;
        }
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
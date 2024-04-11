#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

int t , n , p ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    input ( ) ;
    return 0 ;
}


void input ( )  {
    scanf ( "%d" , &t ) ;
    while ( t != 0 ) {
        solve ( ) ;
        t -- ;
    }
}

void solve ( )  {
    scanf ( "%d%d" , &n , &p ) ;
    int i , j ;
    int x = 2 * n + p ;
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = i + 1 ; j <= n ; j ++ ) {
            if ( x == 0 ) break ;
            printf ( "%d %d\n" , i , j ) ;
            x -- ;
        }
        if ( x == 0 ) break ;
    }
}
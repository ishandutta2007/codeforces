#include<iostream>
#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std ;

#define MAXN 107

int n ;
int a[ MAXN ] ;
int mx = 0 ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        mx = max ( mx , a[ i ] ) ;
    }
}

void solve ( ) {
    int i , j ;
    for ( i = mx ; i <= mx + 1000 ; i ++ ) {
        int x , y ;
        x = y = 0 ;
        for ( j = 1 ; j <= n ; j ++ ) {
            x += a[ j ] ;
            y += ( i - a[ j ] ) ;
        }
        if ( y > x ) { printf ( "%d\n" , i ) ; return ; }
    }
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
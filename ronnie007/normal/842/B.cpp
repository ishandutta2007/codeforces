#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std ;

#define eps 0.0001

int r , d ;
int n ;


void input ( ) {
    scanf ( "%d%d" , &r , &d ) ;
}

void solve ( ) {
    scanf ( "%d" , &n ) ;
    int x , y , z ;
    int i ;
    int ans = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        double u1 = ( x * x + y * y ) ;
        double u2 = ( x * x + y * y ) ;
        u1 = sqrt ( u1 ) ;
        u2 = sqrt ( u2 ) ;
        u1 -= z ;
        u2 += z ;
        if ( r - d - eps < u1 && u2 < r + eps ) {
            ans ++ ;
        }
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
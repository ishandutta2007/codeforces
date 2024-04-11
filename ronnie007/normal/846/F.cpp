#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std ;

#define MAXN 1000007

int n ;
int a[ MAXN ] ;

int lst[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int i ;
    double ans = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        int l = lst[ a[ i ] ] ;
        lst[ a[ i ] ] = i ;
        ans += 1LL * ( i - l ) * ( n - i + 1 ) ;
    }
    ans *= 2 ;
    ans -= n ;
    ans /= n ;
    ans /= n ;
    printf ( "%.12lf\n" , ans ) ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
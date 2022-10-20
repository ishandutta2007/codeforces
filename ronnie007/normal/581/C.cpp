#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std ;

#define MAXN 100007

int n , k ;
int a[ MAXN ] ;
int cur ;

bool f ( int x , int y ) {
    return ( ( x % 10 ) > ( y % 10 ) ) ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        cur += ( a[ i ] / 10 ) ;
    }
}

void solve ( ) {
    sort ( a + 1 , a + n + 1 , f ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( a[ i ] == 100 ) { continue ; }
        int lft = ( 10 - ( a[ i ] % 10 ) ) ;
        if ( k >= lft ) {
            k -= lft ;
            a[ i ] += lft ;
            cur ++ ;
        }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        int br = ( 100 - a[ i ] ) ;
        while ( br >= 10 ) {
            br -= 10 ;
            if ( k >= 10 ) {
                k -= 10 ;
                a[ i ] += 10 ;
                cur ++ ;
            }
        }
    }
    printf ( "%d\n" , cur ) ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
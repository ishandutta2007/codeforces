#include<iostream>
#include<stdio.h>
using namespace std ;

#define MAXN 1000007

int n , k ;
int a[ MAXN ] ;

int br[ 2 * MAXN ] ;
int lst[ 2 * MAXN ] ;

int mn = MAXN ;
void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        br[ a[ i ] ] ++ ;
        if ( mn > a[ i ] ) { mn = a[ i ] ; }
    }
}

void solve ( ) {
    int i , j ;
    int ans = 1 ;
    for ( i = 1 ; i <= 2000000 ; i ++ ) {
        if ( br[ i ] != 0 ) { lst[ i ] = i ; }
        else { lst[ i ] = lst[ i - 1 ] ; }
    }
    for ( i = 2 ; i <= mn ; i ++ ) {
        if ( i <= 1 ) { continue ; }
        for ( j = i ; j <= 2000000 ; j += i ) {
            int h = lst[ j - 1 ] ;
            if ( h - ( j - i ) > k ) { break ; }
        }
        if ( j > 2000000 ) { ans = i ; }
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std ;

#define MAXN 500007

int n , k ;
int a[ MAXN ] ;


void f1 ( ) {
    int i ;
    int lft = k ;
    int lst = a[ 1 ] ;
    int br = 1 ;
    for ( i = 2 ; i <= n ; i ++ ) {
        long long h = ( i - 1 ) ;
        h *= ( a[ i ] - lst ) ;
        if ( lft >= h ) {
            lft -= h ;
            lst = a[ i ] ;
            br ++ ;
        }
        else { break ; }
    }
    for ( i = 1 ; i <= br ; i ++ ) {
        a[ i ] = lst ;
    }
    int full = ( lft / br ) ;
    int ost = ( lft % br ) ;
    for ( i = 1 ; i <= br ; i ++ ) {
        a[ i ] += full ;
        if ( i <= ost ) { a[ i ] ++ ; }
    }
}

void f2 ( ) {
    int i ;
    int lft = k ;
    int lst = a[ n ] ;
    int br = 1 ;
    for ( i = n - 1 ; i >= 1 ; i -- ) {
        long long h = ( n - i ) ;
        h *= ( lst - a[ i ] ) ;
        if ( lft >= h ) {
            lft -= h ;
            lst = a[ i ] ;
            br ++ ;
        }
        else { break ; }
    }
    for ( i = 0 ; i < br ; i ++ ) {
        a[ n - i ] = lst ;
    }
    int full = ( lft / br ) ;
    int ost = ( lft % br ) ;
    for ( i = 0 ; i < br ; i ++ ) {
        a[ n - i ] -= full ;
        if ( i < ost ) { a[ n - i ] -- ; }
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int i ;
    sort ( a + 1 , a + n + 1 ) ;
    f1 ( ) ;
    sort ( a + 1 , a + n + 1 ) ;
    f2 ( ) ;
    sort ( a + 1 , a + n + 1 ) ;
    printf ( "%d\n" , a[ n ] - a[ 1 ] ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std ;

#define MAXN 107

int n , k ;
int a[ MAXN ] ;

int br1 , br2 , br4 ;

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    int i ;
    for ( i = 1 ; i <= k ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    br2 = 2 * n ;
    br4 = n ;
}

void solve ( ) {
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        int mx = 0 ;
        int id = 0 ;
        for ( j = 1 ; j <= k ; j ++ ) {
            if ( mx < a[ j ] ) { mx = a[ j ] ; id = j ; }
        }
        if ( mx >= 3 ) {
            br4 -- ;
            a[ id ] = max ( 0 , a[ id ] - 4 ) ;
        }
    }
    br2 += br4 ;
    br1 += br4 ;
    for ( i = 1 ; i <= k ; i ++ ) {
        while ( br2 > 0 && a[ i ] >= 2 ) {
            a[ i ] -= 2 ;
            br2 -- ;
        }
    }
    br1 += br2 ;
    for ( i = 1 ; i <= k ; i ++ ) {
        while ( br1 > 0 && a[ i ] >= 1 ) {
            a[ i ] -- ;
            br1 -- ;
        }
    }
    for ( i = 1 ; i <= k ; i ++ ) {
        if ( a[ i ] > 0 ) { printf ( "NO\n" ) ; return ; }
    }
    printf ( "YES\n" ) ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
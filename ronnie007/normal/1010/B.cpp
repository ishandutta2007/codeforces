#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std ;

int n , k ;
int h[ 37 ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
}

void solve ( ) {
    int l , r , mid ;
    l = 1 ;
    r = n ;
    int ans = 0 ;
    int i ;
    for ( i = 1 ; i <= k ; i ++ ) {
        printf ( "1\n" ) ;
        fflush(stdout);
        scanf ( "%d" , &h[ i ] ) ;
        if ( h[ i ] == 0 ) { return ; }

    }
    int id = 1 ;
    while ( r > l ) {
        mid = ( l + r ) / 2 ;
        printf ( "%d\n" , mid ) ;
        fflush(stdout);
        scanf ( "%d" , &ans ) ;
        ans *= h[ id ] ;
        if ( ans == 0 ) { return ; }
        if ( ans == 1 ) { l = mid + 1 ; }
        else { r = mid - 1 ; }
        id ++ ;
        if ( id > k ) { id -= k ; }
    }
    printf ( "%d\n" , l ) ;
    fflush(stdout);
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
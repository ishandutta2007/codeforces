#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;
int pos[ MAXN ] ;
int b[ MAXN ] ;

int f[ 2 * MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        pos[ a[ i ] ] = i ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &b[ i ] ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        int dist = pos[ b[ i ] ] - i ;
        if ( dist < 0 ) { dist += n ; }
        ++ f[ dist ] ;
    }
    int ans = 0 ;
    for ( int i = 0 ; i <= n ; ++ i ) {
        ans = max ( ans , f[ i ] ) ;
    }
    printf ( "%d\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
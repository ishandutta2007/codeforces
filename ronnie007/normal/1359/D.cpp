#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;

int l[ MAXN ] ;
int r[ MAXN ] ;
int ans = 0 ;

void f ( int x ) {
    int sm = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        l[ i ] = r[ i ] = 0 ; 
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ] > x ) { sm = 0 ; }
        else if ( a[ i ] < x ) {
            sm += a[ i ] ;
            if ( sm < 0 ) { sm = 0 ; }
        }
        else {
            l[ i ] = sm ;
            sm += a[ i ] ;
        }
    }
    sm = 0 ;
    for ( int i = n ; i >= 1 ; -- i ) {
        if ( a[ i ] > x ) { sm = 0 ; }
        else if ( a[ i ] < x ) {
            sm += a[ i ] ;
            if ( sm < 0 ) { sm = 0 ; }
        }
        else {
            r[ i ] = sm ;
            sm += a[ i ] ;
        }        
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ] == x ) {
            ans = max ( ans , l[ i ] + r[ i ] ) ;
        }
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    for ( int i = 30 ; i >= 1 ; -- i ) {
        f ( i ) ;
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
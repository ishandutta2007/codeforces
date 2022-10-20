#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;
int freq[ MAXN ] ;

int lst[ 2 * MAXN ] ;

int f ( int col , int mx ) {
    for ( int i = 0 ; i < 2 * MAXN ; ++ i ) {
        lst[ i ] = -1 ;
    }
    lst[ MAXN ] = 0 ;
    int h = MAXN ;
    int ret = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ] == col ) { ++ h ; }
        if ( a[ i ] == mx ) { -- h ; }
        if ( lst[ h ] != -1 ) {
            ret = max ( ret , i - lst[ h ] ) ;
        }
        else { lst[ h ] = i ; }
    }
    return ret ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        ++ freq[ a[ i ] ] ;
    }
}

void solve ( ) {
    int mx = 0 ;
    int id = 0 ;
    for ( int i = 1 ; i <= 100 ; ++ i ) {
        if ( mx < freq[ i ] ) {
            mx = freq[ i ] ;
            id = i ;
        }
    }
    int ans = 0 ;
    for ( int i = 1 ; i <= 100 ; ++ i ) {
        if ( i == id ) { continue ; }
        ans = max ( ans , f ( i , id ) ) ;
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
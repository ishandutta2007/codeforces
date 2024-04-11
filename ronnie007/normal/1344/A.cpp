#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;
map < int , int > w ;

void input ( ) {
    w.clear ( ) ;
    scanf ( "%d" , &n ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        a[ i ] += i ;
        a[ i ] %= n ;
        if ( a[ i ] < 0 ) { a[ i ] += n ; } 
    }
}

void solve ( ) {
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( w.find ( a[ i ] ) != w.end ( ) ) {
            printf ( "NO\n" ) ;
            return ;
        }
        w[ a[ i ] ] = 1 ;
    }
    printf ( "YES\n" ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
#include<bits/stdc++.h>
using namespace std ;

int n ;

void input ( ) {
    scanf ( "%d" , &n ) ;
}

void solve ( ) {
    int cnt = ( n / 4 ) + ( ( n % 4 ) > 0 ) ;
    for ( int i = 0 ; i < n - cnt ; ++ i ) {
        printf ( "9" ) ;
    }
    for ( int i = 0 ; i < cnt ; ++ i ) {
        printf ( "8" ) ;
    }
    printf ( "\n" ) ;
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
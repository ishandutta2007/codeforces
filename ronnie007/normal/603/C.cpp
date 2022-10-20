#include<bits/stdc++.h>
using namespace std ;


int n , k ;

int f ( int x ) {
    if ( x == 0 ) { return 0 ; }
    if ( k % 2 == 0 ) {
        if ( x <= 2 ) { return x ; }
        else if ( ( x % 2 ) == 1 ) { return 0 ; }
        else { return 1 ; }
    }
    else {
        if ( x == 1 ) { return 1 ; }
        if ( x == 3 ) { return 1 ; }
        if ( (x%2) == 1 ) { return 0 ; }
    }
    set < int > s ;
    s.clear ( ) ;
    s.insert ( f ( x - 1 ) ) ;
    if ( ( x % 2 ) == 0 ) {
        if ( k == 1 ) {
            s.insert ( f ( x / 2 ) ) ;
        }
        else {
            s.insert ( 0 ) ;
        }
    }
    int i ;
    for ( i = 0 ; i <= 3 ; i ++ ) {
        if ( s.find ( i ) == s.end ( ) ) { return i ; }
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    k %= 2 ;
}

void solve ( ) {
    int ans = 0 ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        int x ;
        scanf ( "%d" , &x ) ;
        ans ^= f ( x ) ;
    }
    if ( ans == 0 ) { printf ( "Nicky\n" ) ; }
    else { printf ( "Kevin\n" ) ; }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
#include<bits/stdc++.h>
using namespace std ;

int n ;

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    int cnt = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( cnt == n ) { break ; }
        printf ( "%d 1\n" , i ) ;
        ++ cnt ;
        if ( cnt == n ) { break ; }
        if ( ( i % 2 ) == 0 ) {
            printf ( "%d 4\n" , i ) ;
            ++ cnt ;
        }
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
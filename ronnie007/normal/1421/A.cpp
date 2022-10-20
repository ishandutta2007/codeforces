#include<bits/stdc++.h>
using namespace std ;

int x , y ;

void input ( ) {
    scanf ( "%d%d" , &x , &y ) ;
}

void solve ( ) {
    int ans = x + y ;
    for ( int i = 0 ; i < 30 ; ++ i ) {
        if ( ( x & (1<<i) ) > 0 && ( y & (1<<i) ) ) {
            ans -= 2 * (1<<i) ;
        }
    }
    printf ( "%d\n" , ans ) ;
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
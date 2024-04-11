#include<bits/stdc++.h>
using namespace std ;

int n , m , k ;

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &k ) ;
}

void solve ( ) {
    int cnt = n / k ;
    if ( cnt >= m ) { printf ( "%d\n" , m ) ; return ; }
    int lft = m - cnt ;
    int sub = ( lft / ( k - 1 ) ) ;
    if ( sub * ( k - 1 ) < lft ) { ++ sub ; }
    printf ( "%d\n" , cnt - sub ) ;
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
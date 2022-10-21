#include<bits/stdc++.h>
using namespace std ;

int l , r ;

void input ( ) {
    scanf ( "%*d%d%d" , &l , &r ) ;
}

void solve ( ) {
    int n ;
    scanf ( "%d" , &n ) ;
    int ans = 0 ;
    while ( n -- ) {
        int x ;
        scanf ( "%d" , &x ) ;
        ans += ( l < x && x < r ) ;
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
#include<bits/stdc++.h>
using namespace std ;

int x , y ; 

int calc ( int add ) {
    int ret = 0 ;
    int p = x ;
    int q = y + add ;
    while ( p > 0 ) {
        ++ ret ;
        p /= q ;
    }
    return ret ;
}

void input ( ) {
    cin >> x >> y ;
}

void solve ( ) {
    int ans = 1000000 ;
    for ( int w = 0 ; w < 100 ; ++ w ) {
        if ( y + w < 2 ) { continue ; }
        int ret = calc ( w ) ;
        ans = min ( ans , ret + w ) ;
    }
    cout << ans << "\n" ;
}

int main ( ) {
    // ios_base :: sync_with_stdio ( false ) ;
    // cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    cin >> t ;
    // t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
#include<bits/stdc++.h>
using namespace std ;

int n ;

bool f ( long long x ) {
    long long l , r , mid ;
    l = 0 ;
    r = x ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( x < mid * mid ) { r = mid ; }
        else { l = mid ; }
    }
    while ( r * r > x ) { -- r ; }
    if ( r * r == x ) { return true ; }
    return false ;
}

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    if ( ( n % 2 ) == 0 ) {
        if ( f ( n / 2 ) == true ) {
            cout << "YES\n" ;
            return ;
        }
    }
    if ( ( n % 4 ) == 0 ) {
        if ( f ( n / 4 ) == true ) {
            cout << "YES\n" ;
            return ;
        }
    }
    cout << "NO\n" ;
}

int main ( ) {
    //freopen ( "dictionary.in" , "r" , stdin ) ;
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
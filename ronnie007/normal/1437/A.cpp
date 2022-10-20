#include<bits/stdc++.h>
using namespace std ;

long long x , y ;

void input ( ) {
    cin >> x >> y ;
}

void solve ( ) {
    if ( 2 * x > y ) { cout << "YES\n" ; }
    else { cout << "NO\n" ; }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
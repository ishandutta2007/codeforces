#include<bits/stdc++.h>
using namespace std ;

long long x , y ;

void input ( ) {
    cin >> x >> y ;
}

void solve ( ) {
    if ( x > y ) { cout << x + y << "\n" ; }
    else { cout << y - ( y % x ) / 2 << "\n" ; }
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
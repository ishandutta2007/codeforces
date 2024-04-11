#include<bits/stdc++.h>
using namespace std ;

pair < int , int > a[ 3 ] ;


void input ( ) {
    for ( int i = 0 ; i < 3 ; ++ i ) {
        cin >> a[ i ].first >> a[ i ].second ;
    }
}

void solve ( ) {
    cout << "3\n" ;
    cout << - a[ 0 ].first + a[ 1 ].first + a[ 2 ].first << " " << - a[ 0 ].second + a[ 1 ].second + a[ 2 ].second << "\n" ;
    cout << a[ 0 ].first - a[ 1 ].first + a[ 2 ].first << " " << a[ 0 ].second - a[ 1 ].second + a[ 2 ].second << "\n" ;
    cout << a[ 0 ].first + a[ 1 ].first - a[ 2 ].first << " " << a[ 0 ].second + a[ 1 ].second - a[ 2 ].second << "\n" ;
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
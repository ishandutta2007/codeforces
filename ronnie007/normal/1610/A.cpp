#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int n , m ;

void input ( ) {
    cin >> n >> m ;
}

void solve ( ) {
    if ( n == 1 && m == 1 ) {
        cout << "0\n" ;
        return ;
    }
    if ( n == 1 || m == 1 ) {
        cout << "1\n" ;
        return ;
    }
    cout << "2\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
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
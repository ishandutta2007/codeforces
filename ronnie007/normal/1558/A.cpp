#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int a , b ;
set < int > s ;

void input ( ) {
    cin >> a >> b ;
}

void solve ( ) {
    s.clear ( ) ;
    int n = a + b ;
    for ( int st = 0 ; st < 2 ; ++ st ) {
        int h1 , h2 ;
        h1 = h2 = n / 2 ;

        if ( ( n % 2 ) == 1 ) {
            if ( st == 0 ) { ++ h1 ; }
            else { ++ h2 ; }
        }

        int mx = min ( h1 , b ) + min ( h2 , a ) ;
        int mn = n - min ( h1 , a ) - min ( h2 , b ) ;

        for ( int i = mn ; i <= mx ; i += 2 ) {
            s.insert ( i ) ;
        }
    }
    int sz = s.size ( ) ;
    cout << sz << "\n" ;
    for ( auto x : s ) {
        cout << x << " " ;
    }
    cout << "\n" ;
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
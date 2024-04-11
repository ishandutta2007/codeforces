#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

long long n ;

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    if ( ( n % 2050 ) != 0 ) {
        cout << "-1\n" ;
        return ;
    }
    n /= 2050 ;
    long long ans = 0 ;
    while ( n > 0 ) {
        ans += ( n % 10 ) ;
        n /= 10 ;
    }
    cout << ans << "\n" ; 
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
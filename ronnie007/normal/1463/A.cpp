#include<bits/stdc++.h>
using namespace std ;

long long x , y , z ;

void input ( ) {
    cin >> x >> y >> z ;
}

void solve ( ) {
    long long k = min ( x , y ) ;
    k = min ( k , z ) ;
    long long diff = x + y + z - 3 * k ;
    k *= 6 ;
    if ( k > 0 && diff >= 0 ) {
        if ( diff <= k ) {
            if ( ( k - diff ) % 9 == 0 ) {
                cout << "YES\n" ;
                return ;
            }
        }
    }
    cout << "NO\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
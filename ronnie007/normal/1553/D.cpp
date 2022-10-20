#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int n , k ;
string a , b ;

void input ( ) {
    cin >> a >> b ;
    n = a.size ( ) ;
    k = b.size ( ) ;
}

void solve ( ) {
    int x , y ;
    x = n - 1 ;
    y = k - 1 ;
    while ( x >= 0 && y >= 0 ) {
        if ( a[ x ] == b[ y ] ) {
            -- x , -- y ;
        }
        else {
            x -= 2 ;
        }
    }
    if ( y < 0 ) {
        cout << "YES\n" ;
        return ;
    }
    cout << "NO\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
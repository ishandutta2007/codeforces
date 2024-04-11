#include<bits/stdc++.h>
using namespace std ;

int n ;
string a ;

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    if ( ( n % 2 ) == 1 ) {
        cout << "NO\n" ;
        return ;
    }
    if ( a[ 0 ] == ')' || a[ n - 1 ] == '(' ) {
        cout << "NO\n" ;
        return ;
    }
    cout << "YES\n" ;
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
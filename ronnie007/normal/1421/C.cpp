#include<bits/stdc++.h>
using namespace std ;

int n ;
string s ;

void input ( ) {
    cin >> s ;
    n = s.size ( ) ;
}

void solve ( ) {
    cout << "3\n" ;
    cout << "L 2\n" ;
    cout << "R 2\n" ;
    cout << "R " << 2 * n - 1 << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
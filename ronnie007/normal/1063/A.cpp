#include<bits/stdc++.h>
using namespace std ;

int n ;
string a ;

void input ( ) {
    cin >> n ;
    cin >> a ;
}

void solve ( ) {
    sort ( a.begin ( ) , a.end ( ) ) ;
    cout << a << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
#include<bits/stdc++.h>
using namespace std ;

int n ;
string a ;

map < int , int > w ;

void input ( ) {
    cin >> n ;
    cin >> a ;
}

void solve ( ) {
    w.clear ( ) ;
    w[ 0 ] = 1 ;
    int sm = 0 ;
    long long ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int x = ( a[ i - 1 ] - '0' ) ;
        sm += x ;
        ans += w[ sm - i ] ;
        ++ w[ sm - i ] ;
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
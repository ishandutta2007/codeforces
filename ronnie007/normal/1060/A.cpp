#include<bits/stdc++.h>
using namespace std ;

int n ;
string a ;

void input ( ) {
    cin >> n ;
    cin >> a ;
}

void solve ( ) {
    int cnt = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cnt += ( a[ i ] == '8' ) ;
    }
    int ans = 0 ;
    while ( cnt > 0 && n >= 11 ) {
        ++ ans ;
        -- cnt ;
        n -= 11 ;
        cnt = min ( cnt , n ) ;
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
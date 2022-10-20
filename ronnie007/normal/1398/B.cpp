#include<bits/stdc++.h>
using namespace std ;

int n ;
string a ;
vector < int > v ;

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    v.clear ( ) ;
    int cnt = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( a[ i ] == '1' ) {
            ++ cnt ;
        }
        else {
            if ( cnt > 0 ) {
                v.push_back ( cnt ) ;
            }
            cnt = 0 ;
        }
    }
    if ( cnt > 0 ) { v.push_back ( cnt ) ; }
    sort ( v.begin ( ) , v.end ( ) , greater < int > ( ) ) ;
    int ans = 0 ;
    int sz = v.size ( ) ;
    for ( int i = 0 ; i < sz ; i += 2 ) {
        ans += v[ i ] ;
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
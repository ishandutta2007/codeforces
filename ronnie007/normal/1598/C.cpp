#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
long long a[ MAXN ] ;
long long act ;
map < long long , int > w ;

void input ( ) {
    cin >> n ;
    act = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        act += a[ i ] ;
        a[ i ] *= n ;
    }
}

void solve ( ) {
    w.clear ( ) ;
    long long ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        long long diff = a[ i ] - act ;
        ans += w[ -diff ] ;
        ++ w[ diff ] ;
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    /// t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
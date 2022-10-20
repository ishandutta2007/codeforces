#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
long long a[ MAXN ] ;

long long ans ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    ans = 0 ;
    long long lst = a[ n ] ;
    for ( int i = n - 1 ; i >= 1 ; -- i ) {
        if ( a[ i ] <= lst ) {
            lst = a[ i ] ;
        }
        else {
            ans += a[ i ] - lst ;
            lst = a[ i ] ;
        }
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
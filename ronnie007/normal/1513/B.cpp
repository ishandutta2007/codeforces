#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007
#define MOD 1000000007

int n ;
int a[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    int hh = a[ 1 ] ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        hh = ( hh & a[ i ] ) ;
    }
    int cnt = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cnt += ( a[ i ] == hh ) ;
    }
    long long ans = 1 ;
    ans = cnt ;
    ans = ( ans * ( cnt - 1 ) ) % MOD ;
    for ( int i = 1 ; i <= n - 2 ; ++ i ) {
        ans *= i ;
        ans %= MOD ;
    }
    cout << ans << "\n" ;
}

int main ( ) {
    //freopen ( "dictionary.in" , "r" , stdin ) ;
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
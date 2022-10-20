#include<bits/stdc++.h>
using namespace std ;

#define MOD 1000000007

long long n ;

long long f ( long long x , long long y ) {
    if ( x < y ) { swap ( x , y ) ; }
    if ( y == 0 ) { return x ; }
    return f ( y , ( x % y ) ) ;
}

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    long long aux = 1 ;
    long long ans = n % MOD ;
    for ( int i = 2 ; i <= 1000 ; ++ i ) {
        ans += ( n / aux ) % MOD ;
        ans %= MOD ;
        long long cm = f ( aux , i ) ;
        long long coef = i / cm ;
        if ( n / coef < aux ) { break ; }
        aux *= coef ;
        if ( aux > n ) { break ; }
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // t = 1 ;
    cin >> t ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
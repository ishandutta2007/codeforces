#include<bits/stdc++.h>
using namespace std ;

#define MOD 1000000007
#define MAXN 200007

long long n , k ;

long long fastpow ( long long x , long long pw ) {
    long long ret = 1 ;
    while ( pw > 0 ) {
        if ( ( pw % 2 ) == 0 ) {
            x = ( x * x ) % MOD ;
            pw /= 2 ;
        }
        else {
            ret = ( ret * x ) % MOD ;
            -- pw ;
        }
    }
    return ret ;
}

long long even[ MAXN ] ;

void init ( ) {
    even[ 1 ] = 1 ;
    for ( int i = 2 ; i < MAXN ; ++ i ) {
        even[ i ] = ( even[ i - 1 ] * 2 ) % MOD ;
    }
}

void input ( ) {
    cin >> n >> k ;
}

void solve ( ) {
    long long ans = 0 ;
    long long coef = 1 ;
    long long aux = even[ n ] ;
    if ( ( n % 2 ) == 0 ) {
        aux = ( aux - 1 + MOD ) % MOD ;
    }
    else { aux = ( aux + 1 ) % MOD ; }
    for ( int i = 1 ; i <= k ; ++ i ) {
        if ( ( n % 2 ) == 0 ) {
            ans = ( ans + coef * fastpow ( 2 , n * ( k - i ) ) ) % MOD ;
        }
        coef = ( coef * aux ) % MOD ;
    }
    ans = ( ans + coef ) % MOD ;
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    init ( ) ;
    int t ;
    // t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
#include<bits/stdc++.h>
using namespace std ;

#define MOD 998244353
#define MAXN 100007

int n ;
string a ;

long long fac[ MAXN ] ;
long long inv[ MAXN ] ;

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

void init ( ) {
    fac[ 0 ] = 1 ;
    for ( int i = 1 ; i < MAXN ; ++ i ) {
        fac[ i ] = ( fac[ i - 1 ] * i ) % MOD ;
    }
    inv[ MAXN - 1 ] = fastpow ( fac[ MAXN - 1 ] , MOD - 2 ) ;
    for ( int i = MAXN - 2 ; i >= 0 ; -- i ) {
        inv[ i ] = ( inv[ i + 1 ] * ( i + 1 ) ) % MOD ;
    }
}

void input ( ) {
    cin >> n ;
    cin >> a ;
}

void solve ( ) {
    int up = 0 ;
    int down = 0 ;
    int cnt = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( a[ i ] == '0' ) {
            if ( cnt > 0 ) { 
                up += ( cnt / 2 ) ;
                cnt = 0 ;
            }
            ++ up , ++ down ;
        }
        else { ++ cnt ; }
    }
    if ( cnt > 0 ) {
        up += cnt / 2 ;
        cnt = 0 ;
    }
    long long ret = fac[ up ] ;
    ret = ( ret * inv[ down ] ) % MOD ;
    ret = ( ret * inv[ up - down ] ) % MOD ;
    cout << ret << "\n" ;
}

int main ( ) {
    //freopen ( "dictionary.in" , "r" , stdin ) ;
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    init ( ) ;
    cin >> t ;
    // t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
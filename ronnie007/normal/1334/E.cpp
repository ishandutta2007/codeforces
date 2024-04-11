#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
#include<unordered_map>
using namespace std ;

#define MOD 998244353
#define MAXN 300007

long long NUM ;

long long fac[ MAXN ] ;
long long inv[ 77 ] ;

vector < long long > pr ;

long long fastpow ( long long x , long long pw ) {
    long long ret = 1 ;
    while ( pw > 0 ) {
        if ( ( pw & 1 ) == 0 ) {
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


long long ways ( long long x ) {
    long long sm = 0 ;
    long long ret = 1 ;
    int sz = pr.size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int cnt = 0 ;
        while ( ( x % pr[ i ] ) == 0 ) {
            x /= pr[ i ] ;
            ++ cnt ; 
        }
        if ( cnt > 0 ) {
            sm += cnt ;
            ret = ( ret * inv[ cnt ] ) % MOD ;
        }
    }
    return ( ret * fac[ sm ] ) % MOD ;
}

void extr_primes ( long long x ) {
    long long h = 2 ;
    while ( h * h <= x ) {
        if ( ( x % h ) == 0 ) {
            pr.push_back ( h ) ;
            while ( ( x % h ) == 0 ) {
                x /= h ;
            }
        }
        ++ h ;
    }
    if ( x > 1 ) {
        pr.push_back ( x ) ;
    }
}

void input ( ) {
    cin >> NUM ;
    extr_primes ( NUM ) ;
}

void solve ( ) {
    fac[ 0 ] = 1 ;
    for ( int i = 1 ; i < MAXN ; ++ i ) {
        fac[ i ] = ( fac[ i - 1 ] * i ) % MOD ;
    }
    for ( int i = 0 ; i <= 77 ; ++ i ) {
        inv[ i ] = fastpow ( fac[ i ] , MOD - 2 ) ;
    }
    int q ;
    cin >> q ;
    while ( q -- ) {
        long long x , y ;
        cin >> x >> y ;
        long long u = __gcd ( x , y ) ;
        x /= u ; y /= u ;
        cout << ( ways ( x ) * ways ( y ) ) % MOD << "\n" ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
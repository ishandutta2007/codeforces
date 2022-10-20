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
using namespace std ;

#define MOD 1000000007

long long x , n ;
long long ans = 1 ;

long long fastpow ( long long aux , long long pw ) {
    long long ret = 1 ;
    aux %= MOD ;

    while ( pw > 0 ) {
        if ( ( pw % 2 ) == 0 ) {
            aux = ( aux * aux ) % MOD ;
            pw >>= 1 ;
        }
        else {
            ret = ( ret * aux ) % MOD ;
            -- pw ;
        }
    }
    return ret ;
}

void upd ( long long steps , long long aux ) {
    if ( steps > n ) { return ; }
    long long cnt = ( n / steps ) ;
    cnt = fastpow ( aux , cnt ) ;
    ans = ( ans * cnt ) % MOD ;
}

void input ( ) {
    cin >> x >> n ;
}

void solve ( ) {
    vector < int > v ;
    for ( long long i = 2 ; i * i <= x ; ++ i ) {
        if ( ( x % i ) == 0 ) {
            v.push_back ( i ) ;
            while ( ( x % i ) == 0 ) { x /= i ; }
        }
    }
    if ( x > 1 ) { v.push_back ( x ) ; }
    for ( long long aux : v ) {
        long long y = aux ;
        upd ( y , aux ) ;
        while ( ( n / y ) >= aux ) {
            y *= aux ;
            upd ( y , aux ) ;
        }
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
#include<bits/stdc++.h>
using namespace std ;

#define MAXN 23
#define MOD 998244353


int n ;
struct el {
    int cnt[ 26 ] ;
};

el a[ 23 ] ;

long long all[ ( 1 << MAXN ) ] ;
long long dp[ ( 1 << ( MAXN - 1 ) ) ] ;


void input ( ) {
    cin >> n ;
    for ( int i = 0 ; i < n ; ++ i ) {
        string foo ; cin >> foo ;
        for ( auto c : foo ) {
            ++ a[ i ].cnt[ ( c - 'a' ) ] ;
        }
    }
}

void solve ( ) {
    el aux ;
    for ( int mask = 1 ; mask < ( 1 << n ) ; ++ mask ) {
        for ( int i = 0 ; i < 26 ; ++ i ) {
            aux.cnt[ i ] = 20007 ;
        }
        int t = 0 ;
        for ( int i = 0 ; i < n ; ++ i ) {
            if ( ( mask & ( 1 << i ) ) == 0 ) { continue ; }
            t ^= 1 ;
            for ( int j = 0 ; j < 26 ; ++ j ) {
                aux.cnt[ j ] = min ( aux.cnt[ j ] , a[ i ].cnt[ j ] ) ;
            }
        }
        all[ mask ] = 1 ;
        for ( int i = 0 ; i < 26 ; ++ i ) {
            all[ mask ] = ( all[ mask ] * ( aux.cnt[ i ] + 1 ) ) % MOD ;
        }
        if ( t == 1 ) {
            dp[ mask ] = all[ mask ] ;
        }
        else {
            dp[ mask ] = MOD - all[ mask ] ;
        }
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < ( 1 << n ) ; ++ j ) {
            if ( ( j & ( 1 << i ) ) == 0 ) {
                dp[ j + ( 1 << i ) ] = ( dp[ j + ( 1 << i ) ] + dp[ j ] ) % MOD ;
            }
        }
    }
    long long ans = 0 ;
    for ( int mask = 1 ; mask < ( 1 << n ) ; ++ mask ) {
        long long coef = 0 ;
        int cnt = 0 ;
        for ( int i = 0 ; i < n ; ++ i ) {
            if ( ( mask & ( 1 << i ) ) > 0 ) { ++ cnt , coef += ( i + 1 ) ; }
        }
        coef *= cnt ;
        coef %= MOD ;
        long long hh = dp[ mask ] ;

        hh = hh * coef ;
        ans = ( ans ^ hh ) ;
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
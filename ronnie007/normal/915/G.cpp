#include<bits/stdc++.h>
using namespace std ;

#define MOD 1000000007
#define MAXN 2000007

int n , k ;
vector < int > v[ MAXN ] ;
long long w[ MAXN ] ;

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

void input ( ) {
    cin >> n >> k ;
    for ( int i = 2 ; i <= k ; ++ i ) {
        if ( v[ i ].size ( ) > 0 ) { continue ; }
        for ( int j = i ; j <= k ; j += i ) {
            v[ j ].push_back ( i ) ;
        }
    }
}

void solve ( ) {
    long long tot = 0 ;
    long long ans = 0 ;
    for ( int i = 0 ; i <= k ; ++ i ) {
        w[ i ] = fastpow ( i , n ) ;
    }
    for ( int i = 2 ; i <= k ; ++ i ) {
        int sz = v[ i ].size ( ) ;
        int sr = (1<<sz) ;
        for ( int mask = 1 ; mask < sr ; ++ mask ) {
            int h = 1 ;
            int p = 0 ;
            for ( int j = 0 ; j < sz ; ++ j ) {
                if ( ( mask & (1<<j) ) > 0 ) {
                    h *= v[ i ][ j ] ;
                    ++ p ;
                }
            }
            int cnt = ( i / h ) ;
            long long coef = ( w[ cnt ] - w[ cnt - 1 ] + MOD ) % MOD ;
            if ( ( p % 2 ) == 0 ) {
                tot = ( tot - coef + MOD ) % MOD ;
            }
            else {
                tot = ( tot + coef ) % MOD ;
            }
        }
        long long lft = ( w[ i ] - tot + MOD ) % MOD ;
        ans = ( ans + ( lft ^ i ) ) % MOD ;
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
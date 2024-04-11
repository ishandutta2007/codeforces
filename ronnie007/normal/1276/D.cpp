#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007
#define MOD 998244353

int n ;
vector < pair < int , int > > v[ MAXN ] ;

long long dp[ MAXN ][ 3 ] ;
long long pref[ MAXN ] ;
long long suff[ MAXN ] ;


void dfs ( int vertex , int prv ) {
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ vertex ][ i ].first == prv ) { continue ; }
        dfs ( v[ vertex ][ i ].first , vertex ) ;
    }
    pref[ 0 ] = 1 ;
    for ( int i = 1 ; i <= sz ; ++ i ) {
        if ( v[ vertex ][ i - 1 ].first == prv ) {
            pref[ i ] = pref[ i - 1 ] ;
            continue ;
        }
        int h = v[ vertex ][ i - 1 ].first ;
        long long coef = ( dp[ h ][ 0 ] + dp[ h ][ 2 ] ) % MOD ;
        pref[ i ] = ( pref[ i - 1 ] * coef ) % MOD ;
    }
    suff[ sz + 1 ] = 1 ;
    for ( int i = sz ; i >= 1 ; -- i ) {
        if ( v[ vertex ][ i - 1 ].first == prv ) {
            suff[ i ] = suff[ i + 1 ] ;
            continue ;
        }
        int h = v[ vertex ][ i - 1 ].first ;
        long long coef = ( dp[ h ][ 0 ] + dp[ h ][ 1 ] ) % MOD ;
        suff[ i ] = ( suff[ i + 1 ] * coef ) % MOD ;
    }
    dp[ vertex ][ 1 ] = pref[ sz ] ;
    int id = 0 ;
    for ( int i = 1 ; i <= sz ; ++ i ) {
        int h = v[ vertex ][ i - 1 ].first ;
        if ( h == prv ) {
            dp[ vertex ][ 2 ] = ( pref[ i - 1 ] * suff[ i + 1 ] ) % MOD ;
            id ^= 1 ;
            continue ;
        }
        long long add = ( pref[ i - 1 ] * dp[ h ][ 1 ] ) % MOD ;
        add = ( add * suff[ i + 1 ] ) % MOD ;
        dp[ vertex ][ id ] = ( dp[ vertex ][ id ] + add ) % MOD ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( { y , i } ) ;
        v[ y ].push_back ( { x , i } ) ;
    }
}

void solve ( ) {
    dfs ( 1 , -1 ) ;
    printf ( "%I64d\n" , ( dp[ 1 ][ 0 ] + dp[ 1 ][ 1 ] ) % MOD ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
#include<bits/stdc++.h>
using namespace std ;


// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 5000007
#define MOD 1000000007

int n ;
int a[ MAXN ] ;
int t[ MAXN ] ;

int ans[ MAXN ] ;

int seed , base ;

int rng ( ) {
    int ret = seed ;
    seed = ( 1LL * seed * base + 233 ) % MOD ;
    return ret ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    int m ; scanf ( "%d" , &m ) ;
    int lst = 0 ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int p , b , k , w ;
        scanf ( "%d%d%d%d" , &p , &k , &b , &w ) ;
        seed = b ;
        base = w ;
        for ( int j = lst + 1 ; j <= p ; ++ j ) {
            t[ j ] = ( rng ( ) % 2 ) + 1 ;
            a[ j ] = ( rng ( ) % k ) + 1 ;
        }
        lst = p ;
    }
}

void solve ( ) {
    long long sm1 , sm2 ;
    sm1 = sm2 = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( t[ i ] == 1 ) { sm1 += a[ i ] ; }
        else { sm2 += a[ i ] ; }
    }
    if ( sm1 > sm2 ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            t[ i ] = 3 - t[ i ] ;
        }
    }
    int pos = 1 ;
    if ( t[ 1 ] == 2 ) {
        for ( int i = 2 ; i <= n ; ++ i ) {
            if ( t[ i ] == 1 ) { pos = i ; break ; }
        }
        ++ ans[ 1 ] ; -- a[ 1 ] ;
    }
    long long aux = 0 ;
    for ( int hh = 0 ; hh < 2 ; ++ hh ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            if ( t[ pos ] == 1 ) {
                aux += a[ pos ] ;
                ans[ pos ] += a[ pos ] ;
                a[ pos ] = 0 ;
            }
            else {
                long long sub = min ( aux , 1LL * a[ pos ] ) ;
                a[ pos ] -= sub ; ans[ pos ] += sub ;
                aux -= sub ;
            }
            ++ pos ;
            if ( pos == n + 1 ) { pos = 1 ; }
        }
    }
    long long ret = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        long long hh = ( ans[ i ] ^ ( 1LL * i * i ) ) + 1 ;
        hh %= MOD ;
        ret = ( ret * hh ) % MOD ;
    }
    printf ( "%d\n" , ret ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
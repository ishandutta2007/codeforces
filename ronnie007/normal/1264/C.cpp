#include<bits/stdc++.h>
using namespace std ;

#define MOD 998244353
#define MAXN 200007

int n , q ;
long long a[ MAXN ] ;
long long pref[ MAXN ] ;
long long sm[ MAXN ] ;

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

long long f ( int st , int en ) {
    -- en ;
    long long ret = sm[ en - 1 ] ;
    ret = ( ret - sm[ st - 1 ] + MOD ) % MOD ;
    ret = ( ret * fastpow ( pref[ st - 1 ] , MOD - 2 ) ) % MOD ;
    ret = ( ret + 1 ) % MOD ;
    long long div = ( pref[ en ] * fastpow ( pref[ st - 1 ] , MOD - 2 ) ) % MOD ;
    ret = ( ret * fastpow ( div , MOD - 2 ) ) % MOD ;
    return ret ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
    pref[ 0 ] = 1 ;
    sm[ 0 ] = 1 ;
    long long inv = fastpow ( 100 , MOD - 2 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        a[ i ] = ( a[ i ] * inv ) % MOD ;
        pref[ i ] = ( pref[ i - 1 ] * a[ i ] ) % MOD ;
        sm[ i ] = ( sm[ i - 1 ] + pref[ i ] ) % MOD ;
    }
}

void solve ( ) {
    set < int > s ;
    s.insert ( 1 ) ;
    s.insert ( n + 1 ) ;
    long long ans = f ( 1 , n + 1 ) ;
    while ( q -- ) {
        int x ;
        scanf ( "%d" , &x ) ;
        if ( s.find ( x ) == s.end ( ) ) {
            s.insert ( x ) ;
            set < int > :: iterator it = s.find ( x ) ;
            set < int > :: iterator prv = it ;
            set < int > :: iterator nxt = it ;
            -- prv ; ++ nxt ;
            ans = ( ans - f ( *prv , *nxt ) + MOD ) % MOD ;
            ans = ( ans + f ( *prv , *it ) ) % MOD ;
            ans = ( ans + f ( *it , *nxt ) ) % MOD ;
        }
        else {
            set < int > :: iterator it = s.find ( x ) ;
            set < int > :: iterator prv = it ;
            set < int > :: iterator nxt = it ;
            -- prv ; ++ nxt ;
            ans = ( ans + f ( *prv , *nxt ) ) % MOD ;
            ans = ( ans - f ( *prv , *it ) + MOD ) % MOD ;
            ans = ( ans - f ( *it , *nxt ) + MOD ) % MOD ;            
            s.erase ( it ) ;
        }
        printf ( "%I64d\n" , ans ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
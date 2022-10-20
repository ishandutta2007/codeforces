#include<bits/stdc++.h>
using namespace std ;

#define MOD 998244353

#define MAXN 200007
int n , k ;

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

long long fac[ MAXN ] ;
long long inv[ MAXN ] ;

long long get_comb ( int n , int x ) {
    long long ret = fac[ n ] ;
    ret = ( ret * inv[ x ] ) % MOD ;
    ret = ( ret * inv[ n - x ] ) % MOD ;
    return ret ;
}

void input ( ) {
    cin >> n >> k ;
}

void solve ( ) {
    if ( k >= n ) {
        printf ( "0\n" ) ;
        return ;
    }
    if ( k == 0 ) {
        long long ans = 1 ;        
        for ( int i = 1 ; i <= n ; ++ i ) {
            ans = ( ans * i ) % MOD ;
        }
        printf ( "%I64d\n" , ans ) ;
        return ;
    }
    int h = n - k ;
    fac[ 0 ] = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        fac[ i ] = ( fac[ i - 1 ] * i ) % MOD ;
    }
    inv[ n ] = fastpow ( fac[ n ] , MOD - 2 ) ;
    for ( int i = n - 1 ; i >= 0 ; -- i ) {
        inv[ i ] = ( inv[ i + 1 ] * ( i + 1 ) ) % MOD ;
    }
    long long ans = 0 ;
    for ( int i = 0 ; i <= h ; ++ i ) {
        long long aux = get_comb ( h , i ) ;
        aux = ( aux * fastpow ( i , n ) ) % MOD ;
        if ( ( h - i ) % 2 == 1 ) { aux = MOD - aux ; }
        ans = ( ans + aux ) % MOD ;
    }
    ans = ( ans * get_comb ( n , h ) ) % MOD ;
    ans = ( ans * 2 ) % MOD ;
    printf ( "%I64d\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
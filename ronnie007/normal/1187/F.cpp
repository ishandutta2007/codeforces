#include<bits/stdc++.h>
using namespace std ;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 200007
#define MOD 1000000007

int n ;
int l[ MAXN ] ;
int r[ MAXN ] ;

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

long long eq[ MAXN ] ;
long long ch[ MAXN ] ;
long long pref[ MAXN ] ;
long long suff[ MAXN ] ;


void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> l[ i ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> r[ i ] ;
        ++ r[ i ] ;
    }
    ch[ 1 ] = 1 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        eq[ i ] = ( min ( r[ i ] , r[ i - 1 ] ) - max ( l[ i ] , l[ i - 1 ] ) ) ;
        if ( eq[ i ] < 0 ) { eq[ i ] = 0 ; }
        eq[ i ] = ( eq[ i ] * fastpow ( r[ i ] - l[ i ] , MOD - 2 ) ) % MOD ;
        eq[ i ] = ( eq[ i ] * fastpow ( r[ i - 1 ] - l[ i - 1 ] , MOD - 2 ) ) % MOD ;

        ch[ i ] = ( 1 - eq[ i ] + MOD ) % MOD ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        pref[ i ] = ( pref[ i - 1 ] + ch[ i ] ) % MOD ;
    }
    for ( int i = n ; i >= 1 ; -- i ) {
        suff[ i ] = ( suff[ i + 1 ] + ch[ i ] ) % MOD ;
    }
}

long long proc ( int st ) {
    long long ret = 1 ;
    ret = ( ret - eq[ st ] + MOD ) % MOD ;
    ret = ( ret - eq[ st + 1 ] + MOD ) % MOD ;
    long long hh = min ( min ( r[ st - 1 ] , r[ st ] ) , r[ st + 1 ] ) 
        - max ( max ( l[ st - 1 ] , l[ st ] ) , l[ st + 1 ] ) ;
    if ( hh < 0 ) { hh = 0 ; }
    hh = ( hh * fastpow ( r[ st - 1 ] - l[ st - 1 ] , MOD - 2 ) ) % MOD ;
    hh = ( hh * fastpow ( r[ st ] - l[ st ] , MOD - 2 ) ) % MOD ;    
    hh = ( hh * fastpow ( r[ st + 1 ] - l[ st + 1 ] , MOD - 2 ) ) % MOD ;
    ret = ( ret + hh ) % MOD ;
    return ret ;
}

void solve ( ) {
    long long ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        ans = ( ans + ch[ i ] ) % MOD ;
        long long sm = 0 ;
        if ( i >= 2 ) { sm += pref[ i - 2 ] ; }
        sm += suff[ i + 2 ] ;

        ans = ( ans + ch[ i ] * sm ) % MOD ;

        if ( i > 1 ) {
            ans = ( ans + proc ( i - 1 ) ) % MOD ;
        }
        if ( i < n ) {
            ans = ( ans + proc ( i ) ) % MOD ;
        }
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
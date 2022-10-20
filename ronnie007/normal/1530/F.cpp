#include<bits/stdc++.h>
using namespace std ;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")


#define MAXN 23
#define MOD 31607


int n ;
int a[ MAXN ][ MAXN ] ;

int prod[ MAXN ] ;

unsigned short dp[ ( 1 << MAXN ) ][ 2 ] ;
int ans = 0 ;
int lim = 10000 ;

int prec[ MOD + 2 ] ;
int inv ;

unsigned short val[ ( 1 << 21 ) ][ MAXN ] ;

int fastpow ( int x , int pw ) {
    int ret = 1 ;
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
    cin >> n ;
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < n ; ++ j ) {
            cin >> a[ i ][ j ] ;
        }
    }
    inv = fastpow ( lim , MOD - 2 ) ;
    for ( int i = 0 ; i < MOD ; ++ i ) {
        prec[ i ] = ( i * inv ) % MOD ;
    }
    for ( int j = 0 ; j < n ; ++ j ) {
        prod[ j ] = 1 ;
        for ( int i = 0 ; i < n ; ++ i ) {
            prod[ j ] = ( prod[ j ] * a[ i ][ j ] ) % MOD ;
            // prod[ i ] = ( prod[ i ] * inv ) % MOD ;
            prod[ j ] = prec[ prod[ j ] ] ;
        }
    }

    for ( int i = 0 ; i < n ; ++ i ) {
        val[ 0 ][ i ] = 1 ;
    }
    for ( int mask = 1 ; mask < ( 1 << n ) ; ++ mask ) {
        int lw = ( mask & ( mask - 1 ) ) ;
        int pos = -1 ;
        int diff = ( mask - lw ) ;
        while ( diff > 0 ) { diff /= 2 ; ++ pos ; }
        for ( int i = 0 ; i < n ; ++ i ) {
            val[ mask ][ i ] = val[ lw ][ i ] ;
            val[ mask ][ i ] = ( val[ mask ][ i ] * a[ i ][ pos ] ) % MOD ;
            val[ mask ][ i ] = ( val[ mask ][ i ] * inv ) % MOD ;
        }
    }
}

void solve ( ) {
    int cnt = n + 2 ;
    for ( int mask = 0 ; mask < ( 1 << cnt ) ; ++ mask ) {
        dp[ mask ][ 0 ] = 1 ;
        dp[ mask ][ 1 ] = 0 ;
        for ( int i = 0 ; i < n ; ++ i ) {
            int aux = ( mask & ( ( 1 << n ) - 1 ) ) ^ ( ( 1 << n ) - 1 ) ;
            if ( ( mask & ( 1 << n ) ) > 0 ) {
                if ( ( aux & ( 1 << i ) ) > 0 ) {
                    aux ^= ( 1 << i ) ;
                }
            }
            if ( ( mask & ( 1 << ( n + 1 ) ) ) > 0 ) {
                if ( ( aux & ( 1 << ( n - i - 1 ) ) ) > 0 ) {
                    aux ^= ( 1 << ( n - i - 1 ) ) ;
                }
            }
            
            int old0 = dp[ mask ][ 0 ] ;
            int old1 = dp[ mask ][ 1 ] ;

            dp[ mask ][ 0 ] += ( old1 * val[ aux ][ i ] ) % MOD ;
            if ( dp[ mask ][ 0 ] >= MOD ) { dp[ mask ][ 0 ] -= MOD ; }
            
            dp[ mask ][ 1 ] += ( old0 * val[ aux ][ i ] ) % MOD ;
            if ( dp[ mask ][ 1 ] >= MOD ) { dp[ mask ][ 1 ] -= MOD ; }
        }
    }

    for ( int mask = 0 ; mask < ( 1 << cnt ) ; ++ mask ) {
        int coef = 1 ;
        for ( int i = 0 ; i < n ; ++ i ) {
            if ( ( mask & ( 1 << i ) ) > 0 ) {
                coef = ( coef * prod[ i ] ) % MOD ;
            }
        }

        if ( ( mask & ( 1 << n ) ) > 0 ) {
            for ( int i = 0 ; i < n ; ++ i ) {
                if ( ( mask & ( 1 << i ) ) == 0 ) {
                    coef = ( coef * a[ i ][ i ] ) % MOD ;
                    // coef = ( coef * inv ) % MOD ;
                    coef = prec[ coef ] ;
                }
            }
        }
        if ( ( mask & ( 1 << n + 1 ) ) > 0 ) {
            for ( int i = 0 ; i < n ; ++ i ) {
                if ( ( mask & ( 1 << i ) ) == 0 ) {
                    if ( ( mask & ( 1 << n ) ) == 0 || i + i != n - 1 ) {
                        coef = ( coef * a[ n - i - 1 ][ i ] ) % MOD ;
                        // coef = ( coef * inv ) % MOD ;
                        coef = prec[ coef ] ;
                    }
                }
            }
        }
        int pcnt = __builtin_popcount ( mask ) ;
        if ( ( pcnt % 2 ) == 0 ) {
            ans += ( coef * dp[ mask ][ 0 ] ) % MOD ;
            if ( ans >= MOD ) { ans -= MOD ; }
            ans -= ( coef * dp[ mask ][ 1 ] ) % MOD ;
            if ( ans < 0 ) { ans += MOD ; }
        }
        else {
            ans += ( coef * dp[ mask ][ 1 ] ) % MOD ;
            if ( ans >= MOD ) { ans -= MOD ; }
            ans -= ( coef * dp[ mask ][ 0 ] ) % MOD ;
            if ( ans < 0 ) { ans += MOD ; }
        }
    }

    ans = ( 1 - ans + MOD ) % MOD ;
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // cin >> t ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
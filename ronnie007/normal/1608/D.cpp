#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MOD 998244353
#define MAXN 100007

int n ;
string a[ MAXN ] ;

int cnt[ 2 ][ 2 ] ;

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

long long fac[ MAXN ] ;
long long inv[ MAXN ] ;

bool eq ;
int emp , hh ;

long long comb ( int up , int down ) {
    if ( up < down ) { return 0 ; }
    long long ret = fac[ up ] ;
    ret = ( ret * inv[ down ] ) % MOD ;
    ret = ( ret * inv[ up - down ] ) % MOD ;
    return ret ;
}

void input ( ) {
    cin >> n ;
    eq = false ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        for ( int j = 0 ; j < 2 ; ++ j ) {
            if ( a[ i ][ j ] == 'W' ) {
                ++ cnt[ j ][ 0 ] ;
            }
            else if ( a[ i ][ j ] == 'B' ) {
                ++ cnt[ j ][ 1 ] ;
            }
        }
        if ( a[ i ][ 0 ] != '?' && a[ i ][ 1 ] != '?' ) {
            if ( a[ i ][ 0 ] == a[ i ][ 1 ] ) {
                eq = true ;
            }
        }
        if ( a[ i ][ 0 ] == 'W' || a[ i ][ 1 ] == 'B' ) { ++ hh ; }
        if ( a[ i ][ 0 ] == '?' && a[ i ][ 1 ] == '?' ) {
            ++ emp ;
        }
    }
    fac[ 0 ] = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        fac[ i ] = ( fac[ i - 1 ] * i ) % MOD ;
    }
    inv[ n ] = fastpow ( fac[ n ] , MOD - 2 ) ;
    for ( int i = n - 1 ; i >= 0 ; -- i ) {
        inv[ i ] = ( inv[ i + 1 ] * ( i + 1 ) ) % MOD ;
    }
}   

void solve ( ) {
    if ( n == 1 ) {
        if ( a[ 1 ][ 0 ] == '?' && a[ 1 ][ 1 ] == '?' ) {
            cout << "2\n" ;
            return ;
        }
        if ( a[ 1 ][ 0 ] == a[ 1 ][ 1 ] ) {
            cout << "0\n" ;
            return ;
        }
        cout << "1\n" ;
        return ;
    }
    long long ans = 0 ;
    // 0 in L
    for ( int i = 0 ; i <= n ; ++ i ) {
        if ( cnt[ 0 ][ 0 ] > i ) { continue ; }
        if ( cnt[ 0 ][ 1 ] > n - i ) { continue ; }
        if ( cnt[ 1 ][ 1 ] > i ) { continue ; }
        if ( cnt[ 1 ][ 0 ] > n - i ) { continue ; }
        
        long long aux1 = comb ( n - cnt[ 0 ][ 0 ] - cnt[ 0 ][ 1 ] , i - cnt[ 0 ][ 0 ] ) ;
        long long aux2 = comb ( n - cnt[ 1 ][ 0 ] - cnt[ 1 ][ 1 ] , i - cnt[ 1 ][ 1 ] ) ;
        ans = ( ans + aux1 * aux2 ) % MOD ;
        
        if ( i > 0 && i < n ) {
            if ( eq == false ) {
                if ( i >= hh ) {
                    aux1 = comb ( emp , i - hh ) ;
                    ans = ( ans - aux1 + MOD ) % MOD ;
                }
            }
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
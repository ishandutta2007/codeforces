#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007
#define MOD 1000000007

int n ;
string a ;

int decode ( char c ) {
    if ( 'a' <= c && c <= 'z' ) { return ( c - 'a' ) ; }
    else { return 26 + ( c - 'A' ) ; }
}


long long fac[ MAXN ] ;
long long inv[ MAXN ] ;

long long dp[ MAXN ] ;
int cnt[ 62 ] ;
long long ans[ 62 ][ 62 ] ;

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

void add ( int x ) {
    if ( x == 0 ) { return ; }
    for ( int i = n - x ; i >= 0 ; -- i ) {
        dp[ i + x ] = ( dp[ i + x ] + dp[ i ] ) ;
        while ( dp[ i + x ] >= MOD ) {
            dp[ i + x ] -= MOD ;
        }
    }
}

void rem ( int x ) {
    if ( x == 0 ) { return ; }
    for ( int i = 0 ; i <= n - x ; ++ i ) {
        dp[ i + x ] = ( dp[ i + x ] - dp[ i ] + MOD ) ;
        while ( dp[ i + x ] >= MOD ) {
            dp[ i + x ] -= MOD ; 
        }
    }
}

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
    dp[ 0 ] = 1 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        ++ cnt[ decode ( a[ i ] ) ] ;
    }
    for ( int i = 0 ; i < 52 ; ++ i ) {
        add ( cnt[ i ] ) ;
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
    for ( int i = 0 ; i < 52 ; ++ i ) {
        rem ( cnt[ i ] ) ;
        for ( int j = i ; j < 52 ; ++ j ) {
            if ( j != i ) {
                rem ( cnt[ j ] ) ;
            }
            ans[ i ][ j ] = dp[ n / 2 ] ;
            if ( j != i ) {
                add ( cnt[ j ] ) ;
            }
        }
        add ( cnt[ i ] ) ;
    }
    long long aux = ( fac[ n / 2 ] * fac[ n / 2 ] ) % MOD ;
    for ( int i = 0 ; i < 52 ; ++ i ) {
        aux = ( aux * inv[ cnt[ i ] ] ) % MOD ;
    }
    int q ;
    cin >> q ;
    while ( q -- ) {
        int x , y ;
        cin >> x >> y ;
        x = decode ( a[ x - 1 ] ) ;
        y = decode ( a[ y - 1 ] ) ;
        if ( x > y ) { swap ( x , y ) ; }
        cout << ( aux * ans[ x ][ y ] * 2 ) % MOD << "\n" ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
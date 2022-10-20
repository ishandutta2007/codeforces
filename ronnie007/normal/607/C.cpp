#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007
#define MOD 1000000007


int n ;
string a , b ;

long long base = 7 ;
long long pw[ MAXN ] ;

long long fw[ MAXN ] ;
long long bw[ MAXN ] ;

int f ( char c ) {
    if ( c == 'N' ) { return 0 ; }
    if ( c == 'S' ) { return 1 ; }
    if ( c == 'W' ) { return 2 ; }
    return 3 ;
}

void input ( ) {
    cin >> n >> a >> b ;
    -- n ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( a[ i ] == 'S' ) { a[ i ] = 'N' ; }
        else if ( a[ i ] == 'N' ) { a[ i ] = 'S' ; }
        else if ( a[ i ] == 'E' ) { a[ i ] = 'W' ; }
        else { a[ i ] = 'E' ; }
    }
}

void solve ( ) {
    pw[ 0 ] = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        pw[ i ] = ( pw[ i - 1 ] * base ) % MOD ;
    }
    bw[ n + 1 ] = 0 ;
    for ( int i = n ; i >= 1 ; -- i ) {
        bw[ i ] = ( bw[ i + 1 ] * base + f ( a[ i - 1 ] ) ) % MOD ;
    }
    fw[ 0 ] = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        fw[ i ] = ( fw[ i - 1 ] * base + f ( b[ i - 1 ] ) ) % MOD ;
    }

    for ( int i = n ; i >= 1 ; -- i ) {
        long long aux = ( fw[ i - 1 ] * pw[ n - i + 1 ] ) % MOD ;
        aux = ( fw[ n ] - aux + MOD ) % MOD ;
        if ( aux == bw[ i ] ) {
            cout << "NO\n" ;
            return ;
        }
    }
    cout << "YES\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
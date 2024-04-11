#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007
#define MOD 1000000007

int n ;
int a[ MAXN ] ;
long long pw[ MAXN ] ;

long long sm = 0 ;

int cnt[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        ++ cnt[ a[ i ] ] ;
    }
    pw[ 0 ] = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        pw[ i ] = ( pw[ i - 1 ] * 2 ) % MOD ;
    }
}

void solve ( ) {
    for ( int i = 0 ; i < 20 ; ++ i ) {
        for ( int j = 0 ; j < MAXN ; ++ j ) {
            if ( ( j & (1<<i) ) == 0 && j + (1<<i) < MAXN ) {
                cnt[ j ] += cnt[ j + (1<<i) ] ;
            }
        }
    }
    long long ans = 0 ;
    for ( int i = 1 ; i < MAXN ; ++ i ) {
        int aux = -1 ;
        int h = i ;
        while ( h > 0 ) {
            h &= ( h - 1 ) ;
            aux *= -1 ;
        }
        if ( aux == 1 ) {
            ans += pw[ cnt[ i ] ] - 1 ;
            if ( ans >= MOD ) { ans -= MOD ; }
        }
        else {
            ans = ans + MOD - pw[ cnt[ i ] ] + 1 ;
            if ( ans >= MOD ) { ans -= MOD ; }
        }
    }
    ans = pw[ n ] - 1 + MOD - ans ;
    if ( ans >= MOD ) { ans -= MOD ; }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
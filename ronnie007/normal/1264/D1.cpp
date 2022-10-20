#include<bits/stdc++.h>
using namespace std ;

#define MOD 998244353
#define MAXN 2007

int n ;
string a ;

long long dp[ MAXN ][ MAXN ][ 2 ][ 2 ] ;
long long cnt[ MAXN ][ MAXN ][ 2 ][ 2 ] ;


void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
    a = '#' + a ;
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j < i ; ++ j ) {
            cnt[ i ][ j ][ 0 ][ 0 ] = 1 ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ] != ')' ) {
            cnt[ i ][ i ][ 0 ][ 0 ] = 1 ;
        }
        if ( a[ i ] != '(' ) {
            cnt[ i ][ i ][ 1 ][ 1 ] = 1 ;
        }
    }
    int len = 1 ;
    for ( int len = 1 ; len < n ; ++ len ) {
        for ( int l = 1 ; l + len <= n ; ++ l ) {
            int r = l + len ;
            for ( int t = 0 ; t < 2 ; ++ t ) {
                for ( int z = 0 ; z < 2 ; ++ z ) {
                    if ( a[ l ] == '(' && t != 0 ) { continue ; }
                    if ( a[ l ] == ')' && t != 1 ) { continue ; }
                    if ( a[ r ] == ')' && z != 1 ) { continue ; }
                    if ( a[ r ] == '(' && z != 0 ) { continue ; }
                    if ( t == 1 ) {
                        cnt[ l ][ r ][ t ][ z ] = ( cnt[ l + 1 ][ r ][ 0 ][ z ] + cnt[ l + 1 ][ r ][ 1 ][ z ] ) % MOD ;
                        dp[ l ][ r ][ t ][ z ] = ( dp[ l + 1 ][ r ][ 0 ][ z ] + dp[ l + 1 ][ r ][ 1 ][ z ] ) % MOD ;
                        continue ;
                    }
                    if ( z == 0 ) {
                        cnt[ l ][ r ][ t ][ z ] = ( cnt[ l ][ r - 1 ][ t ][ 0 ] + cnt[ l ][ r - 1 ][ t ][ 1 ] ) % MOD ;
                        dp[ l ][ r ][ t ][ z ] = ( dp[ l ][ r - 1 ][ t ][ 0 ] + dp[ l ][ r - 1 ][ t ][ 1 ] ) % MOD ;
                        continue ;
                    }
                    for ( int hh1 = 0 ; hh1 < 2 ; ++ hh1 ) {
                        for ( int hh2 = 0 ; hh2 < 2 ; ++ hh2 ) {
                            cnt[ l ][ r ][ t ][ z ] = ( cnt[ l ][ r ][ t ][ z ] + cnt[ l + 1 ][ r - 1 ][ hh1 ][ hh2 ] ) % MOD ;
                            long long add = ( dp[ l + 1 ][ r - 1 ][ hh1 ][ hh2 ] + cnt[ l + 1 ][ r - 1 ][ hh1 ][ hh2 ] ) % MOD ;
                            dp[ l ][ r ][ t ][ z ] = ( dp[ l ][ r ][ t ][ z ] + add ) % MOD ;
                        }
                    }
                }
            }
        }
    }
    long long ans = 0 ;
    for ( int i = 0 ; i < 2 ; ++ i ) {
        for ( int j = 0 ; j < 2 ; ++ j ) {
            ans = ( ans + dp[ 1 ][ n ][ i ][ j ] ) % MOD ;
        }
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
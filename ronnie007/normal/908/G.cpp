#include<bits/stdc++.h>
using namespace std ;

#define MAXN 701
#define MOD 1000000007

int n ;
string a ;

long long pw[ MAXN ] ;

long long dp[ MAXN ][ MAXN ][ 2 ] ;


void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    pw[ 0 ] = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        pw[ i ] = ( pw[ i - 1 ] * 10 ) % MOD ;
    }
    long long ans = 0 ;
    for ( int dig = 1 ; dig < 10 ; ++ dig ) {
        for ( int i = 0 ; i <= n ; ++ i ) {
            for ( int j = 0 ; j <= n ; ++ j ) {
                for ( int t = 0 ; t < 2 ; ++ t ) {
                    dp[ i ][ j ][ t ] = 0 ;
                }
            }
        }
        dp[ 0 ][ 0 ][ 1 ] = 1 ;
        for ( int i = 0 ; i < n ; ++ i ) {
            for ( int j = 0 ; j <= i ; ++ j ) {
                for ( int t = 0 ; t < 2 ; ++ t ) {
                    if ( dp[ i ][ j ][ t ] == 0 ) { continue ; }
                    if ( t == 0 ) {
                        dp[ i + 1 ][ j + 1 ][ 0 ] += dp[ i ][ j ][ t ] * dig ;
                        dp[ i + 1 ][ j + 1 ][ 0 ] %= MOD ;
                        dp[ i + 1 ][ j ][ 0 ] += dp[ i ][ j ][ t ] * ( 10 - dig ) ;
                        dp[ i + 1 ][ j ][ 0 ] %= MOD ;
                    }
                    else {
                        int wh = j + ( ( a[ i ] - '0' ) < dig ) ;
                        dp[ i + 1 ][ wh ][ 1 ] += dp[ i ][ j ][ t ] ;
                        dp[ i + 1 ][ wh ][ 1 ] %= MOD ;

                        int cnt1 = min ( dig , a[ i ] - '0' ) ;
                        int cnt2 = ( a[ i ] - '0' ) - cnt1 ;
                        dp[ i + 1 ][ j + 1 ][ 0 ] += dp[ i ][ j ][ t ] * cnt1 ;
                        dp[ i + 1 ][ j + 1 ][ 0 ] %= MOD ;

                        dp[ i + 1 ][ j ][ 0 ] += dp[ i ][ j ][ t ] * cnt2 ;
                        dp[ i + 1 ][ j ][ 0 ] %= MOD ;
                    }
                }
            }
        }
        long long pref = 0 ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            pref = ( pref + ( dp[ n ][ i - 1 ][ 0 ] + dp[ n ][ i - 1 ][ 1 ] ) ) % MOD ;
            ans += pref * pw[ n - i ] ; 
            ans %= MOD ;
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
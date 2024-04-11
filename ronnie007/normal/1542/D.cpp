#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 503
#define MOD 998244353

int n ;
char op[ MAXN ] ;
int a[ MAXN ] ; 

long long dp[ MAXN ][ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> op[ i ] ;
        if ( op[ i ] == '+' ) { cin >> a[ i ] ; }
    }
}

void solve ( ) {
    long long ans = 0 ;
    for ( int wh = 1 ; wh <= n ; ++ wh ) {
        if ( op[ wh ] == '-' ) { continue ; }
        for ( int i = 0 ; i <= n ; ++ i ) {
            for ( int j = 0 ; j <= n ; ++ j ) {
                dp[ i ][ j ] = 0 ;
            }
        }
        dp[ 0 ][ 0 ] = 1 ;
        for ( int i = 0 ; i < n ; ++ i ) {
            for ( int j = 0 ; j <= n ; ++ j ) {
                if ( dp[ i ][ j ] == 0 ) { continue ; }
                if ( op[ i + 1 ] == '+' ) {
                    if ( i + 1 == wh ) {
                        dp[ i + 1 ][ j ] = dp[ i ][ j ] ;
                        continue ;
                    }
                    int add = 0 ;
                    if ( a[ i + 1 ] < a[ wh ] ) { ++ add ; }
                    else if ( a[ i + 1 ] == a[ wh ] && i + 1 > wh ) { ++ add ; }

                    dp[ i + 1 ][ j + add ] += dp[ i ][ j ] ;
                    dp[ i + 1 ][ j + add ] %= MOD ;

                    dp[ i + 1 ][ j ] += dp[ i ][ j ] ;
                    dp[ i + 1 ][ j ] %= MOD ;
                }
                else {
                    dp[ i + 1 ][ j ] += dp[ i ][ j ] ;
                    dp[ i + 1 ][ j ] %= MOD ;

                    if ( i + 1 < wh || ( i + 1 >= wh && j > 0 ) ) {
                        dp[ i + 1 ][ max ( j - 1 , 0 ) ] += dp[ i ][ j ] ;
                        dp[ i + 1 ][ max ( j - 1 , 0 ) ] %= MOD ;
                    }
                }
            }
        }
        long long coef = 0 ;
        for ( int j = 0 ; j <= n ; ++ j ) {
            coef += dp[ n ][ j ] ;
            coef %= MOD ;
        }
        ans += ( coef * a[ wh ] ) % MOD ;
        ans %= MOD ;
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
#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
const int MAXN = 102 ;
const int MAXSUM = 10002 ;

int n , x ;
int a[ MAXN ] ;

ld dp[ MAXN ][ MAXSUM ] ;
ld comb[ MAXN ][ MAXN ] ;

void solve ( ) {
    cin >> n >> x ;
    int sm = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        sm += a[ i ] ;
    }
    dp[ 0 ][ 0 ] = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int t = i - 1 ; t >= 0 ; -- t ) {
            for ( int j = 0 ; j + a[ i ] <= sm ; ++ j ) {
                dp[ t + 1 ][ j + a[ i ] ] += dp[ t ][ j ] ;
            }
        }
    }
    comb[ 0 ][ 0 ] = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j <= i ; ++ j ) {
            comb[ i ][ j ] = comb[ i - 1 ][ j ] ;
            if ( j > 0 ) {
                comb[ i ][ j ] += comb[ i - 1 ][ j - 1 ] ;
            }
        }
    }
    ld ans = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < sm ; ++ j ) {
            ld coef = ( dp[ i ][ j ] / comb[ n ][ i ] ) ;
            ld cand1 = ( sm - j ) / (ld) ( n - i ) ;
            ld cand2 = ( ( (ld) x ) / 2 ) * ( (ld) n / ( n - i ) + 1 ) ;
            ans += coef * min ( cand1 , cand2 ) ;
        }
    }
    cout << fixed << setprecision ( 12 ) << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; // cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}
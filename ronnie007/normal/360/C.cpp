#include<bits/stdc++.h>
using namespace std ;

#define MAXN 2007
#define MOD 1000000007

int n , k ;
string a ;

int en[ MAXN ][ MAXN ] ;

long long dp[ MAXN ][ MAXN ][ 3 ] ;
long long suff[ MAXN ] ;

void input ( ) {
    cin >> n >> k ;
    cin >> a ;
}

void solve ( ) {
    dp[ n ][ 0 ][ 0 ] = 1 ;
    suff[ 0 ] = 1 ;
    for ( int i = n - 1 ; i >= 0 ; -- i ) {
        for ( int j = 0 ; j <= k ; ++ j ) {
            long long sm = ( dp[ i + 1 ][ j ][ 0 ] + dp[ i + 1 ][ j ][ 1 ] + dp[ i + 1 ][ j ][ 2 ] ) % MOD ;
            if ( a[ i ] != 'a' ) {
                dp[ i ][ j ][ 0 ] = ( sm * ( a[ i ] - 'a' ) ) % MOD ;
            }
            dp[ i ][ j ][ 1 ] = suff[ j ] ;
            suff[ j ] = ( suff[ j ] + dp[ i ][ j ][ 0 ] ) % MOD ;
            
            int lst = i ;
            for ( int t = i + 1 ; t < n ; ++ t ) {
                int coef = ( t - i ) * ( n - t ) ;
                if ( coef > j ) { break ; }
                dp[ i ][ j ][ 1 ] += dp[ t ][ j - coef ][ 2 ] ;
                dp[ i ][ j ][ 1 ] %= MOD ;
                lst = t ;
            }
            for ( int t = n - 1 ; t > i ; -- t ) {
                int coef = ( t - i ) * ( n - t ) ;
                if ( coef > j ) { break ; }
                if ( t <= lst ) { break ; }
                dp[ i ][ j ][ 1 ] += dp[ t ][ j - coef ][ 2 ] ;
                dp[ i ][ j ][ 1 ] %= MOD ;                
            }
            if ( j >= ( n - i ) && a[ i ] != 'z' ) {
                sm = ( dp[ i + 1 ][ j - ( n - i ) ][ 0 ] + dp[ i + 1 ][ j - ( n - i ) ][ 1 ] + dp[ i + 1 ][ j - ( n - i ) ][ 2 ] ) % MOD ;
                dp[ i ][ j ][ 2 ] = ( sm * ( 'z' - a[ i ] ) ) % MOD ;
            }
        }
    }
    cout << ( dp[ 0 ][ k ][ 0 ] + dp[ 0 ][ k ][ 1 ] + dp[ 0 ][ k ][ 2 ] ) % MOD << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
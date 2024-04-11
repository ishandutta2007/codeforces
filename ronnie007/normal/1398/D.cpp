#include<bits/stdc++.h>
using namespace std ;

#define MAXN 207

int n[ 3 ] ;
int a[ 3 ][ MAXN ] ;

long long dp[ MAXN ][ MAXN ][ MAXN ] ;

void input ( ) {
    for ( int i = 0 ; i < 3 ; ++ i ) {
        cin >> n[ i ] ;
    }
    for ( int i = 0 ; i < 3 ; ++ i ) {
        for ( int j = 0 ; j < n[ i ] ; ++ j ) {
            cin >> a[ i ][ j ] ;
        }
        sort ( a[ i ] , a[ i ] + n[ i ] , greater < int > ( ) ) ;
    }
}

void solve ( ) {
    long long ans = 0 ;
    for ( int i = 0 ; i <= n[ 0 ] ; ++ i ) {
        for ( int j = 0 ; j <= n[ 1 ] ; ++ j ) {
            for ( int t = 0 ; t <= n[ 2 ] ; ++ t ) {
                ans = max ( ans , dp[ i ][ j ][ t ] ) ;
                if ( i < n[ 0 ] && j < n[ 1 ] ) {
                    dp[ i + 1 ][ j + 1 ][ t ] = max ( dp[ i + 1 ][ j + 1 ][ t ] , dp[ i ][ j ][ t ] + a[ 0 ][ i ] * a[ 1 ][ j ] ) ;
                }
                if ( i < n[ 0 ] && t < n[ 2 ] ) {
                    dp[ i + 1 ][ j ][ t + 1 ] = max ( dp[ i + 1 ][ j ][ t + 1 ] , dp[ i ][ j ][ t ] + a[ 0 ][ i ] * a[ 2 ][ t ] ) ;
                }
                if ( j < n[ 1 ] && t < n[ 2 ] ) {
                    dp[ i ][ j + 1 ][ t + 1 ] = max ( dp[ i ][ j + 1 ][ t + 1 ] , dp[ i ][ j ][ t ] + a[ 1 ][ j ] * a[ 2 ][ t ] ) ;
                }                
            }
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
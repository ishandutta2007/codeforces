#include<bits/stdc++.h>
using namespace std ;

#define MAXN 3007

int n ;
int a[ MAXN ] ;
int srt[ MAXN ] ;

long long dp[ MAXN ][ MAXN ] ;
long long mn[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        a[ i ] -= i ;
        srt[ i ] = a[ i ] ;
    }
    sort ( srt + 1 , srt + n + 1 ) ;
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            dp[ i ][ j ] = mn[ j ] + abs ( a[ i ] - srt[ j ] ) ;
            if ( j == 1 ) { mn[ j ] = dp[ i ][ j ] ; }
            else { mn[ j ] = min ( mn[ j - 1 ] , dp[ i ][ j ] ) ; }
        }
    }
    long long ans = dp[ n ][ 1 ] ;
    for ( int j = 2 ; j <= n ; ++ j ) {
        ans = min ( ans , dp[ n ][ j ] ) ;
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
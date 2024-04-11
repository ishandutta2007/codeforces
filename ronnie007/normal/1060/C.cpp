#include<bits/stdc++.h>
using namespace std ;

#define MAXN 2007

int n , m ;
long long a[ MAXN ] ;
long long b[ MAXN ] ;

long long sr ;
long long mn[ MAXN ] ;

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        cin >> b[ i ] ;
    }
    cin >> sr ;
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        mn[ i ] = -1 ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        long long sm = 0 ;
        for ( int j = i ; j <= n ; ++ j ) {
            sm += a[ j ] ;
            int len = j - i + 1 ;
            if ( mn[ len ] < 0 || mn[ len ] > sm ) {
                mn[ len ] = sm ;
            }
        }
    }
    int ans = 0 ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int id = n ;
        long long sm = 0 ;
        for ( int j = i ; j <= m ; ++ j ) {
            sm += b[ j ] ;
            while ( id > 0 && mn[ id ] * sm > sr ) { -- id ; }
            ans = max ( ans , id * ( j - i + 1 ) ) ;
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
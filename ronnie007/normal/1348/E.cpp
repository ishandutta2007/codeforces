#include<bits/stdc++.h>
using namespace std ;

#define MAXN 507

int n , k ;
long long a[ MAXN ] ;
long long b[ MAXN ] ;

bool dp[ 2 ][ MAXN ] ;

long long ans = 0 ;

void input ( ) {
    cin >> n >> k ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] >> b[ i ] ;
    }
}

void solve ( ) {
    int prv , nxt ;
    prv = 0 ; nxt = 1 ;
    dp[ prv ][ 0 ] = true ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        ans += a[ i ] + b[ i ] ;
        for ( int j = 0 ; j < k ; ++ j ) {
            dp[ nxt ][ j ] = false ;
        }
        for ( int j = 0 ; j < k ; ++ j ) {
            if ( dp[ prv ][ j ] == false ) { continue ; }
            for ( int t = 0 ; t <= min ( a[ i ] , 1LL * k ) ; ++ t ) {
                if ( b[ i ] < k - t ) { continue ; }
                dp[ nxt ][ ( j + ( a[ i ] - t ) ) % k ] = true ;
            }
            dp[ nxt ][ ( j + a[ i ] ) % k ] = true ;
        }
        prv ^= 1 ; nxt ^= 1 ;
    }
    for ( int i = 0 ; i < k ; ++ i ) {
        if ( dp[ prv ][ i ] == true ) { ans -= i ; break ; }
    }
    cout << ( ans / k ) << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
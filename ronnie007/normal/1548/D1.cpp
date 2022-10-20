#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int n ;
int cnt[ 2 ][ 2 ] ;


void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int x , y ; cin >> x >> y ;
        x /= 2 ; x %= 2 ;
        y /= 2 ; y %= 2 ;
        ++ cnt[ x ][ y ] ;
    }
}

void solve ( ) {
    long long ans = 0 ;
    for ( int i = 0 ; i < 4 ; ++ i ) {
        for ( int j = i ; j < 4 ; ++ j ) {
            for ( int t = j ; t < 4 ; ++ t ) {
                int px , py , qx , qy ;
                px = ( ( j / 2 ) - ( i / 2 ) + 2 ) % 2 ;
                py = ( ( j % 2 ) - ( i % 2 ) + 2 ) % 2 ;
                qx = ( ( t / 2 ) - ( i / 2 ) + 2 ) % 2 ;
                qy = ( ( t % 2 ) - ( i % 2 ) + 2 ) % 2 ;

                int aux = __gcd ( px , py ) + __gcd ( qx , qy ) ;
                px = ( px - qx + 2 ) % 2 ;
                py = ( py - qy + 2 ) % 2 ;
                aux = ( aux + __gcd ( px , py ) ) % 2 ;

                if ( aux == 0 ) {
                    if ( i == t ) {
                        ans += 1LL * cnt[ ( i / 2 ) ][ ( i % 2 ) ] * ( cnt[ ( j / 2 ) ][ ( j % 2 ) ] - 1 ) * ( cnt[ ( t / 2 ) ][ ( t % 2 ) ] - 2 ) / 6 ;
                    }
                    else if ( i == j ) {
                        ans += 1LL * cnt[ ( i / 2 ) ][ ( i % 2 ) ] * ( cnt[ ( j / 2 ) ][ ( j % 2 ) ] - 1 ) * cnt[ ( t / 2 ) ][ ( t % 2 ) ] / 2 ;
                    }
                    else if ( j == t ) {
                        ans += 1LL * cnt[ ( i / 2 ) ][ ( i % 2 ) ] * cnt[ ( j / 2 ) ][ ( j % 2 ) ] * ( cnt[ ( t / 2 ) ][ ( t % 2 ) ] - 1 ) / 2 ;
                    }
                    else {
                        ans += 1LL * cnt[ ( i / 2 ) ][ ( i % 2 ) ] * cnt[ ( j / 2 ) ][ ( j % 2 ) ] * cnt[ ( t / 2 ) ][ ( t % 2 ) ] ;
                    }
                }
            }
        }
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
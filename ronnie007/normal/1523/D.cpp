#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 200007

int n , m , p ;
string a[ MAXN ] ;

int dp[ MAXN ] ;
int val[ MAXN ] ;

void input ( ) {
    cin >> n >> m >> p ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    int ans = 0 , pos = 1 ;
    for ( int tm = 0 ; tm < 45 ; ++ tm ) {
        int wh = rng ( ) % n + 1 ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            val[ i ] = 0 ;
        }
        int coef = 0 ;
        int len = 0 ;
        for ( int j = 0 ; j < m ; ++ j ) {
            if ( a[ wh ][ j ] == '1' ) {
                ++ len ;
                for ( int i = 1 ; i <= n ; ++ i ) {
                    val[ i ] *= 2 ;
                    val[ i ] += ( a[ i ][ j ] - '0' ) ;
                }
            }
        }
        for ( int i = 0 ; i < ( 1 << p ) ; ++ i ) {
            dp[ i ] = 0 ;
        }
        for ( int i = 1 ; i <= n ; ++ i ) {
            ++ dp[ val[ i ] ] ;
        }

        for ( int j = 0 ; j < len ; ++ j ) {
            for ( int i = 0 ; i < ( 1 << len ) ; ++ i ) { 
                if ( ( i & ( 1 << j ) ) == 0 ) {
                    dp[ i ] += dp[ i + ( 1 << j ) ] ;
                }
            }
        }
        for ( int i = 0 ; i < ( 1 << len ) ; ++ i ) {
            if ( dp[ i ] >= ( n + 1 ) / 2 ) {
                if ( __builtin_popcount ( i ) > __builtin_popcount ( ans ) ) {
                    ans = i , pos = wh ;
                }
            }
        }
    }
    string ret ;
    for ( int i = m - 1 ; i >= 0 ; -- i ) {
        if ( a[ pos ][ i ] == '0' ) { ret += '0' ; }
        else {
            if ( ( ans % 2 ) == 1 ) { ret += '1' ; }
            else { ret += '0' ; }
            ans /= 2 ;
        }
    }
    reverse ( ret.begin ( ) , ret.end ( ) ) ;
    cout << ret << "\n" ;
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
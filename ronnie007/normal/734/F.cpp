#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
long long a[ MAXN ] ;
long long b[ MAXN ] ;

int c[ MAXN ] ;
long long sm = 0 ;

int h[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> b[ i ] ;
        c[ i ] = a[ i ] + b[ i ] ;
        sm += c[ i ] ;
    }
}

void solve ( ) {
    if ( ( sm % ( 2 * n ) ) != 0 ) {
        cout << "-1\n" ;
        return ;
    }
    sm /= ( 2 * n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        h[ i ] = ( c[ i ] - sm ) ;
        if ( ( h[ i ] % n ) != 0 ) {
            cout << "-1\n" ;
            return ;
        }
        h[ i ] /= n ;
        if ( h[ i ] < 0 ) {
            cout << "-1\n" ;
            return ;
        }
    }
    for ( int i = 30 ; i >= 0 ; -- i ) {
        int cnt = 0 ;
        for ( int j = 1 ; j <= n ; ++ j ) {
            if ( ( h[ j ] & (1<<i) ) > 0 ) { ++ cnt ; }
        }
        for ( int j = 1 ; j <= n ; ++ j ) {
            if ( ( h[ j ] & (1<<i) ) > 0 ) {
                a[ j ] -= 1LL * cnt * (1<<i) ;
                b[ j ] -= 1LL * n * (1<<i) ;
            }
            else {
                b[ j ] -= 1LL * cnt * (1<<i) ;
            }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ] != 0 || b[ i ] != 0 ) {
            cout << "-1\n" ;
            return ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << h[ i ] << " " ;
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
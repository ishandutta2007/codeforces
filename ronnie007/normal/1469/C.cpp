#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n , k ;
long long a[ MAXN ] ;

long long lo[ MAXN ] ;
long long hi[ MAXN ] ;

void input ( ) {
    cin >> n >> k ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    lo[ 1 ] = hi[ 1 ] = a[ 1 ] ;
    for ( int i = 1 ; i < n ; ++ i ) {
        if ( lo[ i ] > hi[ i ] ) {
            cout << "NO\n" ;
            return ;
        }
        lo[ i + 1 ] = lo[ i ] - ( k - 1 ) ;
        hi[ i + 1 ] = hi[ i ] + ( k - 1 ) ;
        if ( lo[ i + 1 ] < a[ i + 1 ] ) {
            lo[ i + 1 ] = a[ i + 1 ] ;
        }
        if ( hi[ i + 1 ] > a[ i + 1 ] + ( k - 1 ) ) {
            hi[ i + 1 ] = a[ i + 1 ] + ( k - 1 ) ;
        }
        if ( lo[ i + 1 ] > hi[ i + 1 ] ) {
            cout << "NO\n" ;
            return ;
        }
    }
    if ( lo[ n ] > a[ n ] ) {
        cout << "NO\n" ;
        return ;
    }
    cout << "YES\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
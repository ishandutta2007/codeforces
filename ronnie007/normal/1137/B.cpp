#include<bits/stdc++.h>
using namespace std ;

#define MAXN 500007

string a , b ;

int tot[ 2 ] ;
int need[ 2 ] ;
int PI[ MAXN ] ;
string ans ;

void fill ( ) {
    while ( tot[ 0 ] -- ) {
        ans += '0' ;
    }
    while ( tot[ 1 ] -- ) {
        ans += '1' ;
    }
}

void input ( ) {
    cin >> a >> b ;
}

void solve ( ) {
    if ( a.size ( ) < b.size ( ) ) {
        cout << a << "\n" ;
        return ;
    }
    int n = b.size ( ) ;
    int sr = a.size ( ) ;
    for ( int i = 0 ; i < sr ; ++ i ) {
        ++ tot[ ( a[ i ] - '0' ) ] ;
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        ++ need[ ( b[ i ] - '0' ) ] ;
    }
    PI[ 0 ] = PI[ 1 ] = 0 ;
    int l = 0 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        while ( l > 0 && b[ l ] != b[ i - 1 ] ) {
            l = PI[ l ] ;
        }
        l += ( b[ l ] == b[ i - 1 ] ) ;
        PI[ i ] = l ;
    }
    if ( need[ 0 ] > tot[ 0 ] || need[ 1 ] > tot[ 1 ] ) {
        fill ( ) ;
        cout << ans << "\n" ;
        return ;
    }
    tot[ 0 ] -= need[ 0 ] ; tot[ 1 ] -= need[ 1 ] ;    
    ans += b ;
    int len = b.size ( ) ;
    need[ 0 ] = need[ 1 ] = 0 ;
    for ( int i = 0 ; i < n - PI[ n ] ; ++ i ) {
        ++ need[ ( b[ PI[ n ] + i ] - '0' ) ] ;
    }
    while ( len + ( n - PI[ n ] ) <= sr && need[ 0 ] <= tot[ 0 ] && need[ 1 ] <= tot[ 1 ] ) {
        tot[ 0 ] -= need[ 0 ] ; tot[ 1 ] -= need[ 1 ] ;
        for ( int i = 0 ; i < n - PI[ n ] ; ++ i ) {
            ans += b[ PI[ n ] + i ] ;
            ++ len ;
        }
    }
    fill ( ) ;
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
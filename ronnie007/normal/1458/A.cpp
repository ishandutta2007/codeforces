#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n , m ;
long long a[ MAXN ] ;

long long f ( long long x , long long y ) {
    if ( x < y ) { swap ( x , y ) ; }
    if ( y == 0 ) { return x ; }
    return f ( y , ( x % y ) ) ;
}

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
    long long aux = 0 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        aux = f ( a[ i ] - a[ i - 1 ] , aux ) ;
    }
    for ( int j = 1 ; j <= m ; ++ j ) {
        long long add ;
        cin >> add ;
        cout << f ( add + a[ 1 ] , aux ) << " " ;
    }
    cout << "\n" ;
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
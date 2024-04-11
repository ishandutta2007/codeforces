#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
long long k ;
long long a[ MAXN ] ;


void proc ( ) {
    long long mx = a[ 1 ] ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        mx = max ( mx , a[ i ] ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        a[ i ] = mx - a[ i ] ;
    }
}

void input ( ) {
    cin >> n >> k ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    -- k ;
    proc ( ) ;

    k %= 2 ;
    if ( k == 1 ) {
        proc ( ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << a[ i ] << " " ;
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
#include<bits/stdc++.h>
using namespace std ;

#define MAXN 50007

int n ;
int a[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    if ( a[ n ] < a[ 1 ] + a[ 2 ] ) {
        cout << "-1\n" ;
        return ;
    }
    cout << "1 2 " << n << "\n" ;
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
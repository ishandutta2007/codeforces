#include<bits/stdc++.h>
using namespace std ;

#define MAXN 107

int n ;
int a[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    int mx = 0 ;
    int sm = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        mx = max ( mx , a[ i ] ) ;
        sm += a[ i ] ;
    }
    if ( 2 * mx > sm ) {
        cout << "T\n" ;
    }
    else {
        if ( ( sm % 2 ) == 1 ) {
            cout << "T\n" ;
        }
        else {
            cout << "HL\n" ;
        }
    }
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
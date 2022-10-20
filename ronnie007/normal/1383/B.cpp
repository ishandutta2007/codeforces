#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    int aux = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        aux ^= a[ i ] ;
    }
    if ( aux == 0 ) {
        cout << "DRAW\n" ;
        return ;
    }
    for ( int bit = 30 ; bit >= 0 ; -- bit ) {
        if ( (aux&(1<<bit)) == 0 ) { continue ; }
        int cnt = 0 ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            if ( (a[ i ]&(1<<bit)) > 0 ) { ++ cnt ; }
        }
        int sm = ( cnt / 2 ) ;
        int lg = cnt - sm ;
        if ( ( lg % 2 ) == 1 ) {
            cout << "WIN\n" ;
            return ;
        }
        else {
            if ( ( ( n - cnt ) % 2 ) == 1 ) {
                cout << "WIN\n" ;
                return ;
            }
            else {
                cout << "LOSE\n" ;
                return ;
            }
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
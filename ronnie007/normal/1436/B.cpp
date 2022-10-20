#include<bits/stdc++.h>
using namespace std ;

int n ;

bool f ( int x ) {
    int i ;
    if ( x <= 1 ) { return false ; }
    for ( int i = 2 ; i * i <= x ; ++ i ) {
        if ( ( x % i ) == 0 ) {
            return false ;
        }
    }
    return true ;
}

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    for ( int i = n ; i <= 300 ; ++ i ) {
        if ( f ( i ) == true && f ( i - n + 1 ) == false ) {
            for ( int j = 1 ; j <= n ; ++ j ) {
                for ( int t = 1 ; t <= n ; ++ t ) {
                    if ( j != t ) { cout << "1 " ; }
                    else { cout << i - n + 1 << " " ; }
                }
                cout << "\n" ;
            }
            return ;
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
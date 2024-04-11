#include<bits/stdc++.h>
using namespace std ;

int n , m ;


void input ( ) {
    cin >> n >> m ;
}

void solve ( ) {
    int ans = 0 ;
    int aux = 1 ;
    while ( aux < n ) {
        aux *= m , ++ ans ;
    }
    cout << ans << "\n" ;
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = i + 1 ; j < n ; ++ j ) {
            int act = 0 ;
            int x = i , y = j ;
            while ( x != y ) {
                ++ act ;
                x /= m , y /= m ;
            }
            cout << act << " " ;
        }
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
#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    int ans = 0 ;
    int lst = 1 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        ++ ans ;
        bool fl = false ;
        int aux = lst - 1 ;
        int nw = 1 ;
        for ( int j = i + 1 ; j <= n ; ++ j ) {
            if ( a[ j - 1 ] > a[ j ] ) {
                -- aux ;
                if ( aux < 0 ) {
                    fl = true ;
                    i = j - 1 ;
                    lst = nw ;
                    break ;
                }
            }
            ++ nw ;
        }
        if ( fl == false ) { break ; }
    }
    cout << ans << "\n" ;
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
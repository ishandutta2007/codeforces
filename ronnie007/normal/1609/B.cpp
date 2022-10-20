#include<bits/stdc++.h>
using namespace std ;

int n , m ;
string a ;
int ans ;

void add ( int pos , int coef ) {
    if ( a[ pos ] == 'a' && a[ pos + 1 ] == 'b' && a[ pos + 2 ] == 'c' ) {
        ans += coef ;
    }
}

void input ( ) {
    cin >> n >> m ;
    cin >> a ;
}

void solve ( ) {
    for ( int i = 0 ; i + 2 < n ; ++ i ) {
        add ( i , 1 ) ;
    }
    while ( m -- ) {
        int wh ;
        char c ;
        cin >> wh >> c ;
        -- wh ;
        for ( int j = wh - 2 ; j <= wh ; ++ j ) {
            if ( j >= 0 && j + 2 < n ) {
                add ( j , -1 ) ;
            }
        }
        a[ wh ] = c ;
        for ( int j = wh - 2 ; j <= wh ; ++ j ) {
            if ( j >= 0 && j + 2 < n ) {
                add ( j , 1 ) ;
            }
        }
        cout << ans << "\n" ;
    }
}

int main ( ) {
    //freopen ( "dictionary.in" , "r" , stdin ) ;
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
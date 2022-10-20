#include<bits/stdc++.h>
using namespace std ;

int n ;
vector < int > v[ 2 ] ;

void input ( ) {
    cin >> n ;
    v[ 0 ].clear ( ) , v[ 1 ].clear ( ) ;
    for ( int i = 1 , x ; i <= n ; ++ i ) {
        cin >> x ;
        v[ ( x % 2 ) ].push_back ( x ) ;
    }
}

void solve ( ) {
    for ( int id = 0 ; id < 2 ; ++ id ) {
        int sz = v[ id ].size ( ) ;
        for ( int i = 0 ; i < sz - 1 ; ++ i ) {
            if ( v[ id ][ i ] > v[ id ][ i + 1 ] ) {
                cout << "No\n" ;
                return ;
            }
        }
    }
    cout << "Yes\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    ///scanf ( "%d" , &t ) ;
    /// t = 1 ;
    /// t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
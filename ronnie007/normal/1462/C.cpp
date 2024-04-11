#include<bits/stdc++.h>
using namespace std ;

int x ;
vector < int > v ;

void input ( ) {
    cin >> x ;
}

void solve ( ) {
    if ( x > 45 ) { cout << "-1\n" ; return ; }
    for ( int digs = 1 ; digs <= 9 ; ++ digs ) {
        int sr = 0 ;
        for ( int i = 0 ; i < digs ; ++ i ) { sr += 9 - i ; }
        if ( sr < x ) { continue ; }
        v.clear ( ) ;
        for ( int i = digs - 1 ; i >= 0 ; -- i ) {
            v.push_back ( 9 - i ) ;
        }
        while ( sr > x ) {
            -- sr ;
            int lst = 0 ;
            for ( int i = 0 ; i < digs ; ++ i ) {
                if ( v[ i ] > lst + 1 ) {
                    -- v[ i ] ;
                    break ;
                }
                else { lst = v[ i ] ; }
            }
        }
        for ( int i = 0 ; i < digs ; ++ i ) {
            cout << v[ i ] ;
        }
        cout << "\n" ;
        return ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
#include<bits/stdc++.h>
using namespace std ;

int n ;

int ask ( int l , int r , int pos ) {
    cout << "? " << r - l + 1 << " " << "1\n" ;
    fflush ( stdout ) ;
    for ( int j = l ; j <= r ; ++ j ) {
        cout << j << " " ;
    }
    cout << "\n" ;
    fflush ( stdout ) ;
    cout << pos << "\n" ;
    fflush ( stdout ) ;
    int ret ; cin >> ret ;
    return ret ;
}

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    for ( int i = 2 ; i <= n ; ++ i ) {
        int ret = ask ( 1 , i - 1 , i ) ;
        if ( ret == 0 ) { continue ; }
        int l , r , mid ;
        l = 1 ;
        r = i - 1 ;
        while ( r > l ) {
            mid = ( l + r ) / 2 ;
            if ( ask ( 1 , mid , i ) != 0 ) { r = mid ; }
            else { l = mid + 1 ; }
        }
        vector < int > ans ;
        for ( int j = 1 ; j < i ; ++ j ) {
            if ( j != l ) { ans.push_back ( j ) ; }
        }
        for ( int j = i + 1 ; j <= n ; ++ j ) {
            if ( ask ( j , j , i ) == 0 ) {
                ans.push_back ( j ) ;
            }
        }
        cout << "! " << ans.size ( ) << " " ;
        for ( auto x : ans ) {
            cout << x << " " ;
        }
        cout << "\n" ;
        fflush ( stdout ) ;
        return ;
    }
}


int main ( ) {
    // ios_base :: sync_with_stdio ( false ) ;
    // cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    cin >> t ;
    // t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}
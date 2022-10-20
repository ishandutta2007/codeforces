#include<bits/stdc++.h>
using namespace std ;

int n ;

int ask ( int l , int r ) {
    cout << "? " << l << " " << r << "\n" ;
    fflush ( stdout ) ;
    int ret ;
    cin >> ret ;
    return ret ;
}

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    int l , r , mid ;
    int sr = ask ( 1 , n ) ;
    if ( sr != n && ask ( sr , n ) == sr ) {
        l = sr + 1 ;
        r = n ;
        while ( l < r ) {
            mid = ( l + r ) / 2 ;
            int ret = ask ( 1 , mid ) ;
            if ( ret == sr ) { r = mid ; }
            else { l = mid + 1 ; }
        }
        cout << "! " << l << "\n" ;
        fflush ( stdout ) ;
        return ;
    }
    l = 1 ;
    r = sr - 1 ;
    if ( sr == 2 ) {
        cout << "! 1\n" ;
        fflush ( stdout ) ;
        return ;
    }
    while ( l < r ) {
        mid = ( l + r ) / 2 ;
        int ret = ask ( mid , n ) ;
        if ( ret == sr ) { l = mid + 1 ; }
        else { r = mid ; }
    }
    while ( l < n ) {
        int ret = ask ( l , n ) ;
        if ( ret != sr ) { break ; }
        ++ l ;
    }
    cout << "! " << l - 1 << "\n" ;
    fflush ( stdout ) ;
}


int main ( ) {
    // ios_base :: sync_with_stdio ( false ) ;
    // cin.tie ( NULL ) ;
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
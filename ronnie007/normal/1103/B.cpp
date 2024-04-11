#include<bits/stdc++.h>
using namespace std ;


void input ( ) {

}

void solve ( ) {
    int l , r ;
    l = 1 ; r = 2 ;
    string ret ;
    cout << "? 0 1\n" ;
    fflush ( stdout ) ;
    cin >> ret ;
    if ( ret == "e" ) { exit ( 0 ) ; }
    if ( ret == "x" ) {
        cout << "! 1\n" ;
        fflush ( stdout ) ;
        return ;
    }
    while ( 1 ) {
        cout << "? " << l << " " << r << "\n" ;
        fflush ( stdout ) ;
        cin >> ret ;
        if ( ret == "e" ) { exit ( 0 ) ; }
        if ( ret == "x" ) { break ; }
        l *= 2 ; r *= 2 ;
    }
    int st = l ;
    int mid ;
    while ( r - l > 1 ) {
        mid = ( l + r ) / 2 ;
        cout << "? " << st << " " << mid << "\n" ;
        fflush ( stdout ) ;
        cin >> ret ;
        if ( ret == "e" ) { exit ( 0 ) ; }
        if ( ret == "x" ) { r = mid ; }
        else { l = mid ; }
    }
    cout << "! " << r << "\n" ;
    fflush ( stdout ) ;
}


int main ( ) {
    //ios_base :: sync_with_stdio ( false ) ;
    //cin.tie ( NULL ) ;
    string s ;
    while ( 1 ) {
        cin >> s ;
        if ( s != "start" ) { break ; }
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}